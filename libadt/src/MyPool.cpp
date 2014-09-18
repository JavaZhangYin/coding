#include <iostream>
#include <memory>
#include <new>
#include <typeinfo>
#include <stdexcept>
#include <cassert>
#include <stdlib.h>

using namespace std;

#include "MyMacro.hpp"
#include "MyPool.hpp"
using namespace ADT;

inline unsigned int Log2Ceil(unsigned int i)
{
  unsigned int result = 0;
  while ((1 << result) < i)
    ++result;
  return result;
}

StoragePool::~StoragePool()
{
  //cout << "StoragePool::~StoragePool()..." << endl;
}

SinglyLinkedPool::SinglyLinkedPool(size_t n) :
  nNumberOfBlocks((n + sizeof(Block) - 1U) / sizeof(Block)),
  pPool(new Block[nNumberOfBlocks + 1]),
  sentinel(pPool[nNumberOfBlocks])
{
  //cout << "StoragePool::StoragePool()..." << endl;
  Block& head = pPool[0];
  head.nLength = nNumberOfBlocks;
  head.pNext = 0;

  sentinel.nLength = 0;
  sentinel.pNext = &head;
}

SinglyLinkedPool::~SinglyLinkedPool()
{
  delete[] pPool; 
}

void* SinglyLinkedPool::Acquire(size_t bytes)
{
  unsigned int const nBlocks = (bytes + sizeof(Header) + sizeof(Block) - 1U) / sizeof(Block);
  Block *prevPtr = &sentinel;
  Block *ptr = prevPtr->pNext;

  while(ptr != 0 && ptr->nLength < nBlocks)
    {
      prevPtr = ptr;
      ptr = ptr->pNext;
    } 
  if(ptr == 0)
    throw std::bad_alloc();
  if(ptr->nLength > nBlocks)
    {
      Block& newBlock = ptr[nBlocks];
      newBlock.nLength = ptr->nLength - nBlocks;
      newBlock.pNext = ptr->pNext;
      ptr->nLength = nBlocks;
      ptr->pNext = &newBlock;
    }
  prevPtr->pNext = ptr->pNext;
  return ptr->szUserPart;
}

void SinglyLinkedPool::Release(void* arg)
{
  Block& block = *reinterpret_cast<Block*>(reinterpret_cast<Header*>(arg) -1U);

  if(&block < pPool || &block >= pPool + nNumberOfBlocks)
    throw std::invalid_argument("invalid block!");

  Block* prevPtr = &sentinel;
  Block* ptr = prevPtr->pNext;

  while(ptr != 0 && ptr < &block)
    {
      prevPtr = ptr;
      ptr = ptr->pNext;
    }

  if(ptr != 0 && &block + block.nLength == ptr)
    {
      block.nLength += ptr->nLength;
      block.pNext = ptr->pNext;
    }
  else
    {
      block.pNext = ptr;
    }

  if(prevPtr + prevPtr->nLength == &block)
    {
      prevPtr->nLength += block.nLength;
      prevPtr->pNext = block.pNext;
    }
  else
    {
      prevPtr->pNext = &block;
    }
}

DoublyLinkedPool::DoublyLinkedPool(size_t n) :
  nNumberOfBlocks((n + sizeof(Block) - 1U) / sizeof(Block)),
  pPool(new Block[nNumberOfBlocks + 1]),
  sentinel(pPool[nNumberOfBlocks])
{
  sentinel.status = reserved;
  sentinel.link.pNext = &sentinel;
  sentinel.link.pPrev = &sentinel;

  Block& head = pPool[0];
  head.status = free;
  head.nLength = nNumberOfBlocks;
  
  InsertAfter(sentinel, head);
}

DoublyLinkedPool::~DoublyLinkedPool()
{
  delete[] pPool;
}

void DoublyLinkedPool::Release(void *arg)
{
  Block& block = *reinterpret_cast<Block*>(reinterpret_cast<Header*>(arg) - 1);
  if(&block < pPool || &block >= pPool + nNumberOfBlocks)
    throw std::invalid_argument("invalid block");
  block.status = free;
  InsertAfter(sentinel, block);
}

void* DoublyLinkedPool::Acquire(size_t bytes)
{
  unsigned int const nBlocks = (bytes + sizeof(Header) + sizeof(Block) - 1) / sizeof(Block);
  Block *ptr;
  for(ptr = sentinel.link.pNext; ptr != &sentinel; ptr = ptr->link.pNext)
    {
      for(;;)
	{
	  Block &successor = ptr[ptr->nLength];
	  if(successor.status == reserved)
	    break;
	  Unlink(successor);
	  ptr->nLength += successor.nLength;
	}
      if(ptr->nLength >= nBlocks)
	break;
    }
  assert(ptr != &sentinel);
  if(ptr == &sentinel)
    throw std::bad_alloc();
  if(ptr->nLength > nBlocks)
    {
      Block &newBlock = ptr[nBlocks];
      newBlock.status = free;
      newBlock.nLength=ptr->nLength - nBlocks;
      ptr->nLength = nBlocks;
      InsertAfter(sentinel, newBlock);
    }
  Unlink(*ptr);
  return ptr->szUserPart;
}

