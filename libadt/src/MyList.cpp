#include <stdexcept>

using namespace std;

#include "MyArray.hpp"
#include "MyLink.hpp"

#include "MyObject.hpp"
#include "MyContainer.hpp"
#include "MyList.hpp"


using namespace ADT;

////////////////////////////////////////////////////////////////////////
ListAsArray::ListAsArray(unsigned int size) :
  array(size)
{}
////////////////////////////////////////////////////////////////////////
ListAsArray::~ListAsArray()
{
  Purge();
}
////////////////////////////////////////////////////////////////////////
void ListAsArray::Purge()
{
  if(IsOwner())
    {
      for(unsigned int i = 0; i < nCount; i++)
	delete array[i];
    }
  nCount = 0;
}
////////////////////////////////////////////////////////////////////////
void ListAsArray::Accept(Visitor& visitor) const
{
  for(unsigned int i = 0; i < nCount && !visitor.IsDone(); i++)
    {
      visitor.Visit(*(array[i]));
    }
}
////////////////////////////////////////////////////////////////////////
void ListAsArray::Insert(Object& object)
{
  if(nCount == array.GetLength())
    throw std::domain_error("list is full!");
  array[nCount] = &object;
  nCount++;
}
////////////////////////////////////////////////////////////////////////
Object& ListAsArray::operator [](unsigned int nOffset) const
{
  if(nOffset >= nCount)
    throw std::out_of_range("invalid offest!");
  return *array[nOffset];
}
////////////////////////////////////////////////////////////////////////
bool ListAsArray::IsMember(const Object& object) const
{
  for(unsigned int i = 0; i < nCount; i++)
    if(array[i] == &object)
      return true;
  return false;
}
////////////////////////////////////////////////////////////////////////
Object& ListAsArray::Find(Object const& object) const
{
  for(unsigned int i = 0; i < nCount; i++)
    if(*array[i] == object)
      return *array[i];
  return NullObject::GetInstance();
}
////////////////////////////////////////////////////////////////////////
void ListAsArray::WithDraw(Object& object)
{
  if(nCount == 0)
    throw std::domain_error("List is empty");
  unsigned int i = 0;
  while(i < nCount && array[i] != &object)
    i++;
  if(i == nCount)
    throw std::invalid_argument("object not found!");
  for(; i < nCount - 1U; i++)
    array[i] = array[i + 1];
  nCount--;
}
////////////////////////////////////////////////////////////////////////
Position& ListAsArray::FindPosition(Object const& object) const
{
  unsigned int i = 0;
  while(i < nCount && *array[i] != object)
    i++;
  return * new Pos(*this, i);
}
////////////////////////////////////////////////////////////////////////
Object& ListAsArray::operator [](Position const& arg) const
{
  Pos const& position = dynamic_cast<Pos const&> (arg);
  if(&position.list != this || position.nOffset >= nCount)
    throw std::invalid_argument("invalid position!");
  return * array[position.nOffset];
}
////////////////////////////////////////////////////////////////////////
void ListAsArray::InsertAfter(Position const& arg, Object& object)
{
  Pos const& position = dynamic_cast<Pos const&> (arg);

  if(nCount == array.GetLength())
    throw std::domain_error("List is full");
  if(&position.list != this || position.nOffset >= nCount)
    throw std::invalid_argument("invalid position!");
  unsigned int const iInsertPosition = position.nOffset + 1;
  for(unsigned int i = nCount; i > iInsertPosition; i--)
    array[i] = array[i - 1U];
  array[iInsertPosition] = &object;
  nCount++;
}
////////////////////////////////////////////////////////////////////////
void ListAsArray::InsertBefore(Position const& arg, Object& object)
{
  Pos const& position = dynamic_cast<Pos const&> (arg);

  if(nCount == array.GetLength())
    throw std::domain_error("List is full!");
  if(&position.list != this || position.nOffset > nCount)
    throw std::invalid_argument("invalid position!");
  unsigned int const iInsertPosition = position.nOffset;
  for(unsigned int i = nCount; i > iInsertPosition; i--)
    array[i] = array[i - 1U];
  array[iInsertPosition] = &object;
  nCount++;
}
////////////////////////////////////////////////////////////////////////
void ListAsArray::WithDraw(Position const& arg)
{
  Pos const& position = dynamic_cast<Pos const&> (arg);
	
  if(nCount == 0)
    throw  std::domain_error("List is empty!");
  if(&position.list != this || position.nOffset >= nCount)
    throw std::invalid_argument("invalid position!");
}
////////////////////////////////////////////////////////////////////////
Iterator& ListAsArray::NewIterator() const
{
  return *(new Pos(*this));
}
////////////////////////////////////////////////////////////////////////
int ListAsArray::CompareTo(Object const& object) const
{
  ListAsArray const& list = 
    dynamic_cast<ListAsArray const&> (object);
  return ::Compare(nCount, list.nCount);
}
////////////////////////////////////////////////////////////////////////
ListAsArray::Pos::Pos(ListAsArray const& _list, unsigned int _nOffset) :
  list(_list),
  nOffset(_nOffset)
{}
////////////////////////////////////////////////////////////////////////
ListAsArray::Pos::~Pos()
{}
////////////////////////////////////////////////////////////////////////
bool ListAsArray::Pos::IsDone() const
{
  return nOffset >= list.nCount;
}
////////////////////////////////////////////////////////////////////////
Object& ListAsArray::Pos::operator *() const
{
  if(nOffset < list.nCount)
    return *(list.array[nOffset]);
  else
    return NullObject::GetInstance();
}
////////////////////////////////////////////////////////////////////////
void ListAsArray::Pos::operator ++()
{
  if(nOffset < list.nCount)
    nOffset++;
}
////////////////////////////////////////////////////////////////////////
void ListAsArray::Pos::Reset()
{
  nOffset = 0;
}
////////////////////////////////////////////////////////////////////////
ListAsLinkedList::ListAsLinkedList() :
  linkedList()
{}
////////////////////////////////////////////////////////////////////////
ListAsLinkedList::~ListAsLinkedList()
{
  Purge();
}
////////////////////////////////////////////////////////////////////////
void ListAsLinkedList::Purge()
{
  if(IsOwner())
    {
      DListElement<Object*> const* ptr;
      for(ptr = linkedList.GetHeadNode(); ptr != NULL; ptr = ptr->GetNextNodeRight())
	delete ptr->GetData();
    }
  linkedList.Purge();
  nCount = 0;
}
////////////////////////////////////////////////////////////////////////
void ListAsLinkedList::Accept(Visitor& visitor) const
{
  DListElement<Object*> const* ptr;
  for(ptr = linkedList.GetHeadNode(); ptr != NULL && !visitor.IsDone();
      ptr = ptr->GetNextNodeRight())
    {
      visitor.Visit(*ptr->GetData());
    }
}
////////////////////////////////////////////////////////////////////////
void ListAsLinkedList::Insert(Object& object)
{
  linkedList.Append(&object);
  nCount++;
}
////////////////////////////////////////////////////////////////////////
Object& ListAsLinkedList::operator [](unsigned int nOffset) const
{
  if(nOffset >= nCount)
    throw std::out_of_range("invalid offest!");
  unsigned int i = 0;
  DListElement<Object*> const* ptr = linkedList.GetHeadNode();
  while(i < nOffset && ptr != 0)
    {
      ptr = ptr->GetNextNodeRight();
      i++;
    }
  if(ptr == 0)
    throw std::logic_error("should never happen");
  return *ptr->GetData();
}
////////////////////////////////////////////////////////////////////////
bool ListAsLinkedList::IsMember(const Object& object) const
{
  DListElement<Object*> const* ptr;
  for(ptr = linkedList.GetHeadNode(); ptr != 0; ptr = 
	ptr->GetNextNodeRight())
    if(ptr->GetData() == &object)
      return true;
  return false;
}
////////////////////////////////////////////////////////////////////////
Object& ListAsLinkedList::Find(Object const& object) const
{
  DListElement<Object*> const* ptr;
  for(ptr = linkedList.GetHeadNode(); ptr != 0; ptr = 
	ptr->GetNextNodeRight())
    if(*ptr->GetData() == object)
      return *ptr->GetData();
  return NullObject::GetInstance();
}
////////////////////////////////////////////////////////////////////////
void ListAsLinkedList::WithDraw(Object& object)
{
  if(nCount == 0)
    throw std::domain_error("List is empty");
  linkedList.Extract(&object);
  nCount--;
}
////////////////////////////////////////////////////////////////////////
Position& ListAsLinkedList::FindPosition(Object const& object) const
{
  DListElement<Object*> const* ptr = linkedList.GetHeadNode();
  while(ptr != 0 && *ptr->GetData() != object)
    ptr = ptr->GetNextNodeRight();
  return * new Pos(*this, ptr);
}
////////////////////////////////////////////////////////////////////////
Object& ListAsLinkedList::operator [](Position const& arg) const
{
  Pos const& position = dynamic_cast<Pos const&> (arg);
  if(&position.list != this || position.pElement == 0)
    throw std::invalid_argument("invalid position!");
  return *position.pElement->GetData();
}
////////////////////////////////////////////////////////////////////////
void ListAsLinkedList::InsertAfter(Position const& arg, Object& object)
{
  Pos const& position = dynamic_cast<Pos const&> (arg);

  if(&position.list != this || position.pElement == 0)
    throw std::invalid_argument("invalid position!");
  linkedList.InsertAfter(position.pElement, &object);
  nCount++;
}
////////////////////////////////////////////////////////////////////////
void ListAsLinkedList::InsertBefore(Position const& arg, Object& object)
{
  Pos const& position = dynamic_cast<Pos const&> (arg);

  if(&position.list != this || position.pElement == 0)
    throw std::invalid_argument("invalid position!");
  linkedList.InsertBefore(position.pElement, &object);
  nCount++;
}
////////////////////////////////////////////////////////////////////////
void ListAsLinkedList::WithDraw(Position const& arg)
{
  Pos const& position = dynamic_cast<Pos const&> (arg);
	
  if(nCount == 0)
    throw  std::domain_error("List is empty!");
  if(&position.list != this || position.pElement == 0)
    throw std::invalid_argument("invalid position!");
  linkedList.Extract(position.pElement->GetData());
  nCount--;
}
////////////////////////////////////////////////////////////////////////
Iterator& ListAsLinkedList::NewIterator() const
{
  return *(new Pos(*this));
}
////////////////////////////////////////////////////////////////////////
int ListAsLinkedList::CompareTo(Object const& object) const
{
  ListAsLinkedList const& list = 
    dynamic_cast<ListAsLinkedList const&> (object);
  return ::Compare(nCount, list.nCount);
}
////////////////////////////////////////////////////////////////////////
ListAsLinkedList::Pos::Pos(ListAsLinkedList const& _list, DListElement<Object*> const* _pElement) :
  list(_list),
  pElement(_pElement)
{}
////////////////////////////////////////////////////////////////////////
ListAsLinkedList::Pos::Pos(ListAsLinkedList const& _list) :
  list(_list),
  pElement(_list.linkedList.GetHeadNode())
{}
////////////////////////////////////////////////////////////////////////
ListAsLinkedList::Pos::~Pos()
{}
////////////////////////////////////////////////////////////////////////
bool ListAsLinkedList::Pos::IsDone() const
{
  return pElement == NULL;
}
////////////////////////////////////////////////////////////////////////
Object& ListAsLinkedList::Pos::operator *() const
{
  if(pElement != NULL)
    return *(pElement->GetData());
  else
    return NullObject::GetInstance();
}
////////////////////////////////////////////////////////////////////////
void ListAsLinkedList::Pos::operator ++()
{
  if(pElement != NULL)
    pElement = pElement->GetNextNodeRight();
}
void ListAsLinkedList::Pos::Reset()
{
  pElement = list.linkedList.GetHeadNode();
}
////////////////////////////////////////////////////////////////////////
SortedListAsArray::SortedListAsArray(unsigned int size) :
  ListAsArray(size)
{}
////////////////////////////////////////////////////////////////////////
SortedListAsArray::~SortedListAsArray()
{}
////////////////////////////////////////////////////////////////////////
void SortedListAsArray::Insert(Object& object)
{
  if(nCount == array.GetLength())
    throw std::domain_error("list is full");
  unsigned int i = nCount;
  while(i > 0 && *array[i - 1U] > object)
    {
      array[i] = array[i - 1U];
      i--;
    }
  array[i] = &object;
  nCount++;
}
////////////////////////////////////////////////////////////////////////
unsigned int SortedListAsArray::FindOffset(Object const& object) const
{
  int left = 0;
  int right = nCount - 1;

  while(left <= right)
    {
      int const middle = (left + right) / 2;
      if(object > *array[middle])
	left = middle + 1;
      else if(object < *array[middle])
	right = middle - 1;
      else
	return middle;
    }
  return nCount;
}
////////////////////////////////////////////////////////////////////////
Object& SortedListAsArray::Find(Object const& object) const
{
  unsigned int const offset = FindOffset(object);
  if(offset < nCount)
    return *array[offset];
  else return NullObject::GetInstance();
}
////////////////////////////////////////////////////////////////////////
Position& SortedListAsArray::FindPosition(Object const& object) const
{
  Pos& result = *new Pos(*this);
  result.nOffset = FindOffset(object);
  return result;
}
////////////////////////////////////////////////////////////////////////
void SortedListAsArray::WithDraw(Object& object)
{
  if(nCount == 0)
    throw std::domain_error("list is empty!");
  unsigned int const offset = FindOffset(object);
  if(offset == nCount)
    throw std::invalid_argument("object not find");
  for(unsigned int i = offset; i < nCount - 1U; i++)
    array[i] = array[i + 1];
  nCount--;
}
////////////////////////////////////////////////////////////////////////
SortedListAsLinkedList::SortedListAsLinkedList()
{}
////////////////////////////////////////////////////////////////////////
SortedListAsLinkedList::~SortedListAsLinkedList()
{}
////////////////////////////////////////////////////////////////////////
void SortedListAsLinkedList::Insert(Object& object)
{
  DListElement<Object*> const* prePtr = 0;
  DListElement<Object*> const* ptr = linkedList.GetHeadNode();

  while(ptr != 0 && *ptr->GetData() < object)
    {
      prePtr = ptr;
      ptr = ptr->GetNextNodeRight();
    }
  if(prePtr == 0)
    linkedList.Prepend(&object);
  else
    linkedList.InsertAfter(prePtr, &object);
  nCount++;
}
////////////////////////////////////////////////////////////////////////
