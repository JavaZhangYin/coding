#ifndef MY_HEAP
#define MY_HEAP

namespace ADT
{
  class BinaryHeapAsArray : public PriorityQueue
  {
    class Pos;
  private:
    Array<Object*> array;
		
  public:
    BinaryHeapAsArray(unsigned int);
    ~BinaryHeapAsArray();
    //virtual function of PriorityQueue
    void EnQueue(Object&);
    Object& FindMin() const;
    Object& DeQueueMin();
    //virtual function of Container
    void Purge();
    void Accept(Visitor&) const;
    bool IsFull() const;
    Iterator& NewIterator() const;
  protected:
    //virtual function of Object
    int CompareTo(Object const&) const;

    friend class Pos;
  };
  class BinaryHeapAsArray::Pos : public Position
  {
  protected:
    BinaryHeapAsArray const& heap;
    unsigned int nOffset;
  public:
    Pos(BinaryHeapAsArray const&, unsigned int = 1);
    ~Pos();
    void Reset();
    bool IsDone() const;
    Object& operator *() const;
    void operator ++();

    friend class BinaryHeapAsArray;
  };

  /*class BinaryHeapAsBinaryTree : public BinaryTree, public PriorityQueue
    {
    public:
    BinaryHeapAsTree();
    ~BinaryHeapAsTree();
    //virtual function of PriorityQueue
    void EnQueue(Object&);
    Object& FindMin() const;
    Object& DeQueueMin();
    };*/

  class LeftistHeap : public BinaryTree, public MergeablePriorityQueue
  {
  private:
    unsigned int nNullPathLength;
    void SwapContents(LeftistHeap&);
  public:
    LeftistHeap();
    LeftistHeap(Object&);

    LeftistHeap& GetLeft() const;
    LeftistHeap& GetRight() const;

    //virtual function of MergeablePriorityQueue
    void Merge(MergeablePriorityQueue&);

    //virtual funtion of PriorityQueue
    void EnQueue(Object&);
    Object& FindMin() const;
    Object& DeQueueMin();
		
  };

  class BinomialQueue : public MergeablePriorityQueue
  {
  private:
    class Iter;
  private:
    DLinkedList<BinomialTree*> list;

    BinomialTree& FindMinTree() const;
		
    void AddTree(BinomialTree&);
    void RemoveTree(BinomialTree&);

    static BinomialTree* Sum(BinomialTree*, BinomialTree*, BinomialTree*);
    static BinomialTree* Carry(BinomialTree*, BinomialTree*, BinomialTree*);

  public:
    BinomialQueue();
    ~BinomialQueue();

    //virtual funcation of MergeablePriorityQueue
    void Merge(MergeablePriorityQueue&);
    //virtual funcation of PriorityQueue
    void EnQueue(Object&);
    Object& FindMin() const;
    Object& DeQueueMin();
    //virtual funcation of Container
    void Purge();
    void Accept(Visitor&) const;
    Iterator& NewIterator() const;
  protected:
    //virtual funcation of Object
    int CompareTo(Object const&) const;

    friend class Iter;
  };
  ///////////////////////////////////////////////////////////////////////////
  class BinomialQueue::Iter : public Iterator
  {
  private: 
    DLinkedList<BinomialTree*> list;
    Queue& queue;
  public:
    Iter(BinomialQueue const&);
    ~Iter();

    //	virtual function of Iterator	
    void Reset();
    bool IsDone() const;
    Object& operator *() const;
    void operator ++();
  };
}
#endif //MY_HEAP
