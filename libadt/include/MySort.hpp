#ifndef MYSORT_H
#define MYSORT_H

namespace ADT
{
  template <class T>
  class Sorter
  {
  protected:
    unsigned int n;

    static void Swap(T&, T&);
    virtual void DoSort(Array<T>&) = 0;
  public:
    void Sort(Array<T>&);
  };
  
  template <class T>
  void Sorter<T>::Swap(T& x, T& y)
  {
    T const tmp = x;
    x = y;
    y = tmp;
  }
  
  template <class T>
  void Sorter<T>::Sort(Array<T>& array)
  {
    n = array.GetLength();
    if(n > 0)
      {
	unsigned int const tmp = array.GetBase();
	
	array.SetBase(0);
	DoSort(array);
	array.SetBase(tmp);
      }
  }
  
  ///////////////////////////////////////////////////////////////////////
  template <class T>
  class InsertionSorter : public Sorter<T> 
  {
  protected:
    using Sorter<T>::n;
  };

  template <class T>
  class ExchangeSorter : public Sorter<T>
  {
    protected:
    using Sorter<T>::n;
  };

  template <class T>
  class SelectionSorter : public Sorter<T> 
  {
    protected:
    using Sorter<T>::n;
  };

  template <class T>
  class MergeSorter : public Sorter<T>
  {
  protected:
    using Sorter<T>::n;
  };

  template <class T>
  class DistributionSorter : public Sorter<T> 
  {
  protected:
    using Sorter<T>::n;
  };

  /////////////////////////////////////////////////////////////////
  template <class T>
  class StraightInsertionSorter : public InsertionSorter<T> // 直接插入排序
  {
  protected:
    using InsertionSorter<T>::Sorter::n;
    
    void DoSort(Array<T>& array)
    {
      for(unsigned int i = 1; i < n; ++i)
	for(unsigned int j = i;
	    j > 0 && array[j - 1U] > array[j]; --j)
	  Swap(array[j], array[j - 1U]);
    }
  };
  ///////////////////////////////////////////////////////////////////////
  template <class T>
  class BinaryInsertionSorter : public InsertionSorter<T> // 二分法插入排序
  {
  protected:
    using InsertionSorter<T>::Sorter::n;
    void DoSort(Array<T>& array)
    {
      for(unsigned int i = 1; i < n; ++i)
	{
	  T const& tmp = array[i];
	  unsigned int left = 0;
	  unsigned int right = i;
	  while(left < right)
	    {
	      unsigned int const middle = (left + right) / 2;
	      if(tmp >= array[middle])
		left = middle + 1;
	      else
		right = middle;
	    }
	  for(unsigned int j = i; j > left; --j)
	    Swap(array[j - 1U], array[j]);
	}
    }
  };
  
  //////////////////////////////////////////////////////////////////////////
  template <class T>
  class BubbleSorter : public ExchangeSorter<T>
  {
  protected:
    using InsertionSorter<T>::Sorter::n;

    void DoSort(Array<T>& array)
    {
      for(unsigned int i = n; i > 1; --i)
	for(unsigned int j = 0; j < i - 1U; ++j)
	  if(array[j] > array[j + 1])
	    Swap(array[j], array[j + 1]);
    }
  };
  //////////////////////////////////////////////////////////////////////////
  template <class T>
  class QuickSorter : public ExchangeSorter<T> // 快速排序
  {
  protected:
    using ExchangeSorter<T>::Sorter::n;

    static unsigned int const cutOff;
    virtual unsigned int SelectPivot(Array<T>&, unsigned int, unsigned int) = 0;
    void DoSort(Array<T>&);
    void DoSort(Array<T>&, unsigned int, unsigned int); 
  };

  template <class T>
  void QuickSorter<T>::DoSort(Array<T>& array)
  {
    DoSort(array, 0, n - 1U);
    StraightInsertionSorter<T> s;
    s.Sort(array);
  }

  template <class T>
  void QuickSorter<T>::DoSort(Array<T>& array, unsigned int left, unsigned int right)
  {
    if(right - left + cutOff)
      {
	unsigned int const p = SelectPivot(array, left, right);
	Swap(array[p], array[right]);
	T& pivot = array[right];
	unsigned int i = left;
	unsigned int j = right - 1U;
	
	for(;;)
	  {
	    while(i < j && array[i] < pivot) ++i;
	    while(i < j && array[j] > pivot) --j;
	    
	    if(i >= j) break;
	    Swap(array[i++], array[j--]);
	  }
	
	if(array[i] > pivot)
	  Swap(array[i], pivot);
	if(left < i)
	  DoSort(array, left, i - 1U);
	if(right > i)
	  DoSort(array, i + 1U, right);
      }
  }
  ///////////////////////////////////////////////////////////////////////////////////////
  template <class T>
  class MedianOfThreeQuickSorter : public QuickSorter<T> //
  {
  protected:
    using QuickSorter<T>::Sorter::n;

