#ifndef MY_ASSOCIATION
#define MY_ASSOCIATION

//////////////////////////////////////////////////////////////////////////
namespace ADT
{
  /**
   *\brief define of class association 
   */
  class Association : public Object, public Ownership
  {
  protected:
    Object* key;///< key of association
    Object* value;///< value of association

    /**
     *\brief compare association with self
     *\param obj const reference of association object
     *\return 0 If two compared associations are equal.
     *\return -1 If left one is smaller. 
     *\return 1 If left one is bigger.
     */
    int CompareTo(Object const& obj) const;
  public:
    /**
     *\brief construct function
     *\param key reference of association's key
     *\return void
     */
    Association(Object& key);
    /**
     *\brief construct function
     *\param key reference of association's key
     *\param value reference of association's value
     *\return void
     */
    Association(Object&, Object&);
    /**
     *\brief destruct funxtion
     *\param void
     *\return void
     */
    ~Association();

    /**
     *\brief get key of association
     *\param void
     *\return reference of key object
     */
    Object& GetKey() const;
    /**
     *\brief get value of association
     *\param void
     *\return reference of value object
     */
    Object& GetValue() const;
    /**
     *\brief hash function
     *\param void
     *\return hash value of association
     */
    HashValue Hash() const;
    /**
     *\brief put object to out stream
     *\param s out stream
     *\return void
     */
    void Put(ostream& s) const;
  };
}
#endif
