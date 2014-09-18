#include <stdexcept>

using namespace std;

#include "MyMacro.hpp"
#include "MyArray.hpp"
#include "MyLink.hpp"
#include "MyObject.hpp"
#include "MySort.hpp"

using namespace ADT;

BucketSorter::BucketSorter(unsigned int _m) : m(_m), count(_m) 
{
}
 
void BucketSorter::DoSort(Array<unsigned int>& array)
{
  for(unsigned int i = 0; i < m; ++i)
    count[i] = 0;
  for(unsigned int j = 0; j < n; ++j)
    ++count[array[j]];
  for(unsigned int i = 0, j = 0; i < m; ++i)
    for(; count[i] > 0; --count[i])
      array[j++] = i;
}

//////////////////////////////////////////////////////////////////
unsigned int const RadixSorter::r = 10;
unsigned int const RadixSorter::R = 1 << r;
unsigned int const RadixSorter::p = (BITSOFBYTE * sizeof(unsigned) + r - 1U) / r;

void RadixSorter::DoSort(Array<unsigned int>& array)
{
  Array<unsigned int> tempArray(n);
  for(unsigned int i = 0; i < p; ++i)
    {
      for(unsigned int j = 0; j < R; ++j)
	count[j] = 0;

      for(unsigned int k = 0; k < n; ++k)
	{
	  ++count[(array[k] >> (r * i)) & (R - 1U)];
	  tempArray[k] = array[k];
	}
      unsigned int pos = 0;
      for(unsigned int j = 0; j < R; ++j)
	{
	  unsigned int const tmp = count[j];
	  count[j] = pos;
	  pos += tmp;
	}
      for(unsigned int k = 0; k < n; ++k)
	{
	  unsigned int j = (tempArray[k] >> (r * j)) & (R - 1U);
	  array[count[j]++] = tempArray[k];
	}
    }
}
