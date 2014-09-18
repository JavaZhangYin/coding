#include <string>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

#include "MyObject.hpp"

#define bitsizeof(t) (sizeof(t) * (sizeof(long)/4) * 8)
#define mask (~0UL << (bitsizeof(HashValue) - shift))

//////////////////////////////////////////////////////////////
namespace ADT
{
  bool operator ==(Object const& left, Object const& right)
  {return left.Compare(right) == 0;}

  bool operator !=(Object const& left, Object const& right)
  {return left.Compare(right) != 0;}

  ostream& operator <<(ostream& s, Object const& object)
  {
    object.Put(s);
    return s;
  }
  ostream& operator <<(ostream& s, std::string const& str)
  {
    s << str.c_str();
    return s;
  }	
  bool operator <(Object const& left, Object const& right)
  {return left.Compare(right) < 0;}

  bool operator <=(Object const& left, Object const& right)
  {return left.Compare(right) <= 0;}

  bool operator >(Object const& left, Object const& right)
  {return left.Compare(right) > 0;}

  bool operator >=(Object const& left, Object const& right)
  {return left.Compare(right) >= 0;}



  int Compare(std::string a1, std::string a2)
  {
    return strcmp(a1.c_str(), a2.c_str());
  }
  int Compare(char a1, char a2)
  {
    if(a1 == a2)
      return 0;
    else if(a1 > a2)
      return 1;
    else
      return -1;
  }
  int Compare(int a1, int a2)
  {
    if(a1 == a2)
      return 0;
    else if(a1 > a2)
      return 1;
    else
      return -1;
  }
  int Compare(unsigned int a1, unsigned int a2)
  {
    if(a1 == a2)
      return 0;
    else if(a1 > a2)
      return 1;
    else
      return -1;
  }
	
  int Compare(unsigned long a1, unsigned long a2)
  {
    if(a1 == a2)
      return 0;
    else if(a1 > a2)
      return 1;
    else
      return -1;
  }
  int Compare(double a1, double a2)
  {
    if(a1 == a2)
      return 0;
    else if(a1 > a2)
      return 1;
    else
      return -1;
  }

  int Compare(void* a1, void* a2)
  {
    if(a1 == a2)
      return 0;
    else if(a1 > a2)
      return 1;
    else
      return -1;
  }

  HashValue Hash(char c)
  {
    return abs(c);
  }
  HashValue Hash(int i)
  {
    return abs(i);
  }

   HashValue Hash(void * p)
  {
    return abs((long)p);
  }

  HashValue Hash(unsigned int i)
  {
    return i;
  }
  HashValue Hash(unsigned long i)
  {
    return i;
  }
  HashValue Hash(double d)
  {
    if(d == 0)
      return 0;
    else
      {
	int exponent;
	double mantissa = frexp(d, &exponent);
	return (HashValue)(2 * fabs(mantissa) - 1) * ~0U;
      }
  }
  HashValue Hash(std::string const& s)
  {
    HashValue result = 0;
    for(unsigned int i = 0; s[i] != 0; i++)
      result = (result & mask) ^ (result << shift) ^ s[i];
    return result;
  }
}

using namespace ADT;
/////////////////////////////////////////////////////////////////////////////////
Object::~Object()
{}

bool Object::IsNull() const
{
  return false;
}

int Object::Compare(Object const& object) const
{
  if(typeid(*this) == typeid(object))
    return CompareTo(object);
  else if(typeid(*this).before(typeid(object)))
    return -1;
  else 
    return 1;
}

//////////////////////////////////////////////////////////////
NullObject NullObject::instance;

NullObject::NullObject()
{}

bool NullObject::IsNull() const
{
  return true;
}

int NullObject::CompareTo(Object const&) const
{
  return 0;
}

HashValue NullObject::Hash() const
{
  return 0;
}

void NullObject::Put(ostream& s) const
{
  s << "NullObject";
}

NullObject& NullObject::GetInstance()
{
  return instance;
}
//////////////////////////////////////////////////////////////////////
Ownership::Ownership() : fIsOwner(true)
{}

Ownership::Ownership(Ownership& arg) : fIsOwner(arg.fIsOwner)
{
  arg.fIsOwner = false;
}

void Ownership::AssertOwnership()
{
  fIsOwner = true;
}

void Ownership::RescindOwnership()
{
  fIsOwner = false;
}

bool Ownership::IsOwner() const
{
  return fIsOwner;
}

