#ifndef MY_TREE
#define MY_TREE

namespace ADT
{
  class PrePostVisitor;
  //////////////////////////////////////////////////////////////////////////
  class Tree : public virtual Container
  {
  private:
    class Iter;
  public:
    virtual Object& GetKey() const = 0;
    virtual Tree& GetSubTree(unsigned int) const = 0;
    virtual bool IsEmpty() const = 0;
    virtual bool IsLeaf() const = 0;
    virtual unsigned int GetDegree() const = 0;
		
    virtual int GetHeight() const;
    virtual void DepthFirstTraversal(PrePostVisitor&) const;
    virtual void BreadthFirstTraversal(Visitor&) const;
    void Accept(Visitor&) const;

    // virtual function of Container
    unsigned int GetCount() const;
    Iterator& NewIterator() const;
  };

  class Tree::Iter : public Iterator
  {
  private:
    Tree const& tree;
    Stack& stack;
  public:
    Iter(Tree const&);
    ~Iter();
    //	virtual function of Iterator	
    void Reset();
    bool IsDone() const;
    Object& operator *() const;
    void operator ++();
  };

  ///////////////////////////////////////////////////////////////////////////
  class GeneralTree : public Tree
  {
  protected:
    Object* pObjKey;
    unsigned int nDegree;
    DLinkedList<GeneralTree*> list;
  public:
    GeneralTree(Object&);
    ~GeneralTree();

    virtual void AttachSubTree(GeneralTree&);
    virtual GeneralTree& DetachSubTree(GeneralTree&);

    //	virtual function of Tree
    Object& GetKey() const;
    GeneralTree& GetSubTree(unsigned int) const;
    bool IsEmpty() const;
    bool IsLeaf() const;
    unsigned int GetDegree() const;
		
    //	virtual function of Container
    void Purge();
    //	void Accept(Visitor&) const;

    //	virtual function of Object
    int CompareTo(Object const&) const;
  };

  ///////////////////////////////////////////////////////////////////////////
  class NaryTree : public Tree
  {
  protected:
    Object* pObjKey;
    unsigned int const nDegree;
    Array<NaryTree*> arraySubTree;
  public:
    NaryTree(unsigned int);
    NaryTree(unsigned int, Object&);
    ~NaryTree();

    Object& GetKey() const;
    NaryTree& GetSubTree(unsigned int) const;
    virtual void AttachKey(Object&);
    virtual Object& DetachKey();
    virtual void AttachSubTree(unsigned int, NaryTree&);
    virtual NaryTree& DetachSubTree(unsigned int);
	
    //	virtual function of Tree
    bool IsEmpty() const;
    bool IsLeaf() const;
    unsigned int GetDegree() const;
		
    //	virtual function of Container
    void Purge();
    //	void Accept(Visitor&) const;

    //	virtual function of Object
    int CompareTo(Object const&) const;


  };
  ///////////////////////////////////////////////////////////////////////////
  class BinaryTree : public virtual Tree
  {
  protected:
    Object* pObjKey;
    BinaryTree* pBinaryTreeLeft;
    BinaryTree* pBinaryTreeRight;
  public:
    BinaryTree();
    BinaryTree(Object&);
    ~BinaryTree();
		
    Object& GetKey() const;
    virtual void AttachKey(Object&);
    virtual Object& DetachKey();
    virtual BinaryTree& GetLeft() const;
    virtual BinaryTree& GetRight() const;
    virtual void AttachLeft(BinaryTree&);
    virtual void AttachRight(BinaryTree&);
    virtual BinaryTree& DetachLeft();
    virtual BinaryTree& DetachRight();
    //	virtual function of Tree
    void DepthFirstTraversal(PrePostVisitor& visitor) const;
    Tree& GetSubTree(unsigned int) const;
    bool IsEmpty() const;
    bool IsLeaf() const;
    unsigned int GetDegree() const;
		
    //	virtual function of Container
    void Purge();
    //	void Accept(Visitor&) const;

    //	virtual function of Object
    int CompareTo(Object const&) const;

  };
  ///////////////////////////////////////////////////////////////////////////
  class SearchTree : public virtual Tree, public virtual SearchableContainer
  {
  public:
    virtual Object& FindMin() const = 0;
    virtual Object& FindMax() const = 0;
  };
  ///////////////////////////////////////////////////////////////////////////
  class BST : public BinaryTree, public SearchTree
  {
  protected:
    virtual void Balance();
    //	virtual function of BinaryTree
    virtual void AttachKey(Object&);
    virtual Object& DetachKey();
		
