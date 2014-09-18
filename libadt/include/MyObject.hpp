#ifndef MY_OBJECT
#define MY_OBJECT

#define shift 6///<using for hash

namespace ADT
{
  /**
   *@brief HashValue is simple to typedef as unsingned int
   */
  typedef unsigned long HashValue;
  /**
   *@brief define of class Object, an abstact class, base of all
   */
  class Object
  {
  protected:
    /**
     *@brief compare two objects, pure virtual function
     *@param reference object to compare with self(this)
     *@return 0 =
     *@return -1 <
     *@return 1 >
     */
    virtual int CompareTo(Object const&) const = 0;
  public:
    /**
     *@brief destruct function
     *@param void
     *@return void
     */
    virtual ~Object();
    /**
     *@brief test object if is null object
     *@param void
     *@return ture if null else false
     */
    virtual bool IsNull() const;
    /**
     *@brief an interface can be called by base object, it simple call CompareTo
     *@param obj const reference of object to cpmpare with self(this)
     *@return same as CompareTo
     */
    virtual int Compare(Object const& obj) const;
    /**
     *@brief pure virtual function for hash
     *@param void
     *@return hash value of this object
     */
    virtual HashValue Hash() const = 0;
    /**
     *@brief put object to out stream, pure virtual function
     *@param s out stream
     *@return void
     */
    virtual void Put(ostream& s) const = 0;
  };

  //class NullObject的定义//////////////////////////////////////
  /**
   *@brief define of class NullObject
   */
  class NullObject : public Object
  {
  private:
    static NullObject instance;///< static instance of NullObject
    /**
     *@brief default construct function
     *@param void
     *@return void
     */
    NullObject();
  protected:
    /**
     *@brief compare two objects
     *@param reference object to compare with self(this)
     *@return 0 =
     *@return -1 <
     *@return 1 >
     */
    int CompareTo(Object const&) const;
  public:
    /**
     *@brief test object if is null object
     *@param void
     *@return ture if null else false, always true
     */
    bool IsNull() const;
    /**
     *@brief function for hash
     *@param void
     *@return hash value of null object
     */
    HashValue Hash() const;
    /**
     *@brief put object to out stream
     *@param s out stream
     *@return void
     */
    void Put (ostream&) const;
    /**
     *@brief get instance of null object, static function
     *@param void
     *@return reference of null object
     */
    static NullObject& GetInstance();
  };
  //class Wrapper<T>的定义///////////////////////////////////////

  /**
   *@brief define of class Wrapper<T>
   */
  template <class T>
  class Wrapper : public Object
  {
  protected:
    T data;///< wrappered data
    /**
     *@brief compare two wrapper objects
     *@param reference object to compare with self(this)
     *@return 0 =
     *@return -1 <
     *@return 1 >
     */
    int CompareTo(Object const&) const;
  public:
    /**
     *@brief default constuct function
     *@param void
     *@return void
     */
    Wrapper();
    /**
     *@brief constuct function
     *@param data to wrappered
     *@return void
     */
    Wrapper(T const& data);
    /**
     *@brief operater =
     *@param data reference of right value
     *@return *this
     *@
     */
    Wrapper& operator = (T const& data);
    /**
     *@brief operater []
     *@param void
     *@return data value of wraped
     *@
     */
    operator T const&() const;
    /**
     *@brief hash wrapped object
     *@param void
     *@return hash value
     */
    HashValue Hash() const;
    /**
     *@brief out wrapped object to out stream
     *@param reference of out stream
     *@return void
     */
    void Put(ostream&) const;
  };

  //////////////////////////////////////////////////////////////////
  /**
   *@brief operater ==
   */
  extern bool operator ==(Object const&, Object const&);
  /**
   *@brief operater !=
   */
  extern bool operator !=(Object const&, Object const&);
  /**
   *@brief operater <<
   */
  extern ostream& operator <<(ostream&, Object const&);
  /**
   *@brief operater << for std::string
   */
  extern ostream& operator <<(ostream&, std::string const&);
  /**
   *@brief operater <
   */
  extern bool operator <(Object const&, Object const&);
  /**
   *@brief operater <=
   */extern bool operator <=(Object const&, Object const&);
  /**
   *@brief operater >
   */
  extern bool operator >(Object const&, Object const&);
  /**
   *@brief operater >=
   */
  extern bool operator >=(Object const&, Object const&);
  /**
   *@brief compare two chars
   */
  extern int Compare(char, char);
  /**
   *@brief compare two ints
   */
  extern int Compare(int, int);
  /**
   *@brief compare two unsigned ints
   */
  extern int Compare(unsigned int, unsigned int);
  /**
   *@brief compare two unsigned longs
   */
  extern int Compare(unsigned long, unsigned long);
  /**
   *@brief compare two doubles
   */
  extern int Compare(double a1, double a2);
  /**
   *@brief compare two strings
   */
  extern int Compare(std::string, std::string);
  /**
   *@brief compare two pointers of void
   */
  extern int Compare(void*, void*);

  /**
   *@brief hash a char
   */
  extern HashValue Hash(char c);
  /**
   *@brief hash an integer
   */
  extern HashValue Hash(int i);
  /**
   *@brief hash an unsigned integer
   */
  extern HashValue Hash(unsigned int i);
  /**
   *@brief hash an unsigned long
   */
  extern HashValue Hash(unsigned long i);
  /**
   *@brief hash a double
   */
  extern HashValue Hash(double d);
  /**
   *@brief hash a std::string
   */
  extern HashValue Hash(std::string const& s);
  /**
   *@brief hash a void pointer
   */
  extern HashValue Hash(void* p);
  /**
   *@brief template function, swap two telplate objects by value
   */
  template<class T>
  void Swap(T x, T y)
  {
    T p = x;
    x = y;
    y = p;
  }

  //class Wrapper<T>的实现
  template <class T>
  Wrapper<T>::Wrapper() : 
    data()
  {}

  template <class T>
  Wrapper<T>::Wrapper(T const& _data) :
    data(_data)
  {}

  template <class T>
  Wrapper<T>& Wrapper<T>::operator =(T const& _data)
  {
    data = _data;
    return *this;
  }

  template <class T>
  Wrapper<T>::operator T const&() const
  {
    return data;
  }

  template <class T>
  int Wrapper<T>::CompareTo(Object const& obj) const
  {
    Wrapper<T> const& arg =
      dynamic_cast<Wrapper<T> const&> (obj);
    return ADT::Compare(data, arg.data);
  }

  template <class T>
  void Wrapper<T>::Put(ostream& s) const
  {
    s << data;
  }
  template <class T>
  HashValue Wrapper<T>::Hash() const
  {
    return ADT::Hash(data);
  }
  //////////////////////////////////////////////////////////////////
  typedef Wrapper<int> Int;
  typedef Wrapper<unsigned int> UInt;
  typedef Wrapper<unsigned long> ULong;
  typedef Wrapper<char> Char;
  typedef Wrapper<double> Double;
  typedef Wrapper<std::string> String;
  typedef Wrapper<void*> PVoid;
  //////////////////////////////////////////////////////////////////
  //class Ownership的定义
  class Ownership
  {
    bool fIsOwner;
  protected:
    Ownership();
    Ownership(Ownership& arg);
  public:
    void AssertOwnership();
    void RescindOwnership();
    bool IsOwner() const;
  };	

  ///////////////////////////////////////////////////////////////////
  //using namespace ADT;

};

#endif //MY_OBJECT
