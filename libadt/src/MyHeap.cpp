#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

#include "MyMacro.hpp"
#include "MyArray.hpp"
#include "MyLink.hpp"
#include "MyObject.hpp"
#include "MyContainer.hpp"
#include "MyStack.hpp"
#include "MyQueue.hpp"
#include "MyTree.hpp"
#include "MyHeap.hpp"

using namespace ADT;

BinaryHeapAsArray::BinaryHeapAsArray(unsigned int nLength) :
  array(nLength, 1)
{}
///////////////////////////////////////////////////////////////////
void BinaryHeapAsArray::Purge()
{
  if(IsOwner()) 
    {
      for(unsigned int i = 1; i <= nCount; i++) 
	delete array[i];
    }
  nCount = 0;
}
///////////////////////////////////////////////////////////////////
BinaryHeapAsArray::~BinaryHeapAsArray()
{
  Purge();
}
///////////////////////////////////////////////////////////////////
int BinaryHeapAsArray::CompareTo(Object const& object) const
{
  return 0;
}
///////////////////////////////////////////////////////////////////
void BinaryHeapAsArray::Accept(Visitor& visitor) const
{
  for(unsigned int i = 0; i < nCount && !visitor.IsDone(); i++)
    {
      visitor.Visit(*(array[i]));
    }
}
///////////////////////////////////////////////////////////////////
void BinaryHeapAsArray::EnQueue(Object& object)
{
  if(nCount == array.GetLength())
    throw std::domain_error("priority queue is full");
  nCount++;
  unsigned int i = nCount;
  while(i > 1 && *array[i / 2] > object)
    {
      array[i] = array[i / 2];
      i /= 2;
    }
  array[i] = &object;
}
///////////////////////////////////////////////////////////////////
Object& BinaryHeapAsArray::FindMin() const
{
  if(nCount == 0)
    throw std::domain_error("priority queue is empty");
  return *array[1];
}
///////////////////////////////////////////////////////////////////
Object& BinaryHeapAsArray::DeQueueMin()
{
  if(nCount == 0)
    throw std::domain_error("priority queue is empty");
  Object& result = *array[1];
  Object& last = *array[nCount];
  nCount--;
  unsigned int i = 1;
  while(2 * i <= nCount)
    {
      unsigned int nChild = 2 * i;
      if(nChild + 1 <= nCount && *array[nChild + 1] < *array[nChild])
	nChild++;
      if(last <= *array[nChild])
	break;
      array[i] = array[nChild];
      i = nChild;
    }
  array[i] = &last;
  return result;
}
///////////////////////////////////////////////////////////////////
bool BinaryHeapAsArray::IsFull() const
{
  return nCount == array.GetLength();
}
///////////////////////////////////////////////////////////////////
Iterator& BinaryHeapAsArray::NewIterator() const
{
  return *(new Pos(*this));
}
///////////////////////////////////////////////////////////////////
BinaryHeapAsArray::Pos::Pos(BinaryHeapAsArray const& _heap, unsigned int _nOffset) :
  heap(_heap),
  nOffset(_nOffset)
{}
///////////////////////////////////////////////////////////////////
BinaryHeapAsArray::Pos::~Pos()
{}
///////////////////////////////////////////////////////////////////
bool BinaryHeapAsArray::Pos::IsDone() const
{
  return nOffset >= heap.nCount;
}
///////////////////////////////////////////////////////////////////
Object& BinaryHeapAsArray::Pos::operator *() const
{
  if(nOffset < heap.nCount)
    return *(heap.array[nOffset]);
  else
    return NullObject::GetInstance();
}
///////////////////////////////////////////////////////////////////
void BinaryHeapAsArray::Pos::operator ++()
{
  if(nOffset < heap.nCount)
    nOffset++;
}
///////////////////////////////////////////////////////////////////
void BinaryHeapAsArray::Pos::Reset()
{
  nOffset = 0;
}
///////////////////////////////////////////////////////////////////
LeftistHeap::LeftistHeap():BinaryTree(),
			   nNullPathLength(0)
{
}
///////////////////////////////////////////////////////////////////
LeftistHeap::LeftistHeap(Object& object):
  nNullPathLength(1)
{
  pObjKey = &object;
  pBinaryTreeLeft = dynamic_cast<BinaryTree*>(new LeftistHeap);
  pBinaryTreeRight = dynamic_cast<BinaryTree*>(new LeftistHeap);
}
///////////////////////////////////////////////////////////////////
void LeftistHeap::Merge(MergeablePriorityQueue& queue)
{
  LeftistHeap& arg = dynamic_cast<LeftistHeap&>(queue);
  if(IsEmpty())
    SwapContents(arg);
  else if(!arg.IsEmpty())
    {
      if(*pObjKey > *arg.pObjKey)
	SwapContents(arg);
      GetRight().Merge(arg);
      if(GetLeft().nNullPathLength < GetRight().nNullPathLength)
	Swap((void*&)pBinaryTreeLeft, (void*&)pBinaryTreeRight);
      nNullPathLength = 1 + Min(GetLeft().nNullPathLength, GetRight().nNullPathLength);
    }
}
///////////////////////////////////////////////////////////////////
void LeftistHeap::EnQueue(Object& object)
{
  LeftistHeap heap(object);
  Merge(heap);
}
///////////////////////////////////////////////////////////////////
Object& LeftistHeap::FindMin() const
{
  if(IsEmpty())
    throw std::domain_error("priority queue is empty");
  return *pObjKey;
}
///////////////////////////////////////////////////////////////////
Object& LeftistHeap::DeQueueMin()
{
  if(IsEmpty())
    throw std::domain_error("priorty queue is empty");
  Object& result = *pObjKey;
  LeftistHeap& oldLeft = GetLeft();
  LeftistHeap& oldRight = GetRight();

  pObjKey = 0;
  pBinaryTreeLeft = 0;
  pBinaryTreeRight = 0;
  SwapContents(oldLeft);
  delete &oldLeft;
  Merge(oldRight);
  delete &oldRight;
  return result;
}
///////////////////////////////////////////////////////////////////
LeftistHeap& LeftistHeap::GetLeft() const
{
  return dynamic_cast<LeftistHeap&>(BinaryTree::GetLeft());
}
///////////////////////////////////////////////////////////////////
LeftistHeap& LeftistHeap::GetRight() const
{
  return dynamic_cast<LeftistHeap&>(BinaryTree::GetRight());
}
///////////////////////////////////////////////////////////////////
void LeftistHeap::SwapContents(LeftistHeap& heap)
{
  Swap((void*&)pBinaryTreeLeft, (void*&)heap.pBinaryTreeLeft);
  Swap((void*&)pBinaryTreeRight, (void*&)heap.pBinaryTreeRight);
	
  Swap((void*&)pObjKey, (void*&)heap.pObjKey);

  unsigned int n = nNullPathLength;
  nNullPathLength = heap.nNullPathLength;
  heap.nNullPathLength = n;
}
///////////////////////////////////////////////////////////////////

