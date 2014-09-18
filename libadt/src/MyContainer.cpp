#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
#include "MyObject.hpp"
#include "MyContainer.hpp"
///////////////////////////////////////////////////////////////////////////
using namespace ADT;

Container::Container() : nCount(0) {}

unsigned int Container::GetCount() const { return nCount; }

bool Container::IsFull() const { return false; }

bool Container::IsEmpty() const { return GetCount() == 0; }
 
HashValue Container::Hash() const
{
  HashingVisitor visitor(::Hash(typeid(*this).name()));
  Accept(visitor);
  return visitor.GetValue(); 
}

void Container::Put(ostream& s) const
{
  PuttingVisitor visitor(s);
  s << typeid(*this).name() << "{ ";
  Accept(visitor);
  s << "} ";
}

Iterator& Container::NewIterator() const
{
  return *new NullIterator;
}
///////////////////////////////////////////////////////////////////////////////
bool SearchableContainer::IsMember(Object const& obj) const
{
  bool fRet = false;
  Iterator& iter = NewIterator();
  while(!iter.IsDone())
    {
      if(*iter == obj)
	{
	  fRet = true;
	  break;
	}
      ++iter;
    }
  delete &iter;
  return fRet;
}
///////////////////////////////////////////////////////////////////////////////
Object& SearchableContainer::Find(Object const& _obj) const
{
  Object& obj = NullObject::GetInstance();
  Iterator& iter = NewIterator();
  while(!iter.IsDone())
    {
      if(*iter == obj)
	{
	  obj = *iter;
	  break;
	}
      ++iter;
    }
  delete &iter;
  return obj;
}
///////////////////////////////////////////////////////////////////////////////
bool Visitor::IsDone() const
{
  return false;
}
////////////////////////////////////////////////////////////////////////////////
PuttingVisitor::PuttingVisitor(ostream& s) : stream(s), fComma(false)
{}

void PuttingVisitor::Visit(Object& object)
{
  if(fComma)
    stream << ", ";
  stream << object;
  fComma = true;
}
//////////////////////////////////////////////////////////////////////////////////
Iterator::~Iterator()
{}
//////////////////////////////////////////////////////////////////////////////////
NullIterator::NullIterator() {}

void NullIterator::Reset() {}

bool NullIterator::IsDone() const
{
  return true;
}

Object& NullIterator::operator *() const
{
  return NullObject::GetInstance();
}

void NullIterator::operator ++() 
{}
/////////////////////////////////////////////////////////////////////////////////
HashingVisitor::HashingVisitor(HashValue _value) : value(_value)
{}
HashingVisitor::~HashingVisitor()
{}
void HashingVisitor::Visit(Object& object)
{
  value += object.Hash();
}
HashValue HashingVisitor::GetValue() const
{
  return value;
}
////////////////////////////////////////////////////////////////////////////////////
void PrePostVisitor::PreVisit(Object& object)
{}
void PrePostVisitor::Visit(Object& object)
{}
void PrePostVisitor::PostVisit(Object& object)
{}
////////////////////////////////////////////////////////////////////////////////////
PreOrder::PreOrder(Visitor& _visitor) :
  visitor(_visitor)
{}
void PreOrder::PreVisit(Object& object)
{
  visitor.Visit(object);
}
////////////////////////////////////////////////////////////////////////////////////
InOrder::InOrder(Visitor& _visitor) :
  visitor(_visitor)
{}
void InOrder::Visit(Object& object)
{
  visitor.Visit(object);
}
////////////////////////////////////////////////////////////////////////////////////
PostOrder::PostOrder(Visitor& _visitor) :
  visitor(_visitor)
{}
void PostOrder::PostVisit(Object& object)
{
  visitor.Visit(object);
}
////////////////////////////////////////////////////////////////////////////////////
