#ifndef MY_SET
#define MY_SET

namespace ADT
{
  class Set : public virtual SearchableContainer
  {
  protected:
    unsigned int nUniverseSize;
  public:
    Set(unsigned int);

    typedef Wrapper<unsigned int> Element;
		
    Object& Find(Object const&) const;
  private:
    static Element element;
  };

  class SetAsArray : public Set
  {
  private:
    Array<bool> array;
    class Iter;
  public:
    SetAsArray(unsigned int);
    ~SetAsArray();
    //virtual funcation of SearchableContainer
    bool IsMember(Object const&) const;
    void Insert(Object&);
    void WithDraw(Object&);
    //virtual funcation of Container
    void Purge();
    void Accept(Visitor&) const;
    bool IsFull() const;
    //virtual funcation of Object
    unsigned int GetCount() const;
    int CompareTo(Object const&) const;

    friend SetAsArray operator+(SetAsArray const&, SetAsArray const&);
    friend SetAsArray operator-(SetAsArray const&, SetAsArray const&);
    friend SetAsArray operator*(SetAsArray const&, SetAsArray const&);
    friend bool operator==(SetAsArray const&, SetAsArray const&);
    friend bool operator<=(SetAsArray const&, SetAsArray const&);

    friend class Iter;
  };

  class SetAsArray::Iter : public Iterator
  {
  private:
    SetAsArray const& set;
    unsigned int nOffset;
  public:
    Iter(SetAsArray const&);
    ~Iter();
    //	virtual function of Iterator	
    void Reset();
    bool IsDone() const;
    Object& operator *() const;
    void operator ++();
  };
  
  class SetAsBitVector : public Set
  {
  private:
    typedef unsigned int Word;
    enum Bits{wordBits = sizeof(Word)};
    Array<Word> vector;
  public:
    SetAsBitVector(unsigned int);
    ~SetAsBitVector();
    //virtual funcation of SearchableContainer
    bool IsMember(Object const&) const;
    void Insert(Object&);
    void WithDraw(Object&);
    //virtual funcation of Container
    void Purge();
    void Accept(Visitor&) const;
    bool IsFull() const;
    //virtual funcation of Object
    unsigned int GetCount() const;
    int CompareTo(Object const&) const;

    friend SetAsBitVector operator+(SetAsBitVector const&, SetAsBitVector const&);
    friend SetAsBitVector operator-(SetAsBitVector const&, SetAsBitVector const&);
    friend SetAsBitVector operator*(SetAsBitVector const&, SetAsBitVector const&);
    friend bool operator==(SetAsBitVector const&, SetAsBitVector const&);
    friend bool operator<=(SetAsBitVector const&, SetAsBitVector const&);
  };

  class Multiset : public Set
  {
  public:
    Multiset(unsigned int);
  };

  class MultisetAsArray : public Multiset
  {
  private:
    Array<unsigned int> array;
  public:
    MultisetAsArray(unsigned int);
    //virtual funcation of SearchableContainer
    bool IsMember(Object const&) const;
    void Insert(Object&);
    void WithDraw(Object&);
    Object& Find(Object const&) const;
    //virtual funcation of Container
    void Purge();
    void Accept(Visitor&) const;
    //bool IsFull() const;
    //virtual funcation of Object
    unsigned int GetCount() const;
    int CompareTo(Object const&) const;
		
    friend MultisetAsArray operator+(MultisetAsArray const&, MultisetAsArray const&);
    friend MultisetAsArray operator-(MultisetAsArray const&, MultisetAsArray const&);
    friend MultisetAsArray operator*(MultisetAsArray const&, MultisetAsArray const&);
    friend bool operator==(MultisetAsArray const&, MultisetAsArray const&);
    friend bool operator<=(MultisetAsArray const&, MultisetAsArray const&);
  };

  class MultisetAsLinkedList : public Multiset
  {
  private:
    DLinkedList<unsigned int> list;
  public:
    MultisetAsLinkedList(unsigned int);
    ~MultisetAsLinkedList();
    //virtual funcation of SearchableContainer
    bool IsMember(Object const&) const;
    void Insert(Object&);
    void WithDraw(Object&);
		
