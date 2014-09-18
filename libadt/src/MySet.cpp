#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

#include "MyMacro.hpp"
#include "MyArray.hpp"
#include "MyLink.hpp"
#include "MyObject.hpp"
#include "MyContainer.hpp"
#include "MySet.hpp"

////////////////////////////////////////////////////////////////////////
using namespace ADT;

Set::Set(unsigned int n) : 
  nUniverseSize(n)
{}

Object& Set::Find(Object const& object) const
{
  return NullObject::GetInstance();
}

Set::Element Set::element = 0;

SetAsArray::SetAsArray(unsigned int n) :
  Set(n),
  array(n)
{
  for(unsigned int item = 0; item < nUniverseSize; item++)
    array[item] = false;
}

SetAsArray::~SetAsArray()
{
  Purge();
}

void SetAsArray::Insert(Object& object)
{
  unsigned int const item = dynamic_cast<Element&>(object);
  array[item] = true;
}

bool SetAsArray::IsMember(Object const& object) const
{
  unsigned int const item = dynamic_cast<Element const&>(object);
  return array[item];
}

void SetAsArray::Purge()
{
  for(unsigned int i = 0; i < nUniverseSize; i++)
    array[i] = false;
}

void SetAsArray::WithDraw(Object& object)
{
  unsigned int const item = dynamic_cast<Element const&>(object);
  array[item] = false;
}

int SetAsArray::CompareTo(Object const& object) const
{
  SetAsArray const& arg = dynamic_cast<SetAsArray const&>(object);
  if(*this == arg)
    return 0;
  else if(*this <= arg)
    return -1;
  else 
    return 1;
}

unsigned int SetAsArray::GetCount() const
{
  unsigned int result = 0;
  for(unsigned int i = 0; i < nUniverseSize; i++)
    if(array[i] == true) result++;
  return result;
}

void SetAsArray::Accept(Visitor& visitor) const
{
  for(unsigned int i = 0; i < nUniverseSize; i++)
    if(array[i] == true && !visitor.IsDone()) 
      {
	Element element(i);
	visitor.Visit(element);
      }
}


// Object& SetAsArray::Find(Object const& object) const
// {
// 	return NullObject::GetInstance();
// }

bool SetAsArray::IsFull() const
{
  return GetCount() == nUniverseSize;
}


SetAsBitVector::SetAsBitVector(unsigned int n) :
  Set(n),
  vector((n + wordBits - 1U) / wordBits)
{
  for(unsigned int i = 0; i < vector.GetLength(); i++)
    vector[i] = 0;
}

SetAsBitVector::~SetAsBitVector()
{
  Purge();
}

void SetAsBitVector::Insert(Object& object)
{
  unsigned int const item = dynamic_cast<Element&>(object);
  vector[item / wordBits] |= 1 << item % wordBits;
}

void SetAsBitVector::WithDraw(Object& object)
{
  unsigned int const item = dynamic_cast<Element&>(object);
  vector[item / wordBits] &= ~(1 << item % wordBits);
}

bool SetAsBitVector::IsMember(Object const& object) const
{
  unsigned int const item = dynamic_cast<Element const&>(object);
  return ((vector[item / wordBits] & (1 << item % wordBits)) != 0);
}

bool SetAsBitVector::IsFull() const
{
  return GetCount() == nUniverseSize;
}

//  Object& SetAsBitVector::Find(Object const& object) const
//  {
//  	return NullObject::GetInstance();
//  }

int SetAsBitVector::CompareTo(Object const& object) const
{
  SetAsBitVector const& arg = dynamic_cast<SetAsBitVector const&>(object);
  if(*this == arg)
    return 0;
  else if(*this <= arg)
    return -1;
  else 
    return 1;
}

unsigned int SetAsBitVector::GetCount() const
{
  unsigned int result = 0;
  for(unsigned int i = 0; i < nUniverseSize; i++)
    if(vector[i / wordBits] & (1 << i % wordBits)) result++;
  return result;
}

void SetAsBitVector::Accept(Visitor& visitor) const
{
  for(unsigned int i = 0; i < nUniverseSize; i++)
    if((vector[i / wordBits] & (1 << i % wordBits)) && visitor.IsDone()) 
      {Element element(i); visitor.Visit(element);}
}

