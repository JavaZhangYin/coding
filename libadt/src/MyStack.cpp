#include <string>
#include <stdexcept>

using namespace std;

#include "MyArray.hpp"
#include "MyLink.hpp"
#include "MyObject.hpp"
#include "MyContainer.hpp"
#include "MyStack.hpp"

using namespace ADT;

//StackAsArray function
///////////////////////////////////////////////////////////
StackAsArray::StackAsArray(unsigned int size) :
  array(size)
{}
///////////////////////////////////////////////////////////
StackAsArray::StackAsArray()
{}
///////////////////////////////////////////////////////////
int StackAsArray::CompareTo(Object const& object) const
{
  StackAsArray const& stack =
    dynamic_cast<StackAsArray const&> (object);
  return ::Compare(nCount, stack.nCount);
}
///////////////////////////////////////////////////////////
void StackAsArray::Purge()
{
  if(IsOwner())
    {
      for(unsigned int i = 0; i < nCount; i++)
	delete array[i];
    }
  nCount = 0;
}
///////////////////////////////////////////////////////////
StackAsArray::~StackAsArray()
{
  Purge();
}
///////////////////////////////////////////////////////////
void StackAsArray::Push(Object& object)
{
  //	unsigned int nLen = array.GetLength();

  if(nCount == array.GetLength())
    throw std::domain_error("stack is full");
  /*
    if(2 * nCount >= nLen)
    {
    array.SetLength(2 * nCount + 1);
    }
  */
  array[nCount++] = &object;
}
///////////////////////////////////////////////////////////
Object& StackAsArray::Pop()
{
  //	unsigned int nLen = array.GetLength();
  if(nCount == 0)
    throw std::domain_error("stack is empty");
  /*
    if(2 * nCount < nLen)
    {
    array.SetLength(nLen/2 + 1);
    }
  */
  return *(array[--nCount]);
}
///////////////////////////////////////////////////////////
Object& StackAsArray::Top() const
{
  if(nCount == 0)
    throw std::domain_error("stack is empty");
  return *(array[nCount - 1U]);
}
///////////////////////////////////////////////////////////
void StackAsArray::Accept(Visitor& visitor) const
{
  for(unsigned int i = 0; i < nCount && !visitor.IsDone(); i++)
    {
      visitor.Visit(*(array[i]));
    }
}
///////////////////////////////////////////////////////////
Iterator& StackAsArray::NewIterator() const
{
  return *(new Iter(*this));
}
///////////////////////////////////////////////////////////
StackAsArray::Iter::Iter(StackAsArray const& _stack) : 
  stack(_stack)
{
  Reset();
}
///////////////////////////////////////////////////////////
bool StackAsArray::Iter::IsDone() const
{
  return nPosition >= stack.nCount;
}
///////////////////////////////////////////////////////////
Object& StackAsArray::Iter::operator *() const
{
  if(nPosition < stack.nCount)
    return *(stack.array[nPosition]);
  else
    return NullObject::GetInstance();
}
///////////////////////////////////////////////////////////
void StackAsArray::Iter::operator ++()
{
  if(nPosition < stack.nCount)
    nPosition++;
}
///////////////////////////////////////////////////////////
void StackAsArray::Iter::Reset()
{
  nPosition = 0;
}
//StackAsLinkedList function
///////////////////////////////////////////////////////////
StackAsLinkedList::StackAsLinkedList() :
  list()
{}
///////////////////////////////////////////////////////////
int StackAsLinkedList::CompareTo(Object const& object) const
{
  StackAsLinkedList const& stack =
    dynamic_cast<StackAsLinkedList const&> (object);
  return ::Compare(nCount, stack.nCount);
}
///////////////////////////////////////////////////////////
void StackAsLinkedList::Purge()
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
///////////////////////////////////////////////////////////
StackAsLinkedList::~StackAsLinkedList()
{
  Purge();
}
///////////////////////////////////////////////////////////
void StackAsLinkedList::Push(Object& object)
{
  list.Prepend(&object);
  nCount++;
}
///////////////////////////////////////////////////////////
Object& StackAsLinkedList::Pop()
{
  if(nCount == 0)
    {
      throw std::domain_error("stack is empty");
    }
  Object& result = *(list.GetFirst());
  list.Extract(&result);
  nCount--;
  return result;
}
///////////////////////////////////////////////////////////
Object& StackAsLinkedList::Top() const
{
  if(nCount == 0)
    {
      throw std::domain_error("stack is empty");
    }
  return *(list.GetFirst());
}
///////////////////////////////////////////////////////////
void StackAsLinkedList::Accept(Visitor& visitor) const
{
  DListElement<Object*> const* ptr;
  for(ptr = list.GetHeadNode(); ptr != NULL && !visitor.IsDone();
      ptr = ptr->GetNextNodeRight())
    {
      visitor.Visit(*ptr->GetData());
    }
}
///////////////////////////////////////////////////////////
StackAsLinkedList::Iter::Iter(StackAsLinkedList const& _stack) : 
  stack(_stack)
{
  Reset();
}
///////////////////////////////////////////////////////////
bool StackAsLinkedList::Iter::IsDone() const
{
  return pPosition == NULL;
}
///////////////////////////////////////////////////////////
Object& StackAsLinkedList::Iter::operator *() const
{
  if(pPosition != NULL)
    return *(pPosition->GetData());
  else
    return NullObject::GetInstance();
}
///////////////////////////////////////////////////////////
void StackAsLinkedList::Iter::operator ++()
{
  if(pPosition != NULL)
    pPosition = pPosition->GetNextNodeRight();
}
///////////////////////////////////////////////////////////
void StackAsLinkedList::Iter::Reset()
{
  pPosition = stack.list.GetHeadNode();
}
///////////////////////////////////////////////////////////
Iterator& StackAsLinkedList::NewIterator() const
{
  return *(new Iter(*this));
}
///////////////////////////////////////////////////////////
