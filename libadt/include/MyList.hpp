#ifndef MY_LIST
#define MY_LIST

namespace ADT
{
  /**
   *@brief define of class List, it is an interface
   */
  class List : public virtual SearchableContainer
  {
  public:
    /**
     *@brief 
     */
    virtual Object& operator[] (unsigned int) const = 0;
    virtual Object& operator[] (Position const&) const = 0;
    virtual Position& FindPosition(Object const&) const = 0;
    virtual void WithDraw(Position const&) = 0;
  };

  class OrderedList : public virtual List
  {
  public:
    virtual void InsertAfter(Position const&, Object&) = 0;
    virtual void InsertBefore(Position const&, Object&) = 0;
  };

  class ListAsArray : public virtual OrderedList
  {
  protected:
    Array<Object*> array;
    class Pos;
  public:
    ListAsArray(unsigned int);
    ~ListAsArray();
    //virtual function of OrderedList	
    void InsertAfter(Position const&, Object&);
    void InsertBefore(Position const&, Object&);
    //virtual function of List
    Object& operator[] (unsigned int)const;
    Object& operator[] (Position const&) const;
    Position& FindPosition(Object const&) const;
    void WithDraw(Position const&);
    //virtual function of SearchableContainer
    bool IsMember(Object const&) const;
    void Insert(Object&);
    void WithDraw(Object&);
    Object& Find(Object const&) const;
    //virtual function of Container
    void Purge();
    void Accept(Visitor&) const;
    Iterator& NewIterator() const;
    //virtual function of Object
    int CompareTo(Object const&) const;

    friend class Pos;
  };

  class ListAsArray::Pos : public Position
  {
  protected:
    ListAsArray const& list;
    unsigned int nOffset;
  public:
    Pos(ListAsArray const&, unsigned int = 0);
    ~Pos();
    void Reset();
    bool IsDone() const;
    Object& operator *() const;
    void operator ++();

    friend class ListAsArray;
    friend class SortedListAsArray;
  };
  ////////////////////////////////////////////////////////////////////
  class ListAsLinkedList : public virtual OrderedList
  {
  protected:
    DLinkedList<Object*> linkedList;
    class Pos;

  public:
    ListAsLinkedList();
    ~ListAsLinkedList();
    //virtual function of OrderedList	
    void InsertAfter(Position const&, Object&);
    void InsertBefore(Position const&, Object&);
    //virtual function of List
    Object& operator[] (unsigned int)const;
    Object& operator[] (Position const&) const;
    Position& FindPosition(Object const&) const;
    void WithDraw(Position const&);
    //virtual function of SearchableContainer
    bool IsMember(Object const&) const;
    void Insert(Object&);
    void WithDraw(Object&);
    Object& Find(Object const&) const;
    //virtual function of Container
    void Purge();
    void Accept(Visitor&) const;
    Iterator& NewIterator() const;
    //virtual function of Object
    int CompareTo(Object const&) const;

    friend class Pos;
  };
  class ListAsLinkedList::Pos : public Position
  {
  protected:
    ListAsLinkedList const& list;
    DListElement<Object*> const* pElement;
  public:
    Pos(ListAsLinkedList const&, DListElement<Object*> const*);
    Pos(ListAsLinkedList const&);
    ~Pos();
    void Reset();
    bool IsDone() const;
    Object& operator *() const;
    void operator ++();

    friend class ListAsLinkedList;
    friend class SortedListAsLinkedList;
  };
  /////////////////////////////////////////////////////////////////////////////
  class SortedList : public virtual List
  {};

  class SortedListAsArray : public virtual SortedList, public virtual ListAsArray
  {
  private:
    unsigned int FindOffset(Object const&) const;
	
  public:
    SortedListAsArray(unsigned int);
    ~SortedListAsArray();

    void Insert(Object& object);
    Object& Find(Object const&) const;
    Position& FindPosition(Object const&) const;
    void WithDraw(Object&);
  };

  class SortedListAsLinkedList : public virtual SortedList, public virtual ListAsLinkedList
  {
  public:
    SortedListAsLinkedList();
    ~SortedListAsLinkedList();

    void Insert(Object&);
  };
}
///////////////////////////////////////////////////////////////////////////////
#endif //MY_LIST