void SetAsBitVector::Purge()
{
  for(unsigned int i = 0; i < vector.GetLength(); i++)
    vector[i] = 0;
}

Multiset::Multiset(unsigned int n) : 
  Set(n)
{}

MultisetAsArray::MultisetAsArray(unsigned int n) :
  Multiset(n),
  array(n)
{
  for(unsigned int item = 0; item < nUniverseSize; item++)
    array[item] = 0;
}

void MultisetAsArray::Insert(Object& object)
{
  unsigned int const item = dynamic_cast<Element&>(object);
  array[item]++;
}

void MultisetAsArray::WithDraw(Object& object)
{
  unsigned int const item = dynamic_cast<Element&>(object);
  if(array[item] > 0)
    array[item]--;
}

bool MultisetAsArray::IsMember(Object const& object) const
{
  unsigned int const item = dynamic_cast<Element const&>(object);
  return array[item] > 0;
}

Object& MultisetAsArray::Find(Object const&) const
{
  return NullObject::GetInstance();
}

void MultisetAsArray::Purge()
{
  for(unsigned int item = 0; item < nUniverseSize; item++)
    array[item] = 0;
}

void MultisetAsArray::Accept(Visitor& visitor) const
{
  for(unsigned int i = 0; i < nUniverseSize; i++)
    for(unsigned int j = 0; j < array[i]; j++)
      if(!visitor.IsDone()) {Element element(i); visitor.Visit(element);}
}

// bool MultisetAsArray::IsFull() const
// {
// 	return GetCount() == nUniverseSize;
// }

unsigned int MultisetAsArray::GetCount() const
{
  unsigned int result = 0;
  for(unsigned int i = 0; i < nUniverseSize; i++)
    result += array[i];
  return result;
}
int MultisetAsArray::CompareTo(Object const& object) const
{
  MultisetAsArray const& arg = dynamic_cast<MultisetAsArray const&>(object);
  if(*this == arg)
    return 0;
  else if(*this <= arg)
    return -1;
  else 
    return 1;
}

MultisetAsLinkedList::MultisetAsLinkedList(unsigned int n) :
  Multiset(n),
  list()
{
}

MultisetAsLinkedList::~MultisetAsLinkedList()
{
  Purge();
}

void MultisetAsLinkedList::Purge()
{
  list.Purge();
}
void MultisetAsLinkedList::Insert(Object& object)
{
  unsigned int const item = dynamic_cast<Element&>(object);
	
  if(item > nUniverseSize) throw std::invalid_argument("not member of set");
	
  DListElement<unsigned int> const* prePtr = 0;
  DListElement<unsigned int> const* ptr = list.GetHeadNode();

  while(ptr != 0 && ptr->GetData() < item)
    {
      prePtr = ptr;
      ptr = ptr->GetNextNodeRight();
    }
  if(prePtr == 0)
    list.Prepend(item);
  else
    list.InsertAfter(prePtr, item);
}

void MultisetAsLinkedList::WithDraw(Object& object)
{
  unsigned int const item = dynamic_cast<Element&>(object);
	
  if(item > nUniverseSize) throw std::invalid_argument("not member of set");
	
  list.Extract(item);
}

bool MultisetAsLinkedList::IsMember(Object const& object) const
{
  unsigned int const item = dynamic_cast<Element const&>(object);
	
  if(item > nUniverseSize) throw std::invalid_argument("not member of set");
	
  DListElement<unsigned int> const* ptr = list.GetHeadNode();
  while(ptr != 0 && ptr->GetData() != item)
    {
      ptr = ptr->GetNextNodeRight();
    }
  return ptr ? true : false;
}

/*
  Object& MultisetAsLinkedList::Find(Object const&) const
  {
  return NullObject::GetInstance();
  }
*/
void MultisetAsLinkedList::Accept(Visitor& visitor) const
{
  DListElement<unsigned int> const* ptr = list.GetHeadNode();
  for(; ptr != NULL && !visitor.IsDone(); ptr = ptr->GetNextNodeRight())
    {Element element(ptr->GetData()); visitor.Visit(element);}
}