    //virtual funcation of Container
    void Purge();
    void Accept(Visitor&) const;
    //bool IsFull() const;
    //virtual funcation of Object
    unsigned int GetCount() const;
    int CompareTo(Object const&) const;
		
    friend MultisetAsLinkedList operator+(MultisetAsLinkedList const&, MultisetAsLinkedList const&);
    friend MultisetAsLinkedList operator-(MultisetAsLinkedList const&, MultisetAsLinkedList const&);
    friend MultisetAsLinkedList operator*(MultisetAsLinkedList const&, MultisetAsLinkedList const&);
    friend bool operator==(MultisetAsLinkedList const&, MultisetAsLinkedList const&);
    friend bool operator<=(MultisetAsLinkedList const&, MultisetAsLinkedList const&);
  };
  /*
    class Partition : public Set
    {
    public:
    Partition (unsigned int n) : Set(n) {}
		
    virtual Set& Find(Object const&) const = 0;
    virtual void Join(Set&, Set&) = 0;
    };

    class ParitionAsForest;
    class PartitionTree : public Set, public Tree
    {
    private:
    unsigned int const nItem;
    PartitionTree* pParent;
    unsigned int nRank;

    PartitionTree(unsigned int, unsigned int);

    public:
    //virtual function of Set
    //virtual function of Tree
    Object& GetKey() const;
    Tree& GetSubTree(unsigned int) const;
    bool IsEmpty() const;
    bool IsLeaf() const;
    unsigned int GetDegree() const;
    //virtual funcation of SearchableContainer
    bool IsMember(Object const&) const;
    void Insert(Object&);
    void WithDraw(Object&);
    //virtual funcation of Container
    void Purge();
    void Accept(Visitor&) const;
    bool IsFull() const;
    //virtual funcation of Object
    unsigned int GetCount() const;
    int CompareTo(Object const&) const;

    friend class ParitionAsForest;
    };

    class PartitionAsForest : public Partition
    {
    private:
    Array<PartitionTree*> array;
    void CheckArguments(PartitionTree const&, PartitionTree const&);

    }

  */
  extern SetAsArray operator+(SetAsArray const&, SetAsArray const&);
  extern SetAsArray operator-(SetAsArray const&, SetAsArray const&);
  extern SetAsArray operator*(SetAsArray const&, SetAsArray const&);
  extern bool operator==(SetAsArray const&, SetAsArray const&);
  extern bool operator<=(SetAsArray const&, SetAsArray const&);

  extern SetAsBitVector operator+(SetAsBitVector const&, SetAsBitVector const&);
  extern SetAsBitVector operator-(SetAsBitVector const&, SetAsBitVector const&);
  extern SetAsBitVector operator*(SetAsBitVector const&, SetAsBitVector const&);
  extern bool operator==(SetAsBitVector const&, SetAsBitVector const&);
  extern bool operator<=(SetAsBitVector const&, SetAsBitVector const&);

  extern MultisetAsArray operator+(MultisetAsArray const&, MultisetAsArray const&);
  extern MultisetAsArray operator-(MultisetAsArray const&, MultisetAsArray const&);
  extern MultisetAsArray operator*(MultisetAsArray const&, MultisetAsArray const&);
  extern bool operator==(MultisetAsArray const&, MultisetAsArray const&);
  extern bool operator<=(MultisetAsArray const&, MultisetAsArray const&);

  extern MultisetAsLinkedList operator+(MultisetAsLinkedList const&, MultisetAsLinkedList const&);
  extern MultisetAsLinkedList operator-(MultisetAsLinkedList const&, MultisetAsLinkedList const&);
  extern MultisetAsLinkedList operator*(MultisetAsLinkedList const&, MultisetAsLinkedList const&);
  extern bool operator==(MultisetAsLinkedList const&, MultisetAsLinkedList const&);
  extern bool operator<=(MultisetAsLinkedList const&, MultisetAsLinkedList const&);

}
#endif//MY_SET
