#include <iostream>
#include <string>

using namespace std;

#include "MyObject.hpp"
#include "MyAssociation.hpp"

////////////////////////////////////////////////////////////////////////
using namespace ADT;

Association::Association(Object& _key) : key(&_key), value(0) {}

Association::Association(Object& _key, Object& _value) : key(&_key), value(&_value) {}

Association::~Association()
{
  if(IsOwner())
    {
      delete key;
      delete value;
    }
}

Object& Association::GetKey() const
{
  return *key;
}

Object& Association::GetValue() const
{
  if(value == 0)
    return NullObject::GetInstance();
  else
    return *value;
}

int Association::CompareTo(Object const& object) const
{
  Association const& association = 
    dynamic_cast<Association const&> (object);
  return GetKey().Compare(association.GetKey());
}

void Association::Put(ostream& s) const
{
  s << "Association {" << *key;
  if(value != 0)
    s<< ", " << *value;
  s << "}";
}
HashValue Association::Hash() const
{
  return key->Hash();
}