unsigned int MultisetAsLinkedList::GetCount() const
{
  unsigned int iResult = 0;
  DListElement<unsigned int> const* ptr = list.GetHeadNode();
  for(; ptr != 0; ptr = ptr->GetNextNodeRight())	
    iResult++;
  return iResult;
}
int MultisetAsLinkedList::CompareTo(Object const& object) const
{
  MultisetAsLinkedList const& arg = dynamic_cast<MultisetAsLinkedList const&>(object);
  if(*this == arg)
    return 0;
  else if(*this <= arg)
    return -1;
  else 
    return 1;
}

SetAsArray::Iter::Iter(SetAsArray const& _set) :
  set(_set),
  nOffset(0)
{}

SetAsArray::Iter::~Iter()
{}
void SetAsArray::Iter::Reset()
{
  nOffset = 0;
}
bool SetAsArray::Iter::IsDone() const
{
  return nOffset >= set.nUniverseSize;
}
Object& SetAsArray::Iter::operator *() const
{
  return NullObject::GetInstance();
}
void SetAsArray::Iter::operator ++()
{
}

/*
  PartitionTree::PartitionTree(unsigned int item, unsigned int n) :
  Set(n),
  nItem(item),
  pParent(0),
  nRank(0)
  {
  nCount = 1;
  }

  Object& PartitionTree::GetKey() const
  {
  return NullObject::GetInstance();
  }
  Tree& GetSubTree(unsigned int) const
  {
  
  }
*/
///////////////////////////////////////////////////////////////////////
namespace ADT
{
  SetAsArray operator+(SetAsArray const& s, SetAsArray const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    SetAsArray result(s.nUniverseSize);
    for(unsigned int i = 0; i < s.nUniverseSize; i++)
      result.array[i] = s.array[i] || t.array[i];
    return result;
  }

  SetAsArray operator*(SetAsArray const& s, SetAsArray const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    SetAsArray result(s.nUniverseSize);
    for(unsigned int i = 0; i < s.nUniverseSize; i++)
      result.array[i] = s.array[i] && t.array[i];
    return result;
  }

  SetAsArray operator-(SetAsArray const& s, SetAsArray const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    SetAsArray result(s.nUniverseSize);
    for(unsigned int i = 0; i < s.nUniverseSize; i++)
      result.array[i] = s.array[i] && !t.array[i];
    return result;
  }

  bool operator==(SetAsArray const& s, SetAsArray const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    for(unsigned int i = 0; i < s.nUniverseSize; i++)
      if(s.array[i] != t.array[i]) return false;
    return true;
  }

  bool operator<=(SetAsArray const& s, SetAsArray const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    for(unsigned int i = 0; i < s.nUniverseSize; i++)
      if(s.array[i] && !t.array[i]) return false;
    return true;
  }

  SetAsBitVector operator+(SetAsBitVector const& s, SetAsBitVector const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    SetAsBitVector result(s.nUniverseSize);
    for(unsigned int i = 0; i < s.vector.GetLength(); i++)
      result.vector[i] = s.vector[i] | t.vector[i];
    return result;
  }

  SetAsBitVector operator*(SetAsBitVector const& s, SetAsBitVector const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    SetAsBitVector result(s.nUniverseSize);
    for(unsigned int i = 0; i < s.vector.GetLength(); i++)
      result.vector[i] = s.vector[i] & t.vector[i];
    return result;
  }

  SetAsBitVector operator-(SetAsBitVector const& s, SetAsBitVector const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    SetAsBitVector result(s.nUniverseSize);
    for(unsigned int i = 0; i < s.vector.GetLength(); i++)
      result.vector[i] = s.vector[i] & ~t.vector[i];
    return result;
  }

  bool operator==(SetAsBitVector const& s, SetAsBitVector const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    for(unsigned int i = 0; i < s.vector.GetLength(); i++)
      if(s.vector[i] != t.vector[i]) return false;
    return true;
  }

  bool operator<=(SetAsBitVector const& s, SetAsBitVector const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    for(unsigned int i = 0; i < s.vector.GetLength(); i++)
      if(s.vector[i] & ~t.vector[i]) return false;
    return true;
  }

  MultisetAsArray operator+(MultisetAsArray const& s, MultisetAsArray const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    MultisetAsArray result(s.nUniverseSize);
    for(unsigned int i = 0; i < s.nUniverseSize; i++)
      result.array[i] = s.array[i] + t.array[i];
    return result;
  }

