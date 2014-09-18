#ifndef MY_HASHTSBLE
#define MY_HASHTABLE

namespace ADT
{
  /* Default hash table size. */
  static unsigned int  DEFAULT_HASHTABLE_SIZE = 10001;
  /**
   * \class HashTable
   * \brief To be Added.
   */
  class HashTable : public virtual SearchableContainer
    {
    protected:
      unsigned int nLength;
    public:
      HashTable(unsigned int);
      virtual unsigned int H(Object const&) const;
    };
  
  /**
   * \class ChainerHashTable
   * \brief To be Added.
   */
    class ChainedHashTable : public HashTable
      {
      private:
	typedef DLinkedList<Object*> ObjectLinkList;
		
	class Iter : public Iterator
	  {
	  private:
	    Array<ObjectLinkList> array;
	    Queue& queue;
	    unsigned int nOffset;
	  public:
	    Iter(ChainedHashTable const&);
	    ~Iter();

	    //	virtual function of Iterator	
	    void Reset();
	    bool IsDone() const;
	    Object& operator *() const;
	    void operator ++();
	  };
	       	
	Array<ObjectLinkList> array;
      public:
	ChainedHashTable(unsigned int);
	~ChainedHashTable();

	// virtual function of SearchableContainer
	bool IsMember(Object const&) const;
	void Insert(Object&);
	void WithDraw(Object&);
	Object& Find(Object const&) const;

	// virtual function of Container	
	void Purge();
	void Accept(Visitor&) const;
	Iterator& NewIterator() const;

	// virtual function of Object
	int CompareTo(Object const&) const;
		
	friend class Iter;
      };
    class ChainedScatterTable : public HashTable
      {
	class Entry
	  {
	  public:
	    enum State {null = ~0U};
	    Object* pObject;
	    unsigned int nNext;

	    Entry();
	    ~Entry();
	  };
	class Iter : public Iterator
	  {
	  private:
	    ChainedScatterTable const& chainedScatterTable;
	    unsigned int nOffset;
	  public:
	    Iter(ChainedScatterTable const&);
	    ~Iter();

	    //	virtual function of Iterator	
	    void Reset();
	    bool IsDone() const;
	    Object& operator *() const;
	    void operator ++();
	  };
	Array<Entry> array;

      public:
	ChainedScatterTable(unsigned int = DEFAULT_HASHTABLE_SIZE);
	~ChainedScatterTable();

	//	virtual function of SearchableContainer
	bool IsMember(Object const&) const;
	void Insert(Object&);
	void WithDraw(Object&);
	Object& Find(Object const&) const;

	//	virtual function of Container	
	void Purge();
	void Accept(Visitor&) const;
	Iterator& NewIterator() const;

	//	virtual function of Object
	int CompareTo(Object const&) const;
		
	friend class Iter;
      };
    /////////////////////////////////////////////////////////////////////////////////////
      class OpenScatterTable : public HashTable
	{
	private:
	  class Entry
	    {
	    public:
	      enum State {empty, occupied, deleted};
	      State state;
	      Object* pObject;

	      Entry();
	      ~Entry();
	    };
	  class Iter : public Iterator
	    {
	    private:
	      OpenScatterTable const& openScatterTable;
	      unsigned int nOffset;
	    public:
	      Iter(OpenScatterTable const&);
	      ~Iter();

	      //	virtual function of Iterator	
	      void Reset();
	      bool IsDone() const;
	      Object& operator *() const;
	      void operator ++();
	    };
	  Array<Entry> array;

	  unsigned int C(unsigned int) const;
	  unsigned int FindMatch(Object const&) const;
	  unsigned int FindInstance(Object const&) const;
	  unsigned int FindUnoccupied(Object const&) const;

	public:
	  OpenScatterTable(unsigned int = DEFAULT_HASHTABLE_SIZE);
	  ~OpenScatterTable();

	  //	virtual function of SearchableContainer
	  bool IsMember(Object const&) const;
	  void Insert(Object&);
	  void WithDraw(Object&);
	  Object& Find(Object const&) const;

	  //	virtual function of Container	
	  void Purge();
	  void Accept(Visitor&) const;
	  Iterator& NewIterator() const;
		
	  //	virtual function of Object
	  int CompareTo(Object const&) const;	
	  friend class Iter;
	};
}
/////////////////////////////////////////////////////////////////////////////////////
#endif //MY_HASHTABLE
