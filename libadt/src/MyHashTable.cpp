#include <string>
#include <stdexcept>

using namespace std;

#include "MyArray.hpp"
#include "MyLink.hpp"

#include "MyObject.hpp"
#include "MyContainer.hpp"

#include "MyQueue.hpp"

#include "MyHashTable.hpp"

using namespace ADT;
//////////////////////////////////////////////////////////////////////////////////////
HashTable::HashTable(unsigned int _nLength) : 
  nLength(_nLength)
{}

unsigned int HashTable::H(Object const& object) const
{
  return object.Hash() % nLength;
}
/////////////////////////////////////////////////////////////////////////////////////
ChainedHashTable::ChainedHashTable(unsigned int _nLength) :
  HashTable(_nLength),
  array(_nLength)
{}
ChainedHashTable::~ChainedHashTable()
{
  Purge();
}
void ChainedHashTable::Purge()
{
  for(unsigned int i = 0; i < nLength; i++)
    {
      if(IsOwner())
	{
	  DListElement<Object*> const* ptr;
	  for(ptr = array[i].GetHeadNode(); ptr != 0; 
	      ptr = ptr->GetNextNodeRight())
	    delete ptr->GetData();
	}
      array[i].Purge();
    }
  nCount = 0;
}
void ChainedHashTable::Insert(Object& object)
{
  array[H(object)].Append(&object);
  nCount++;
}
void ChainedHashTable::WithDraw(Object& object)
{
  array[H(object)].Extract(&object);
  nCount--;
}
Object& ChainedHashTable::Find(Object const& object) const
{
  DListElement<Object*> const* ptr;

  for(ptr = array[H(object)].GetHeadNode(); ptr != 0; 
      ptr = ptr->GetNextNodeRight())
    {
      if(object == *ptr->GetData())
	return *ptr->GetData();
    }
  return NullObject::GetInstance();
}
void ChainedHashTable::Accept(Visitor& visitor) const
{
  for(unsigned int i = 0; i < array.GetLength() && !visitor.IsDone(); i++)
    {
      DListElement<Object*> const* ptr;
      for(ptr = array[i].GetHeadNode(); ptr != 0; ptr = ptr->GetNextNodeRight())
	visitor.Visit(*ptr->GetData());
    }
}
bool ChainedHashTable::IsMember(Object const& object) const
{
  if(Find(object) != NullObject::GetInstance())
    return true;
  else 
    return false;
}
int ChainedHashTable::CompareTo(Object const& object) const
{
  ChainedHashTable const& hashTable =
    dynamic_cast<ChainedHashTable const&> (object);
  return ::Compare(nCount, hashTable.nCount);
}
////////////////////////////////////////////////////////////////////////////////////
ChainedScatterTable::Entry::Entry() :
  pObject(0),
  nNext(null)
{}
ChainedScatterTable::Entry::~Entry() 
{}

ChainedScatterTable::ChainedScatterTable(unsigned int _nLength) :
  HashTable(_nLength),
  array(_nLength)
{}
ChainedScatterTable::~ChainedScatterTable()
{
  Purge();
}
void ChainedScatterTable::Purge()
{
  for(unsigned int i = 0; i < nLength; i++)
    {
      if(array[i].pObject != 0)
	{
	  if(IsOwner())
	    delete array[i].pObject;
	  array[i] = Entry();
	}
    }

  nCount = 0;
}
void ChainedScatterTable::Insert(Object& object)
{
  if(nCount == nLength)
    throw std::domain_error("scatter table is full");
  unsigned int nProbe = H(object);
  if(array[nProbe].pObject != 0)
    {
      while(array[nProbe].nNext != Entry::null)
	nProbe = array[nProbe].nNext;
      unsigned int const nTail  = nProbe;
      nProbe = (nProbe + 1) % nLength;
      while(array[nProbe].pObject != 0)
	nProbe = (nProbe + 1) % nLength;
      array[nTail].nNext = nProbe;
    }
  array[nProbe].pObject = &object;
  array[nProbe].nNext = Entry::null;
  nCount++;
}
Object& ChainedScatterTable::Find(Object const& object) const
{
  for(unsigned int nProbe = H(object);
      nProbe != Entry::null; nProbe = array[nProbe].nNext)
    {
      if(object == *array[nProbe].pObject)
	return *array[nProbe].pObject;
    }
  return NullObject::GetInstance();
}
void ChainedScatterTable::WithDraw(Object& object)
{
  if(nCount == 0)
    throw std::domain_error("scatter table is empty");
  unsigned int i = H(object);
  while(i != Entry::null && array[i].pObject != &object)
    i = array[i].nNext;
  if(i == Entry::null)
    throw std::invalid_argument("object not found");
  for(;;)
    {
      unsigned int j;
      for(j = array[i].nNext; j != Entry::null; j = array[j].nNext)
	{
	  unsigned int const h = H(*array[j].pObject);
	  bool bContained = false;
	  for(unsigned int k = array[i].nNext;
	      k != array[j].nNext && !bContained;
	      k = array[k].nNext)
	    {
	      if(k == h)
		bContained = true;
	    }
	  if(!bContained)
	    break;			
	}
      if(j == Entry::null)
	break;
      array[i].pObject = array[j].pObject;
      i = j;
    }
  array[i].pObject = 0;
  array[i].nNext = Entry::null;
  for(unsigned int j = (i + nLength - 1U) % nLength;
      j != i; j = (j + nLength - 1U) % nLength)
    {
      if(array[j].nNext == i)
	{
	  array[j].nNext = Entry::null;
	  break;
	}
    }
  nCount--;
}
int ChainedScatterTable::CompareTo(Object const& object) const
{
  ChainedScatterTable const& hashTable =
    dynamic_cast<ChainedScatterTable const&> (object);
  return ::Compare(nCount, hashTable.nCount);
}
void ChainedScatterTable::Accept(Visitor& visitor) const
{
  for(unsigned int i = 0; i < nLength; i++)
    {
      if(array[i].pObject != 0)
	visitor.Visit(*array[i].pObject);
    }
}
bool ChainedScatterTable::IsMember(Object const& object) const
{
  if(Find(object) != NullObject::GetInstance())
    return true;
  else 
    return false;
}
///////////////////////////////////////////////////////////////////////////////////
OpenScatterTable::Entry::Entry() :
  state(empty),
  pObject(0)
{}