    unsigned int SelectPivot(Array<T>& array, unsigned int left, unsigned int right)
    {
      unsigned int middle = (left + right) / 2;
      if(array[left] > array[middle])
	Swap(left, middle);
      if(array[left] > array[right])
	Swap(left, right);
      if(array[middle] > array[right])
	Swap(middle, right);
      return middle;
    }
  };
  
  ////////////////////////////////////////////////////////////////////////////////////////
  template <class T>
  class StraightSelcetionSorter : public SelectionSorter<T> // 直接选择排序
  {
  protected:
    using SelectionSorter<T>::Sorter::n;

    void DoSort(Array<T>& array)
    {
      for(unsigned int i = n; i > 1; --i)
	{
	  unsigned int max = 0;
	  for(unsigned int j = 1; j < i; ++j)
	    if(array[j] > array[max])
	      max = j;
	  Swap(array[i - 1U], array[max]);
	}
    }
  };

  //////////////////////////////////////////////////////////////////////////////////////////
  template <class T>
  class HeapSorter : public SelectionSorter<T>
  {
  protected:
    using SelectionSorter<T>::Sorter::n;

    void BuildHeap(Array<T>&);
    void PercolateDown(Array<T>&, unsigned int, unsigned int);
    void DoSort(Array<T>&);
  };
  
  template <class T>
  void HeapSorter<T>::PercolateDown(Array<T>& array, unsigned int length, unsigned int i)
  {
    while(i <= length / 2)
      {
	unsigned int child = i << 1; // i * 2
	if(child + 1 <= length && array[child + 1] > array[child])
	  child += 1;
	if(array[i] >= array[child])
	  break;
	Swap(array[i], array[child]);
	i = child;
      }
  }
  
  template <class T>
  void HeapSorter<T>::BuildHeap(Array<T>& array)
  {
    for(unsigned int i = n / 2; i > 0; --i)
      PercolateDown(array, n, i);
  }
  
  template <class T>
  void HeapSorter<T>::DoSort(Array<T>& array)
  {
    array.SetBase(1);
    BuildHeap(array);
    for(unsigned int i = n; i >= 2; --i)
      {
	Swap(array[i], array[1]);
	PercolateDown(array, i - 1U, 1);
      }
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  template <class T>
  class TwoWayMergeSorter : public MergeSorter<T> // 两路归并排序
  {
  protected:
    using MergeSorter<T>::Sorter::n;

    Array<T>* tempArray;
      
    void Merge(Array<T>&, unsigned int, unsigned int, unsigned int);
    void DoSort(Array<T>&, unsigned int, unsigned int);
    void DoSort(Array<T>&);
  public:
    TwoWayMergeSorter() : tempArray(0)
      {
      }
  };
  
  template <class T>
  void TwoWayMergeSorter<T>::Merge(Array<T>& array, unsigned int left, unsigned int middle, unsigned right)
  {
    unsigned int i = left;
    unsigned int j = left;
    unsigned int k = middle + 1;
    while(j <= middle && k <= right)
      {
	if(array[j] <= array[k])
	  (*tempArray)[i++] = array[j++];
	else
	  (*tempArray)[i++] = array[k++];
      }
      
    while(j <= middle)
      (*tempArray)[i++] = array[j++];
    while(k <= right)
      (*tempArray)[i++] = array[k++];
    for(i = left; i <= right; ++i)
      {
	array[i] = (*tempArray)[i];
      }
  }
  
  template <class T>
  void TwoWayMergeSorter<T>::DoSort(Array<T>& array)
  {
    tempArray = new Array<T> (n);
    DoSort(array, 0, n - 1U);
    delete tempArray;
    tempArray = 0;
  }
  
  template <class T>
  void TwoWayMergeSorter<T>::DoSort(Array<T>& array, unsigned int left, unsigned int right)
  {
    if(left < right)
      {
	unsigned int const middle = (left + right) / 2;
	DoSort(array, left, middle);
	DoSort(array, middle + 1, right);
	Merge(array, left, middle, right);
      }
  }
  //////////////////////////////////////////////////////////////////////////////////////////
  class BucketSorter : public DistributionSorter<unsigned int> // 桶式排序
  {
  protected:
    unsigned int const m;
    Array<unsigned int> count;
    
    void DoSort(Array<unsigned int>&);
  public:
    BucketSorter(unsigned int _m);
  };
  ///////////////////////////////////////////////////////////////////////////////////////////
  class RadixSorter : public DistributionSorter<unsigned int>
  {
  protected:
    static unsigned int const r;
    static unsigned int const R;
    static unsigned int const p;
    
    Array<unsigned int> count;
    
    void DoSort(Array<unsigned int>&);
  public:
    RadixSorter() : count(R) 
    {
    }
  };
  
}
#endif //MYSORT_H