BinomialQueue::BinomialQueue() : 
  list()
{}
///////////////////////////////////////////////////////////////////
BinomialQueue::~BinomialQueue()
{
  Purge();
}
///////////////////////////////////////////////////////////////////
void BinomialQueue::Purge()
{
  DListElement<BinomialTree*> const* p = 0;
  for(p = list.GetHeadNode(); p != 0; p = p->GetNextNodeRight())
    {
      if(!IsOwner())
	{
	  dynamic_cast<BinomialTree*>(p->GetData())->RescindOwnership();
	}
      delete p->GetData();
    }
  list.Purge();
  nCount = 0;
}
///////////////////////////////////////////////////////////////////
void BinomialQueue::AddTree(BinomialTree& tree)
{
  list.Append(&tree);
  nCount += tree.GetCount();
}
///////////////////////////////////////////////////////////////////
void BinomialQueue::RemoveTree(BinomialTree& tree)
{
  list.Extract(&tree);
  nCount -= tree.GetCount();
}
///////////////////////////////////////////////////////////////////
BinomialTree& BinomialQueue::FindMinTree() const
{
  DListElement<BinomialTree*> const* ptr = 0;
  BinomialTree* minTree = 0;
  for(ptr = list.GetHeadNode(); ptr != 0; ptr = ptr->GetNextNodeRight())
    {
      BinomialTree* tree = ptr->GetData();
      if(minTree == 0 || tree->GetKey() < minTree->GetKey())
	minTree = tree;
    }
  return *minTree;
}
///////////////////////////////////////////////////////////////////
Object& BinomialQueue::FindMin() const
{
  if(nCount == 0)
    throw std::domain_error("priority queue is empty");
  return FindMinTree().GetKey();
}
///////////////////////////////////////////////////////////////////
void BinomialQueue::Merge(MergeablePriorityQueue& queue)
{
  BinomialQueue& arg = dynamic_cast<BinomialQueue&>(queue);
  DLinkedList<BinomialTree*> oldList = list;
  list.Purge();
  nCount = 0;
  DListElement<BinomialTree*> const* p = oldList.GetHeadNode();
  DListElement<BinomialTree*> const* q = arg.list.GetHeadNode();
  BinomialTree* carry = 0;
  for(unsigned int i = 0; p || q || carry; i++)
    {
      BinomialTree* a = 0;
      if(p && p->GetData()->GetDegree() == i)
	{
	  a = p->GetData();
	  p = p->GetNextNodeRight();
	}
		
      BinomialTree* b = 0;
      if(q && q->GetData()->GetDegree() == i)
	{
	  b = q->GetData();
	  q = q->GetNextNodeRight();
	}

      BinomialTree* sum = Sum(a, b, carry);

      if(sum)
	AddTree(*sum);
      carry = Carry(a, b, carry);
    }
  arg.list.Purge();
  arg.nCount = 0;
}
///////////////////////////////////////////////////////////////////
BinomialTree* BinomialQueue::Sum(BinomialTree* a, BinomialTree* b, BinomialTree* c)
{
  if(a && !b && !c)
    return a;
  else if(!a && b && !c)
    return b;
  else if(!a && !b && c)
    return c;
  else if(a && b && c)
    return c;
  else
    return 0;
}
///////////////////////////////////////////////////////////////////
BinomialTree* BinomialQueue::Carry(BinomialTree* a, BinomialTree* b, BinomialTree* c)
{
  if(a && b && !c)
    {
      a->Add(*b);
      return a;
    }
  else if(a && !b && c)
    {
      a->Add(*c);
      return a;
    }
  else if(!a && b && c)
    {
      b->Add(*c);
      return b;
    }
  else if(a && b && c)
    {
      a->Add(*b);
      return a;
    }
  else
    return 0;
}
///////////////////////////////////////////////////////////////////
void BinomialQueue::EnQueue(Object& object)
{
  BinomialQueue queue;
  queue.AddTree(*new BinomialTree(object));
  Merge(queue);
}
///////////////////////////////////////////////////////////////////
Object& BinomialQueue::DeQueueMin()
{
  if(nCount == 0)
    throw std::domain_error("priority queue is empty");

  BinomialTree& minTree = FindMinTree();
  RemoveTree(minTree);

  BinomialQueue queue;
  while(minTree.GetDegree() > 0)
    {
      BinomialTree& child = minTree.GetSubTree(0);
      minTree.DetachSubTree(child);
      queue.AddTree(child);
    }
  Merge(queue);

  Object& result = minTree.GetKey();
  minTree.RescindOwnership();
  delete &minTree;

  return result;
}
///////////////////////////////////////////////////////////////////
Iterator& BinomialQueue::NewIterator() const
{
  return *new Iter(*this);
}
///////////////////////////////////////////////////////////////////
void BinomialQueue::Accept(Visitor& visitor) const
{
  Iterator& iter = NewIterator();
  while(!iter.IsDone())
    {
      visitor.Visit(*iter);
      ++iter;
    }
  delete &iter;
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
BinomialQueue::Iter::Iter(BinomialQueue const& _queue) :
  list(_queue.list),
  queue(*new QueueAsLinkedList())
{
  queue.RescindOwnership();
  Reset();
}
///////////////////////////////////////////////////////////////////
BinomialQueue::Iter::~Iter()
{
  delete &queue;
}
///////////////////////////////////////////////////////////////////
void BinomialQueue::Iter::Reset()
{
  queue.Purge();
  if(!list.IsEmpty())
    {
      BinomialTree* tree = list.GetFirst();
      Iterator& iter = tree->NewIterator();
      while(!iter.IsDone())
	{
	  queue.EnQueue(*iter);
	  ++iter;	
	}
      delete &iter;
      list.Extract(tree);
    }
}
///////////////////////////////////////////////////////////////////
bool BinomialQueue::Iter::IsDone() const
{
  return queue.IsEmpty();
}
///////////////////////////////////////////////////////////////////
Object& BinomialQueue::Iter::operator *() const
{
  if(!queue.IsEmpty())
    return queue.GetHead();
  else
    return NullObject::GetInstance();
}
///////////////////////////////////////////////////////////////////
void BinomialQueue::Iter::operator ++()
{
  if(!queue.IsEmpty())
    queue.DeQueue();
  if(queue.IsEmpty())
    {
      if(!list.IsEmpty())
	{
	  BinomialTree* tree = list.GetFirst();
	  Iterator& iter = tree->NewIterator();
	  while(!iter.IsDone())
	    {
	      queue.EnQueue(*iter);
	      ++iter;
	    }
	  delete &iter;
	  list.Extract(tree);
	}
    }
}
///////////////////////////////////////////////////////////////////
int BinomialQueue::CompareTo(Object const& object) const
{
  return 0;
}