  MultisetAsArray operator*(MultisetAsArray const& s, MultisetAsArray const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    MultisetAsArray result(s.nUniverseSize);
    for(unsigned int i = 0; i < s.nUniverseSize; i++)
      result.array[i] = Min(s.array[i], t.array[i]);
    return result;
  }

  MultisetAsArray operator-(MultisetAsArray const& s, MultisetAsArray const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    MultisetAsArray result(s.nUniverseSize);
    for(unsigned int i = 0; i < s.nUniverseSize; i++)
      if(t.array[ i] <= s.array[i])
	result.array[i] = s.array[i] - t.array[i];
    return result;
  }

  bool operator==(MultisetAsArray const& s, MultisetAsArray const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    for(unsigned int i = 0; i < s.nUniverseSize; i++)
      if(s.array[i] != t.array[i]) return false;
    return true;
  }

  bool operator<=(MultisetAsArray const& s, MultisetAsArray const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    for(unsigned int i = 0; i < s.nUniverseSize; i++)
      if(t.array[i] < s.array[i]) return false;
    return true;
  }

  MultisetAsLinkedList operator+(MultisetAsLinkedList const& s, MultisetAsLinkedList const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    MultisetAsLinkedList result(s.nUniverseSize);
    DListElement<unsigned int> const* p = s.list.GetHeadNode();
    DListElement<unsigned int> const* q = t.list.GetHeadNode();

    while(p && q)
      {
	if(p->GetData() <= q->GetData())
	  {
	    result.list.Append(p->GetData());
	    p = p->GetNextNodeRight();
	  }
	else
	  {
	    result.list.Append(q->GetData());
	    q = q->GetNextNodeRight();
	  }
      }
    for(; p; p = p->GetNextNodeRight())
      result.list.Append(p->GetData());
    for(; q; q = q->GetNextNodeRight())
      result.list.Append(q->GetData());
    return result;
  }

  MultisetAsLinkedList operator*(MultisetAsLinkedList const& s, MultisetAsLinkedList const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    MultisetAsLinkedList result(s.nUniverseSize);
    DListElement<unsigned int> const* p = s.list.GetHeadNode();
    DListElement<unsigned int> const* q = t.list.GetHeadNode();
    while(p && q)
      {
	int const diff = p->GetData() - q->GetData();
	if(diff == 0)
	  result.list.Append(p->GetData());
	if(diff <= 0)
	  p = p->GetNextNodeRight();
	if(diff >= 0)
	  q = q->GetNextNodeRight();
      }
    return result;
  }

  MultisetAsLinkedList operator-(MultisetAsLinkedList const& s, MultisetAsLinkedList const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");
    MultisetAsLinkedList result(s.nUniverseSize);
    DListElement<unsigned int> const* p = s.list.GetHeadNode();
    DListElement<unsigned int> const* q = t.list.GetHeadNode();
    while(p && q)
      {
	int const diff = p->GetData() - q->GetData();
	if(diff == 0)
	  {
	    p = p->GetNextNodeRight();
	    q = q->GetNextNodeRight();
	  }
	else
	  result.list.Append(p->GetData());
      }
    return result;
  }

  bool operator==(MultisetAsLinkedList const& s, MultisetAsLinkedList const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");

    DListElement<unsigned int> const* p = s.list.GetHeadNode();
    DListElement<unsigned int> const* q = t.list.GetHeadNode();
    for(;
	p && q;
	p = p->GetNextNodeRight(),
	  q = q->GetNextNodeRight()
	)
      if(p->GetData() != q->GetData()) return false;

    return true;
  }

  bool operator<=(MultisetAsLinkedList const& s, MultisetAsLinkedList const& t)
  {
    if(s.nUniverseSize != t.nUniverseSize)
      throw std::invalid_argument("mismatched sets");

    DListElement<unsigned int> const* p = s.list.GetHeadNode();
    DListElement<unsigned int> const* q = t.list.GetHeadNode();
    for(;
	p && q;
	p = p->GetNextNodeRight(),
	  q = q->GetNextNodeRight()
	)
      if(q->GetData() < p->GetData()) return false;

    return true;
  }
}
