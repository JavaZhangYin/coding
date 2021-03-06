#include <stdexcept>
using namespace std;

#include "MyArray.hpp"
#include "MyLink.hpp"
#include "MyObject.hpp"
#include "MyContainer.hpp"
#include "MyQueue.hpp"

using namespace ADT;

///////////////////////////////////////////////////////////////////
QueueAsArray::QueueAsArray(unsigned int size) :
  array(size),
  nHead(0),
  nTail(size - 1U)
{}
///////////////////////////////////////////////////////////////////
void QueueAsArray::Purge()
{
  if(IsOwner())
    {
      for(unsigned int i = 0; i < nCount; i++)
	{
	  delete array[nHead];
	  if(++nHead == array.GetLength())
	    nHead = 0;
	}
    }

  nCount = 0;
}
///////////////////////////////////////////////////////////////////
QueueAsArray::~QueueAsArray()
{
  Purge();
}
///////////////////////////////////////////////////////////////////
int QueueAsArray::CompareTo(Object const& object) const
{	
  QueueAsArray const& queue =
    dynamic_cast<QueueAsArray const&> (object);
  return ::Compare(nCount, queue.nCount);
}
///////////////////////////////////////////////////////////////////
Object& QueueAsArray::GetHead() const
{
  if(nCount == 0)
    throw std::domain_error("queue is empty!");
  return *array[nHead];
}
///////////////////////////////////////////////////////////////////
void QueueAsArray::EnQueue(Object& object)
{
  if(nCount == array.GetLength())
    throw std::domain_error("queue is full!");
  if(++nTail == array.GetLength())
    nTail = 0;
  array[nTail] = &object;
  ++nCount;
}
///////////////////////////////////////////////////////////////////
Object& QueueAsArray::DeQueue()
{
  if(nCount == 0)
    throw std::domain_error("queue is empty");
  Object& result = *array[nHead];
  if(++nHead == array.GetLength())
    nHead = 0;
  nCount--;
  return result;
}
///////////////////////////////////////////////////////////////////
void QueueAsArray::Accept(Visitor& visitor) const
{
  for(unsigned int i = 0; i < nCount && !visitor.IsDone(); i++)
    {
      visitor.Visit(*(array[i]));
    }
}
///////////////////////////////////////////////////////////////////
bool QueueAsArray::IsFull() const
{
  return nCount == array.GetLength();
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
QueueAsLinkedList::QueueAsLinkedList() : list()
{}
void QueueAsLinkedList::Purge()
{
  if(IsOwner())
    {
      DListElement<Object*> const* ptr;
      for(ptr = list.GetHeadNode(); ptr != NULL; ptr = ptr->GetNextNodeRight())
	delete ptr->GetData();
    }
  list.Purge();
  nCount = 0;
}
///////////////////////////////////////////////////////////////////
QueueAsLinkedList::~QueueAsLinkedList()
{
  Purge();
}
///////////////////////////////////////////////////////////////////
Object& QueueAsLinkedList::GetHead() const
{
  if(nCount == 0)
    throw std::domain_error("queue is empty");
  return *list.GetFirst();
}
///////////////////////////////////////////////////////////////////
void QueueAsLinkedList::EnQueue(Object& object)
{
  list.Append(&object);
  nCount++;
}
///////////////////////////////////////////////////////////////////
Object& QueueAsLinkedList::DeQueue()
{
  if(nCount == 0)
    throw std::domain_error("queue is empty");
  Object& result = *list.GetFirst();
  list.Extract(&result);
  nCount--;
  return result;
}
///////////////////////////////////////////////////////////////////
int QueueAsLinkedList::CompareTo(Object const& object) const
{
  QueueAsLinkedList const& queue =
    dynamic_cast<QueueAsLinkedList const&> (object);
  return ::Compare(nCount, queue.nCount);
}
///////////////////////////////////////////////////////////////////
void QueueAsLinkedList::Accept(Visitor& visitor) const
{
  DListElement<Object*> const* ptr = NULL;
  for(ptr = list.GetHeadNode(); ptr != NULL && !visitor.IsDone();
      ptr = ptr->GetNextNodeRight())
    {		
      visitor.Visit(*ptr->GetData());
    }
}
///////////////////////////////////////////////////////////////////
void Deque::EnQueue(Object& object)
{
  EnQueueTail(object);
}
///////////////////////////////////////////////////////////////////
Object& Deque::DeQueue()
{
  return DeQueueHead();
}
///////////////////////////////////////////////////////////////////
DequeAsArray::DequeAsArray(unsigned int size) :
  QueueAsArray(size)
{}
///////////////////////////////////////////////////////////////////
DequeAsArray::~DequeAsArray()
{}
///////////////////////////////////////////////////////////////////
Object& DequeAsArray::GetHead() const
{
  return QueueAsArray::GetHead();
}
///////////////////////////////////////////////////////////////////
Object& DequeAsArray::GetTail() const
{
  if(nCount == 0)
    throw std::domain_error("deque is empty");
  return *array[nTail];
}
///////////////////////////////////////////////////////////////////
void DequeAsArray::EnQueue(Object& object)
{
  Deque::EnQueue(object);
}
///////////////////////////////////////////////////////////////////
void DequeAsArray::EnQueueHead(Object& object)
{
  if(nCount == array.GetLength())
    throw std::domain_error("deque is full");
  if(nHead == 0)
    nHead = array.GetLength() - 1U;
  array[nHead] = &object;
  nCount++;
}
///////////////////////////////////////////////////////////////////
void DequeAsArray::EnQueueTail(Object& object)
{
  QueueAsArray::EnQueue(object);
}
///////////////////////////////////////////////////////////////////
Object& DequeAsArray::DeQueue()
{
  return Deque::DeQueue();
}
///////////////////////////////////////////////////////////////////
Object& DequeAsArray::DeQueueHead()
{
  return QueueAsArray::DeQueue();
}
///////////////////////////////////////////////////////////////////
Object& DequeAsArray::DeQueueTail()
{
  if(nCount == 0)
    throw std::domain_error("deque is empty");
  Object& result = *array[nTail];
  if(nTail-- == 0)
    nTail = array.GetLength() - 1U;
  nCount--;
  return result;
}
///////////////////////////////////////////////////////////////////
DequeAsLinkedList::DequeAsLinkedList()
{}
///////////////////////////////////////////////////////////////////
DequeAsLinkedList::~DequeAsLinkedList()
{}
///////////////////////////////////////////////////////////////////
Object& DequeAsLinkedList::GetHead() const
{
  return QueueAsLinkedList::GetHead();
}
///////////////////////////////////////////////////////////////////
Object& DequeAsLinkedList::GetTail() const
{
  if(nCount == 0)
    throw std::domain_error("deque is empty");
  return *list.GetLast();
}
///////////////////////////////////////////////////////////////////
void DequeAsLinkedList::EnQueue(Object& object)
{
  Deque::EnQueue(object);
}
///////////////////////////////////////////////////////////////////
void DequeAsLinkedList::EnQueueHead(Object& object)
{
  list.Prepend(&object);
  nCount++;
}
///////////////////////////////////////////////////////////////////
void DequeAsLinkedList::EnQueueTail(Object& object)
{
  QueueAsLinkedList::EnQueue(object);
}
///////////////////////////////////////////////////////////////////
Object& DequeAsLinkedList::DeQueue()
{
  return Deque::DeQueue();
}
///////////////////////////////////////////////////////////////////
Object& DequeAsLinkedList::DeQueueHead()
{
  return QueueAsLinkedList::DeQueue();
}
///////////////////////////////////////////////////////////////////
Object& DequeAsLinkedList::DeQueueTail()
{
  if(nCount == 0)
    throw std::domain_error("deque is empty");
  Object& result = *list.GetLast();
  list.Extract(&result);
  nCount--;
  return result;
}
///////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