OpenScatterTable::Entry::~Entry()
{}

OpenScatterTable::OpenScatterTable(unsigned int _nLength) :
  HashTable(_nLength),
  array(_nLength)
{}

OpenScatterTable::~OpenScatterTable()
{
  Purge();
}

void OpenScatterTable::Purge()
{
  for(unsigned int i = 0; i < nLength; i++)
    {
      array[i].state = Entry::occupied;
      if(array[i].state)
	{
	  if(IsOwner())
	    delete array[i].pObject;
	  array[i] = Entry();
	}
    }
  nCount = 0;
}

unsigned int OpenScatterTable::C(unsigned int i) const
{
  return i;
}

unsigned int OpenScatterTable::FindUnoccupied(Object const& object) const
{
  unsigned int const hash = H(object);
  for(unsigned int i = 0; i <= nCount; i++)
    {
      unsigned int const nProbe = (hash + C(i)) % nLength;
      if(array[nProbe].state != Entry::occupied)
	return nProbe;
    }
  return nLength;
}

void OpenScatterTable::Insert(Object& object)
{
  if(nCount == nLength)
    throw std::domain_error("scatter table is full");
  unsigned int const nOffset = FindUnoccupied(object);
  array[nOffset].state = Entry::occupied;
  array[nOffset].pObject = &object;
  nCount++;
}

unsigned int OpenScatterTable::FindMatch(Object const& object) const
{
  unsigned int const hash = H(object);
  for(unsigned int i = 0; i < nLength; i++)
    {
      unsigned int const nProbe = (hash + C(i)) % nLength;
      if(array[nProbe].state == Entry::empty)
	break;	
      if(array[nProbe].state == Entry::occupied &&
	 object == *array[nProbe].pObject)
	return nProbe;
    }
  return nLength;
}

unsigned int OpenScatterTable::FindInstance(Object const& object) const
{
  return FindMatch(object);
}

Object& OpenScatterTable::Find(Object const& object) const
{
  unsigned int nOffset = FindMatch(object);
  if(nOffset < nLength)
    return *array[nOffset].pObject;
  else 
    return NullObject::GetInstance();
}