void DoublyLinkedPool::Unlink(Block &block)
{
  Block *prev = block.link.pPrev;
  Block *next = block.link.pNext;
  prev->link.pNext = next;
  next->link.pPrev = prev;
}
void DoublyLinkedPool::InsertAfter(Block &sentinel, Block &block)
{
  Block *tail = sentinel.link.pPrev;
  block.link.pPrev = tail;
  block.link.pNext = &sentinel;
  sentinel.link.pPrev = &block;
  tail->link.pNext = &block;

  /////////////////////////////////
//   Block *prev = block.link.pPrev;
//   Block *next = block.link.pNext;

//   block.link.pNext = sentinel.link.pNext;
//   block.link.pPrev = &sentinel;
  
//   sentinel.link.pNext->link.pPrev = &block; 
//   sentinel.link.pNext = &block;
}

BuddyPool::BuddyPool(size_t bytes) :
  m(Log2Ceil(bytes)),
  nNumberOfBlocks((1 << m) / sizeof(Block)),
  pPool(new Block[nNumberOfBlocks + m + 1]),
  pSentinel(pPool + nNumberOfBlocks)
{
  for(unsigned int i = 0; i <= m; i++)
    {
      pSentinel[i].link.pNext = &pSentinel[i];
      pSentinel[i].link.pPrev = &pSentinel[i];
    }
  Block& head = pPool[0];
  head.status = free;
  head.k = m;
  InsertAfter(pSentinel[m], head);
}

BuddyPool::~BuddyPool()
{
  delete[] pPool;
}

void* BuddyPool::Acquire(size_t bytes)
{
  unsigned int kPrime = Log2Ceil(bytes + sizeof(Header));
  unsigned int i = kPrime;
  while(i <= m && pSentinel[i].link.pNext == &pSentinel[i])
    i++;
  if(i > m)
    throw std::bad_alloc();
 
  Block& block = *pSentinel[i].link.pNext;
  Unlink(block);
  while(block.k > kPrime)
    {
      block.k -= 1;
      Block& buddy = Buddy(block);
      buddy.status = free;
      buddy.k = block.k;
      InsertAfter(pSentinel[buddy.k], buddy);
    }
  block.status = reserved;
  return block.szUserPart;
}

void BuddyPool::Release(void *arg)
{
  Block& block = *reinterpret_cast<Block*>(reinterpret_cast<Header*>(arg) - 1);
  if(&block < pPool || &block >= pPool + nNumberOfBlocks)
    throw std::invalid_argument("invalid pointer");
  block.status = free;
  Block *ptr;
  for(ptr = &block; ptr->k < m; ptr->k += 1)
    {
      Block& buddy = Buddy(*ptr);
      if(buddy.status == reserved || buddy.k != ptr->k)
	break;
      Unlink(buddy);
      if(&buddy < ptr)
	ptr = &buddy;
    }
  InsertAfter(pSentinel[ptr->k], *ptr);
}

void BuddyPool::Unlink(Block &block)
{
  Block *prev = block.link.pPrev;
  Block *next = block.link.pNext;
  prev->link.pNext = next;
  next->link.pPrev = prev;
}
void BuddyPool::InsertAfter(Block &sentinel, Block &block)
{
  Block *tail = sentinel.link.pPrev;
  block.link.pPrev = tail;
  block.link.pNext = &sentinel;
  sentinel.link.pPrev = &block;
  tail->link.pNext = &block;

//   Block *prev = block.link.pPrev;
//   Block *next = block.link.pNext;

//   block.link.pNext = sentinel.link.pNext;
//   block.link.pPrev = &sentinel;

//   sentinel.link.pNext->link.pPrev = &block; 
//   sentinel.link.pNext = &block;
}
BuddyPool::Block& BuddyPool::Buddy(Block& block) const
{
  unsigned int k = block.k;
  Block *p = &block;
  int b = (p - pPool);
  Block& _block = *(pPool + (b ^ 1 << (k - Log2Ceil(sizeof(Block)))));
  return _block;
}
//namespace ADT
//{

void* operator new(size_t bytes, StoragePool& p) throw(std::bad_alloc)
{
  //cout << "operator new(size_t bytes, StoragePool& p) ...";
  //  void *v = p.Acquire(bytes + sizeof(Tag));
  Tag* const tag = reinterpret_cast<Tag*>(p.Acquire(bytes + sizeof(Tag)));
  tag->pPool = &p;
  return tag + 1;
}

void* operator new[](size_t bytes, StoragePool& p) throw()
{
  return operator new(bytes, p);
}
  
void* operator new(size_t bytes) throw(std::bad_alloc)
{
  Tag* const tag = reinterpret_cast<Tag*>(malloc(bytes + sizeof(Tag)));
  tag->pPool = 0;
  return tag + 1;
}

