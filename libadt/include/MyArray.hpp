#ifndef MY_ARRAY
#define MY_ARRAY

namespace ADT
{
  /**
   *@brief define of class Array<T>
   */
  template <class T>
  class Array
  {
  protected:
    T* pData; ///< pointer to array data
    unsigned int nBase; ///<  base index of array
    unsigned int nLength; ///< array length
  public:
    Array();
    Array(unsigned int, unsigned int = 0);
    Array(Array const&); 
    ~Array();

    Array& operator = (Array const&);
    T const& operator[](unsigned int) const;
    T& operator[](unsigned int); 
    T const* GetData() const;
    unsigned int GetBase() const;
    unsigned int GetLength() const;

    void SetBase(unsigned int);
    void SetLength(unsigned int);
  };
  
  /**
   *@brief default construct function, array length, base index are seted to zero
   *@param void
   *@return void
   */
  template <class T>
  Array<T>::Array()
  {
    pData = new T[0];
    nBase = 0;
    nLength = 0;
  }

  /**
   *@brief construct function, 
   *@param n array length
   *@param m base index
   *@return void
   */
  template <class T>
  Array<T>::Array(unsigned int n, unsigned int m)
  {
    pData = new T[n];
    nBase = m;
    nLength = n;
  }

  /**
   *@brief copy construct function
   *@param array be copied
   *@return void
   */
  template <class T>
  Array<T>::Array(Array<T> const& array)
  {
    pData = new T[array.nLength];
    nBase = array.nBase;
    nLength = array.nLength;
    for(unsigned int i = 0; i < nLength; i++)
      {
	pData[i] = (array.pData)[i];
      }
  }

  /**
   *@brief destruct funtion
   *@param void
   *@return void
   */
  template<class T>
  Array<T>::~Array()
  {
    delete[] pData;
  }

  /**
   *@brief get array data
   *@param void
   *@return array data first address
   */
  template<class T>
  T const* Array<T>::GetData() const
  {
    return pData;
  }

  /**
   *@brief get array base index
   *@param void
   *@return base index
   */
  template<class T>
  unsigned int Array<T>::GetBase() const
  {
    return nBase;
  }

  /**
   *@brief get array length
   *@param void
   *@return array length
   */
  template<class T>
  unsigned int Array<T>::GetLength() const
  {
    return nLength;
  }

  /**
   *@brief get data at position of array, right operator
   *@param position data position at array
   *@return refrence of data at position
   */
  template <class T>
  T const& Array<T>::operator [](unsigned int position) const
  {
    unsigned int const offset = position - nBase;
    if(offset >= nLength)
      throw std::out_of_range("invalid position!");
    return pData[offset];
  } 

  /**
   *@brief duplicate array
   *@param array to duplicate
   *@return reference of *this
   */
  template <class T>
  Array<T>& Array<T>::operator =(Array<T> const& array)
  {
    if(this != &array)
      {
	delete[] pData;
	nBase = array.nBase;
	nLength = array.nLength;
	pData = new T[nLength];
	
	for(unsigned int i = 0; i < nLength; i++)
	  {
	    pData[i] = array.pData[i];
	  }
      }
    return *this;
  }

  /**
   *@brief get data at position of array, left operator
   *@return return data at position
   */
  template <class T>
  T& Array<T>::operator [] (unsigned int position)
  {
    unsigned int const offset = position - nBase;
    if(offset >= nLength)
      throw std::out_of_range("invalid position!");
    return pData[offset];
  }

  /**
   *@brief set/reset base index
   *@param newBase new base index be seted
   *@param void
   */
  template <class T>
  void Array<T>::SetBase(unsigned int newBase)
  {
    T* const newData = new T[nLength];
    if(newBase < nBase)
      {
	unsigned int shift = nBase - newBase;
	for(int i = nLength; i >= shift; --i)
	  newData[i] =pData[i - shift];
      }
    else
      {
	unsigned int shift = newBase - nBase;
	for(int i = shift; i < nLength; ++i)
	  newData[i] = pData[i + shift];
      }
    delete[] pData;
    pData = newData;
    nBase = newBase;
  }

  /**
   *@brief set/reset array length
   *@newLength new array length of array
   *@return void
   */
  template <class T>
  void Array<T>::SetLength(unsigned int newLength)
  {
    T* const newData = new T[newLength];
    unsigned int const min =
      nLength < newLength ? nLength : newLength;
    for(unsigned int i = 0; i < min; i++)
      {
	newData[i] = pData[i];
      }
    delete [] pData;
    pData = newData;
    nLength = newLength;
  }
  