void OpenScatterTable::WithDraw(Object& object)
{
  if(nCount == 0)
    throw std::domain_error("scatter table is empty");
  unsigned int i = FindInstance(object);
  if(i == nLength)
    throw std::invalid_argument("object not find");
  for(;;)
    {
      unsigned int j;
      for(j = (i + 1) % nLength;
	  array[j].state == Entry::occupied;
	  j = (j + 1) % nLength)
	{
	  unsigned int const h = H(*array[j].pObject);
	  if((h <= i && i < j) || (i < j && j < h) || (j < h && h <= i))
	    break;
	}
      if(array[j].state == Entry::empty)
	break;
      array[i] = array[j];
      i = j;
    }
  array[i].state = Entry::empty;
  array[i].pObject = 0;
  nCount--;
}
int OpenScatterTable::CompareTo(Object const& object) const
{
  OpenScatterTable const& hashTable =
    dynamic_cast<OpenScatterTable const&> (object);
  return ::Compare(nCount, hashTable.nCount);
}
void OpenScatterTable::Accept(Visitor& visitor) const
{
  for(unsigned int i = 0; i < nLength; i++)
    {
      if(array[i].pObject != 0)
	visitor.Visit(*array[i].pObject);
    }
}
bool OpenScatterTable::IsMember(Object const& object) const
{
  if(Find(object) != NullObject::GetInstance())
    return true;
  else 
    return false;
}
Iterator& OpenScatterTable::NewIterator() const
{
  return *new Iter(*this);
}
Iterator& ChainedScatterTable::NewIterator() const
{
  return *new Iter(*this);
}
Iterator& ChainedHashTable::NewIterator() const
{
  return *new Iter(*this);
}
///////////////////////////////////////////////////////////////////////////////
OpenScatterTable::Iter::Iter(OpenScatterTable const& _openScatterTable):
  openScatterTable(_openScatterTable),
  nOffset(0)
{
  Reset();
}
OpenScatterTable::Iter::~Iter()
{}
void OpenScatterTable::Iter::Reset()
{
  for(nOffset = 0; nOffset < openScatterTable.nLength; nOffset++)
    {	
		
      if(openScatterTable.array[nOffset].pObject != 0)
	break;
    }
}
bool OpenScatterTable::Iter::IsDone() const
{
  return nOffset >= openScatterTable.nLength;
}
Object& OpenScatterTable::Iter::operator *() const
{
  if(nOffset < openScatterTable.nLength)
    {
      if(openScatterTable.array[nOffset].pObject != 0)
	return *(openScatterTable.array[nOffset].pObject);
      else
	return NullObject::GetInstance();
    }
  else
    return NullObject::GetInstance();
}

void OpenScatterTable::Iter::operator ++()
{
  nOffset++;
  while(nOffset < openScatterTable.nLength)
    {	
      if(openScatterTable.array[nOffset].pObject != 0)
	break;
      nOffset++;
    }
}
///////////////////////////////////////////////////////////////////////////////
ChainedScatterTable::Iter::Iter(ChainedScatterTable const& _chainedScatterTable):
  chainedScatterTable(_chainedScatterTable),
  nOffset(0)
{
  Reset();
}
ChainedScatterTable::Iter::~Iter()
{}
void ChainedScatterTable::Iter::Reset()
{
  nOffset = 0;
  while(nOffset < chainedScatterTable.nLength)
    {	
      nOffset++;
      if(chainedScatterTable.array[nOffset].pObject != 0)
	break;
    }
}
bool ChainedScatterTable::Iter::IsDone() const
{
  return nOffset >= chainedScatterTable.nLength;
}
Object& ChainedScatterTable::Iter::operator *() const
{
  if(nOffset < chainedScatterTable.nLength)
    {
      if(chainedScatterTable.array[nOffset].pObject != 0)
	return *(chainedScatterTable.array[nOffset].pObject);
      else
	return NullObject::GetInstance();
    }
  else
    return NullObject::GetInstance();
}

void ChainedScatterTable::Iter::operator ++()
{
  nOffset++;
  while(nOffset < chainedScatterTable.nLength)
    {	
      if(chainedScatterTable.array[nOffset].pObject != 0)
	break;
      nOffset++;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
ChainedHashTable::Iter::Iter(ChainedHashTable const& chainedHashTable):
  array(chainedHashTable.array),
  queue(*new QueueAsLinkedList()),
  nOffset(0)
{
  queue.RescindOwnership();
  Reset();
}
ChainedHashTable::Iter::~Iter()
{
  delete &queue;
}
void ChainedHashTable::Iter::Reset()
{
  queue.Purge();
  unsigned int length = array.GetLength();
  for(nOffset = 0; queue.IsEmpty() && nOffset < length; nOffset++)
    {
      ObjectLinkList& linkList = array[nOffset];
      DListElement<Object*> const* pElement;
      for(pElement = linkList.GetHeadNode(); pElement != NULL; pElement = pElement->GetNextNodeRight())
	{
	  queue.EnQueue(*(pElement->GetData()));
	}
		
    }
}
bool ChainedHashTable::Iter::IsDone() const
{
  return queue.IsEmpty();
}
Object& ChainedHashTable::Iter::operator *() const
{
  if(!queue.IsEmpty())
    return queue.GetHead();
  else
    return NullObject::GetInstance();
}

void ChainedHashTable::Iter::operator ++()
{
  if(!queue.IsEmpty())
    queue.DeQueue();
  if(queue.IsEmpty())
    {
      if(nOffset < array.GetLength())
	{
	  ObjectLinkList& linkList = array[nOffset];
	  DListElement<Object*> const* pElement;
	  for(pElement = linkList.GetHeadNode(); 
	      pElement != NULL; 
	      pElement = pElement->GetNextNodeRight())
	    {
	      queue.EnQueue(*pElement->GetData());
	    }
	  nOffset++;
	}
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