void* operator new[](size_t bytes) throw(std::bad_alloc)
{
  return operator new(bytes);
}

void operator delete(void* arg) throw()
{
  Tag* const tag = reinterpret_cast<Tag*>(arg) -1;
  if(tag->pPool)
    tag->pPool->Release(tag);
  else
    free(tag);
}

void operator delete[](void* arg) throw()
{
  operator delete(arg);
}

void operator delete(void* arg, StoragePool& p) throw()
{
  //cout << "operator delete(void* arg, StoragePool& p)...";
  Tag* const tag = reinterpret_cast<Tag*>(arg) -1;
  if(tag->pPool)
    tag->pPool->Release(tag);
  else
    free(tag);
}

void operator delete[](void* arg, StoragePool& p) throw()
{
  operator delete(arg, p);
}
/////////////////////////////////////////////////////////////////
//DEBUG°æ
void* operator new(size_t bytes, StoragePool &p, char *f, int l) throw()
{
  cout << "operator new(size_t bytes, StoragePool& p, char *f, int l) ...";
  cout << "FILE: " << f << " | LINE:" << l << endl;

  Tag* const tag = reinterpret_cast<Tag*>(p.Acquire(bytes + sizeof(Tag)));
  tag->pPool = &p;
  return tag + 1;
}

void* operator new[](size_t bytes, StoragePool &p, char *f, int l) throw()
{
  cout << "operator new[](size_t bytes, StoragePool& p, char *f, int l) ...";
  cout << "FILE: " << f << " | LINE:" << l << endl;
  return operator new(bytes, p, f, l);
}
  
void* operator new(size_t bytes, char *f, int l) throw(std::bad_alloc)
{
  cout << "operator new(size_t bytes, char *f, int l) ...";
  cout << "FILE: " << f << " | LINE:" << l << endl;
  //cout << "2222222222222222222222222222" << endl;
  Tag* const tag = reinterpret_cast<Tag*>(malloc(bytes + sizeof(Tag)));
  tag->pPool = 0;
  return tag + 1;
  //cout << "tag:" << tag << endl;
  //cout << "tag + 1:" << tag + 1 << endl;
  //void *p = tag + 1;
  //cout << "p:" << p << endl;
  //return p;
}
 
void* operator new[](size_t bytes, char *f, int l) throw(std::bad_alloc)
{
  cout << "operator new[](size_t bytes, char *f, int l) ...";
  cout << "FILE: " << f << " | LINE:" << l << endl;
  //cout << "11111111111111111111111111111" << endl;
  //void* p = operator new(bytes, f, l);
  //cout << "p:" << p << endl;
  return operator new(bytes, f, l);
} 

void operator delete(void* arg, char *f, int l) throw()
{
  cout << "operator delete(void* arg, char *f, int l)...";
  cout << "FILE: " << f << " | LINE:" << l << endl;
  //cout << "444444444444444444444444444444444444444" << endl;
  //cout << "arg: = " << arg << endl; 
  Tag* const tag = reinterpret_cast<Tag*>(arg) - 1;
  //cout << "tag:" << tag << endl;
  if(tag->pPool)
    tag->pPool->Release(tag);
  else
    free(tag);
}

void operator delete[](void* arg, char *f, int l) throw()
{
  cout << "operator delete[](void* arg, char *f, int l)...";
  cout << "FILE: " << f << " | LINE:" << l << endl;
  //cout << "33333333333333333333333333333333333333" << endl;
  //cout << "arg: = " << arg << endl;
  operator delete(arg, f, l);
}

void operator delete(void* arg, StoragePool& p, char *f, int l) throw()
{
  cout << "operator delete(void* arg, StoragePool& p, char *f, int l)...";
  cout << "FILE: " << f << " | LINE:" << l << endl;
  Tag* const tag = reinterpret_cast<Tag*>(arg) -1;
  
  if(tag->pPool)
    tag->pPool->Release(tag);
  else
    free(tag);
}

void operator delete[](void* arg, StoragePool& p, char *f, int l)throw()
{
  cout << "operator delete(void* arg, StoragePool& p, char *f, int l)...";
  cout << "FILE: " << f << " | LINE:" << l << endl;
  operator delete(arg, p, f, l);
}

////////////////////
/*
  void* operator new(size_t bytes, StoragePool* p) throw()
  {
  Tag* tag;
  if(p)
  tag = reinterpret_cast<Tag*>(p->Acquire(bytes + sizeof(Tag)));
  else
  tag = reinterpret_cast<Tag*>(malloc(bytes + sizeof(Tag)));

  tag->pPool = p;
  return tag + 1;
  }

  void operator delete(void* arg, void* p) throw()
  {
  Tag* const tag = reinterpret_cast<Tag*>(arg) -1U;
  if(tag->pPool)
  tag->pPool->Release(tag);
  else
  free(tag);
  }
*/
//};