  /**
   *@brief define of template class Array2D<T>
   */
  template <class T>
  class Array2D
  {
  protected:
    unsigned int nNumberOfRows; ///< number of rows
    unsigned int nNumberOfColumns; ///< number of columns
    Array<T> array; ///< array for data
  public:
    /**
     *@brirf define of template class Array2D<T>::Row, be used for describe rows
     */
    class Row
    {
    private:
      Array2D& array2D; ///< object of array2D
      unsigned int const row; ///< number of row
    public:
      /**
       *@brief construct function
       *@param _array2D array2D to bind
       *@param _row bind row number of array2D
       *@return void
       */
      Row(Array2D& _array2D, unsigned int _row) :
	array2D(_array2D), row(_row){}
      /**
       *@brief get object by column number from row(this), right operator 
       *@param column posion at row
       *@return reference data at position column in row(this) 
       */
      T& operator [] (unsigned int column) const
      {
	return array2D.Select(row, column);
      }
    };
  public:
    /**
     *@brief construct function
     *@param m row count
     *@param n column count
     */
    Array2D(unsigned int m, unsigned int n) :
      nNumberOfRows(m),
      nNumberOfColumns(n),
      array(m * n){}
    /**
     *@brief destruct function
     *param void
     *return void
     */
    virtual ~Array2D(){};

    /**
     *@brief select object at row i and column j
     *@param i row
     *@param j column
     *@return data at row i and column j
     */
    T& Select(unsigned int i, unsigned int j)
    {
      if(i >= nNumberOfRows)
	throw std::out_of_range("invalid row");
      if(j >= nNumberOfColumns)
	throw std::out_of_range("invalid column");
      return array[i * nNumberOfColumns + j];
    }

    /**
     *@brief get row object by row number 
     *@param row row number
     *@return row object
     */
    Row operator [] (unsigned int row) {return Row(*this, row);}

    /**
     *@brief get row count
     *@param void
     *@return row count
     */
    unsigned int GetNumberOfRows() const {return nNumberOfRows;}
    /**
     *@brief get column count
     *@param void
     *@return column count
     */
    unsigned int GetNumberOfColumns() const {return nNumberOfColumns;}	
  };
  /**
   *@brief define of template class Matrix<T> 
   */
  template <class T>
  class Matrix : public Array2D<T>
  {
    using Array2D<T>::nNumberOfColumns; 
    using Array2D<T>::nNumberOfRows;

  public:
    Matrix(unsigned int, unsigned int);
    virtual ~Matrix() {};
    Matrix operator *(Matrix const&) const;
    Matrix operator +(Matrix const&) const;
  };

  /**
   *@brief construct function
   *@param m row counts
   *@param n column counts
   *@return void
   */
  template <class T>
  Matrix<T>::Matrix(unsigned int m, unsigned int n) : Array2D<T>(m, n)
  {}

  /**
   *@brief operator *(mul)
   *@param arg matrix to *
   *@return result of two matrixes *
   */	
  template <class T>
  Matrix<T> Matrix<T>::operator *(Matrix<T> const& arg) const
  {
    if(nNumberOfColumns != arg.nNumberOfRows)
      throw std::invalid_argument("incompatible matrices");
    Matrix<T> result(nNumberOfRows, arg.nNumberOfColumns);
    for(unsigned int i = 0; i < nNumberOfRows; i++)
      {
	for(unsigned int j = 0; j < arg.nNumberOfColumns; j++)
	  {
	    T sum = 0;
	    for(unsigned int k = 0; k < nNumberOfColumns; k++)
	      sum += (*this)[i][k] * arg[k][j];
	    result[i][j] = sum;
	  }
      }
    return result;
  }

  /**
   *@brief operator +(add)
   *@param arg matrix to +
   *@return result of two matrixes +
   */	
  template <class T>
  Matrix<T> Matrix<T>::operator +(Matrix<T> const& arg) const
  {
    if(nNumberOfColumns != arg.nNumberOfColumns || nNumberOfRows != arg.nNumberOfRows)
      throw std::invalid_argument("incompatible matrices");
		
    Matrix<T> result(nNumberOfRows, nNumberOfColumns);
		
    for(unsigned int i = 0; i < nNumberOfRows; i++)
      for(unsigned int j = 0; j < nNumberOfColumns; j++)
	result[i][j] += (*this)[i][j] + arg[i][j];

    return result;
  }
}
#endif