  public:		
    //	virtual function of SearchTree	
    Object& FindMin() const;
    Object& FindMax() const;
    //	virtual function of BinaryTree
    BST& GetLeft() const;
    BST& GetRight() const;
    //	virtual function of SearchableContainer
    void Insert(Object&);
    void WithDraw(Object&);
    bool IsMember(Object const&) const;
    Object& Find(Object const&) const;
  };
  ///////////////////////////////////////////////////////////////////////////
  class AVLTree : public BST
  {
  protected:
    int iHeight;

    int BalanceFactor() const;
    void AdjustHeight();
    void LLRotation();
    void LRRotation();
    void RRRotation();
    void RLRotation();
    void AttachKey(Object&);
    Object& DetachKey();
    void Balance();
  public:
    AVLTree();

    int GetHeight() const;
    AVLTree& GetLeft() const;
    AVLTree& GetRight() const;
  };
  ///////////////////////////////////////////////////////////////////////////
  class MWayTree : public SearchTree
  {
  private:
    class Iter;
  protected:
    unsigned int const nWay;
    unsigned int nNumberOfKeys;
    Array<Object*> arrayKey;
    Array<MWayTree*> arraySubTree;

    unsigned int FindIndex(Object const&) const;
  public:
    MWayTree(unsigned int);
    ~MWayTree();
    Object& GetKey(unsigned int) const;
    //	virtual function of Tree
		
    Object& GetKey() const;
    Tree& GetSubTree(unsigned int) const;
    bool IsEmpty() const;
    bool IsLeaf() const;
    unsigned int GetDegree() const;
    Iterator& NewIterator() const;
		
    void DepthFirstTraversal(PrePostVisitor&) const;
    void BreadthFirstTraversal(Visitor& visitor) const;
    //	virtual function of SearchTree	
    Object& FindMin() const;
    Object& FindMax() const;
    //	virtual function of Container
    void Purge();
    //	virtual function of SearchableContainer
    void Insert(Object&);
    void WithDraw(Object&);
    bool IsMember(Object const&) const;
    Object& Find(Object const&) const;
    //	virtual function of Object
    int CompareTo(Object const&) const;
  };
  ///////////////////////////////////////////////////////////////////////////
  class MWayTree::Iter : public Iterator
  {
  private:
    MWayTree const& tree;
    Stack& stack;
    Queue& queue;
  public:
    Iter(MWayTree const&);
    ~Iter();
    //	virtual function of Iterator	
    void Reset();
    bool IsDone() const;
    Object& operator *() const;
    void operator ++();
  };
  ///////////////////////////////////////////////////////////////////////////
  class BTree : public MWayTree
  {
  private:
    BTree* pBTreeParent;

    void InsertPair(Object&, BTree&);
    void AttachKey(unsigned int, Object&);
    void AttachSubTree(unsigned int, MWayTree&);
    Object& InsertKey(unsigned int, Object&);
    BTree& InsertSubTree(unsigned int, BTree&);
    void AttachLeftHalfOf(BTree const&);
    void AttachRightHalfOf(BTree const&, Object&, BTree&);

    Object& DetachKey(unsigned int);
    BTree&  DetachSubTree(unsigned int);

    Object& DeleteKey(unsigned int nIndex);
    BTree&  DeleteSubTree(unsigned int nIndex);

    void LLRotation(unsigned int);
    void RRRotation(unsigned int);
    void Coalition(unsigned int);

    void Balance(unsigned int);
  public:
    BTree(unsigned int);
    BTree(unsigned int, BTree&);

    void Insert(Object&);
    void WithDraw(Object&);
  };
  ///////////////////////////////////////////////////////////////////////////
  class BinomialTree : public GeneralTree
  {
  private:
    void SwapContents(BinomialTree&);
  public:
    BinomialTree(Object&);
    void Add(BinomialTree&);
    BinomialTree& GetSubTree(unsigned int) const;
  };
  ///////////////////////////////////////////////////////////////////////////
}
#endif /*My_TREE*/
