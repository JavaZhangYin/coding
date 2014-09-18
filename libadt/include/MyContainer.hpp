#ifndef MY_CONTAINER
#define MY_CONTAINER

namespace ADT
{
  /**
   *\brief define of class Visitor, an abstract class 
   */
  class Visitor
  {
  public:
    /**
     *\brief is called by container's Accept function, for each object of container's
     *\param obj reference object of container's object
     *\return void
     */
    virtual void Visit(Object&) = 0;
    /**
     *\brief check visit has finished or not
     *\param void
     *\return ture if done else false
     */
    virtual bool IsDone() const;
  };

  /**
   *\brief define of class Iterator, an abstract class
   */
  class Iterator
  {
  public:
    /**
     *\brief default destruct function
     *\param void
     *\return void
     */
    virtual ~Iterator();
    /**
     *\brief reset the iterator to the beginning position 
     *\param void
     *\return void
     */
    virtual void Reset() = 0;
    /**
     *\brief check iterator has finished or not
     *\param void
     *\return true if done else false 
     */
    virtual bool IsDone() const = 0;
    /**
     *\brief get the current position's object
     *param void
     *return object of current position
     */
    virtual Object& operator *() const = 0;
    /**
     *\brief step the position of object to the next
     *param void
     *return void
     */
    virtual void operator ++() = 0;
  };

  /**
   *\brief define of class Container, an abstract class
   */
  class Container : public virtual Object, public virtual Ownership
  {
  protected:
    /* Number of container objects. */
    unsigned int nCount;
    /**
     *\brief default construct function
     *param void
     *return void
     */
    Container();
  public:
    /**
     *\brief get the counts of container's objects
     *\param void
     *\return counts of container's objects
     */
    virtual unsigned int GetCount() const;
    /**
     *brief check the container if is empty
     *param void
     *return true if empty else false
     */
    virtual bool IsEmpty() const;
    /**
     *brief check the container if is full
     *param void
     *return true if full else false
     */
    virtual bool IsFull() const;
    /**
     *brief hash function of the container object
     *param void
     *return hash value of the container object
     */
    virtual HashValue Hash() const;
    /**
     *\brief output the container to the out stream
     *\param reference of out stream 
     *\return void
     */
    virtual void Put(ostream&) const;
    /**
     *\brief create iterator for iterate constainer's object
     *\param void
     *\return iterator object
     */
    virtual Iterator& NewIterator() const;
    /**
     *\breif purge all objects of constainer
     *param void
     *return void
     */
    virtual void Purge() = 0;
    /**
     *\brief visit all objects of container by visitor
     *\param reference of visitor
     *\return void
     */
    virtual void Accept(Visitor&) const = 0;
  };

  /**
   * \class Position.
   * \brief hold the position of and Iterator Object.
   */
  class Position : public Iterator
  {};

  /**
   * \class NullIterator
   * \brief A special Iterator class aims to keep of consistency of code but actually do nothing.
   */
  class NullIterator : public Iterator
  {
  public:
    NullIterator();
    void Reset();
    bool IsDone() const;
    Object& operator *() const;
    void operator ++();
  };

  /**
   * \class PuttingVisitor
   * \brief To be added.
   */
  class PuttingVisitor : public Visitor
  {
    ostream& stream;
    bool fComma;
  public:
    PuttingVisitor(ostream&);
    void Visit(Object&);
  };

  /**
   * \class SearchableContainer
   * \brief Searchable class. This class defines some virtual methods for member operations.
   */
  class SearchableContainer : public virtual Container
  {
  public:
    virtual bool IsMember(Object const&) const = 0;
    virtual void Insert(Object&) = 0;
    virtual void WithDraw(Object&) = 0;
    virtual Object& Find(Object const&) const = 0;
  };

  /**
   * \class HashingVisitor
   * \brief To be added.
   */
  class HashingVisitor : public Visitor
  {
  private:
    HashValue value;
  public:
    HashingVisitor(HashValue);
    ~HashingVisitor();

    void Visit(Object& object);
    HashValue GetValue() const;
  };

  /**
   * \class PrePostVisitor
   * \brief To be added.
   */
  class PrePostVisitor : public Visitor
  {
  public:
    virtual void PreVisit(Object&);
    virtual void Visit(Object&);
    virtual void PostVisit(Object&);
  };

  /**
   * \class PreOrder
   * \brief To be added.
   */
  class PreOrder : public PrePostVisitor
  {
  private:
    Visitor& visitor;
  public:
    PreOrder(Visitor&);

    void PreVisit(Object&);
  };

  /**
   * \class InOrder
   * \brief To be added.
   */
  class InOrder : public PrePostVisitor
  {
  private:
    Visitor& visitor;
  public:
    InOrder(Visitor&);

    void Visit(Object&);
  };

  /**
   * \class PostOrder
   * \brief To be added.
   */
  class PostOrder : public PrePostVisitor
  {
  private:
    Visitor& visitor;
  public:
    PostOrder(Visitor&);

    void PostVisit(Object&);
  };

}
#endif /*MY_CONTAINER*/
