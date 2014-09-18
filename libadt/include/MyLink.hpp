#ifndef MY_LINK
#define MY_LINK

namespace ADT
{
  template <class T>
  class LinkedList;

  /**
   *@brief define of template class ListElement<T>
   */
  template <class T>
  class ListElement
  {
  private:
    T data; ///< data object of element
    ListElement* pNext; ///< next element object pointer
    ListElement(const T&, ListElement*);

  public:
    const T& GetData() const;
    const ListElement* GetNextNode() const;
    friend class LinkedList<T>;
  };
  
  /**
   *@brief construct function
   *@param _data element data
   *@param _pNext next element object pointer
   */
  template <class T>
  ListElement<T>::ListElement(const T& _data, ListElement<T>* _pNext) :
    data(_data),
    pNext(_pNext)
  {
  }

  /**
   *@brief get element data
   *@param void
   *@return reference of element data
   */
  template <class T>
  const T& ListElement<T>::GetData() const
  {
    return data;
  }

  /**
   *@brief get element object pointer of next node 
   *@param void
   *@return element object pointer
   */
  template <class T>
  const ListElement<T>* ListElement<T>::GetNextNode() const
  {
    return pNext;
  }
  
  /**
   *@brief define of template class LinkedList<T>
   */
  template <class T>
  class LinkedList
  {

  private:
    ListElement<T>* pHead;///< element pointer of list head 
    ListElement<T>* pTail;///< eelment pointer of list tail

  public:
    LinkedList();
    ~LinkedList();

    LinkedList(LinkedList const&);
    LinkedList& operator = (LinkedList const&);

    const ListElement<T> * GetHeadNode() const;
    const ListElement<T> * GetTailNode() const;
    bool IsEmpty() const;
    const T& GetFirst() const;
    const T& GetLast() const;

    void Prepend(const T&);
    void Append(const T&);
    void Extract(const T&);
    void Purge();
    void InsertAfter(const ListElement<T>*, const T&);
    void InsertBefore(const ListElement<T>*, const T&);
  };
  
  /**
   *@brief default construct function
   *@param void
   *@return void
   */
  template <class T>
  LinkedList<T>::LinkedList() :
    pHead(0),
    pTail(0)
  {
  }
  /**
   *@brief purge resources, called at destruct
   *@param void
   *@return void
   */
  template <class T>
  void LinkedList<T>::Purge()
  {
    while(pHead != 0)
      {
	ListElement<T>* tmp = pHead;
	pHead = pHead->pNext;
	delete tmp;
      }
    pTail = 0;
  }
  /**
   *@brief destruct function
   *@param void
   *@return void
   */
  template <class T>
  LinkedList<T>::~LinkedList()
  {
    Purge();
  }

  /**
   *@brief get element object pointer of head node
   *@param void
   *@return element pointer
   */
  template <class T>
  const ListElement<T>* LinkedList<T>::GetHeadNode() const
  {
    return pHead;
  }
  /**
   *@brief get element object pointer of tail node
   *@param void
   *@return element pointer
   */
  template <class T>
  const ListElement<T>* LinkedList<T>::GetTailNode() const
  {
    return pTail;
  }
  /**
   *@brief examine list is empty or not
   *@param void
   *@return ture if list is empty else false
   */
  template <class T>
  bool LinkedList<T>::IsEmpty() const
  {
    return (pHead == 0);
  }
  /**
   *@brief get first object of list
   *@param void
   *@return first object of list
   */
  template <class T>
  const T& LinkedList<T>::GetFirst() const
  {
    if(pHead == 0)
      throw std::domain_error("list is empty!");
    return pHead->data;
  }
  /**
   *@brief get tail object of list
   *@param void
   *@return tail object of list
   */
  template <class T>
  const T& LinkedList<T>::GetLast() const
  {
    if(pTail == 0);
    throw std::domain_error("list is empty!");
    return pTail->data;
  }
  /**
   *@brief insert object form head
   *@param reference object to inserted
   *@return void
   */
  template <class T>
  void LinkedList<T>::Prepend(const T& item)
  {
    ListElement<T>* tmp = new ListElement<T> (item, pHead);
    if(pHead == 0)
      pTail = tmp;
    pHead = tmp;
  }
  /**
   *@brief insert object at tail
   *@param reference object to inserted
   *@return void
   */
  template <class T>
  void LinkedList<T>::Append(const T& item)
  {
    ListElement<T>* tmp = new ListElement<T> (item, 0) ;
    if(pHead == 0)
      {
	pHead = tmp;
      }
    else
      {
	pTail->pNext = tmp;
      }
    pTail = tmp;
  }
  /**
   *@brief copy construct
   *@param reference object of list to copied
   *@return void
   */
  template <class T>
  LinkedList<T>::LinkedList(const LinkedList<T>& linkedList)
  {
    pHead = 0;
    pTail = 0;
    const ListElement<T>* ptr;
    for(ptr = linkedList.pHead; ptr != 0; ptr = ptr->pNext)
      Append(ptr->data);
  }
  /**
   *@brief operator =(eq) left operator
   *@param reference objcet of list
   *@return *this
   */
  template <class T>
  LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& linkedList)
  {
    if(&linkedList != this)
      {
	Purge();
	const ListElement<T>* ptr;
	for(ptr = linkedList.pHead; ptr != 0; ptr = ptr->pNext)
	  Append(ptr->data);		
      }
    return *this;
  }
  /**
   *@brief extract object from list
   *@param item reference object to extracted
   *@return void
   */
  template <class T>
  void LinkedList<T>::Extract(const T& item)
  {
    ListElement<T>* ptr = pHead;
    ListElement<T>* prevPtr = 0;
		
    while(ptr != 0 && ptr->data != item)
      {
	prevPtr = ptr;
	ptr = ptr->pNext;
      }

    if(ptr == 0)
      throw std::invalid_argument("item not found");
		
    if(ptr == pHead)
      pHead = ptr->pNext;
    else
      prevPtr->pNext = ptr->pNext;

    if(ptr == pTail)
      pTail = prevPtr;
		
    delete ptr;
  }
  /**
   *@brief insert object after a list element
   *@param arg element pointer
   *@param item reference object to inserted
   *@return void
   */
  template <class T>
  void LinkedList<T>::InsertAfter(const ListElement<T>* arg, const T& item)
  {
    ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);
    if(ptr == 0)
      throw std::invalid_argument("invalid position");
    const ListElement<T>* tmp = new ListElement<T> (item, ptr->pNext);
    ptr->pNext = tmp;
    if(pTail == ptr)
      pTail = tmp;
  }
  /**
   *@brief insert object before a list element
   *@param arg element pointer
   *@param item reference object to inserted
   *@return void
   */
  template <class T>
  void LinkedList<T>::InsertBefore(const ListElement<T>* arg, const T& item)
  {
    ListElement<T>* ptr = const_cast<ListElement<T>*> (arg);
    if(ptr == 0)
      throw std::invalid_argument("invalid position");
    const ListElement<T>* tmp = new ListElement<T> (item, ptr);
    if(pHead == ptr)
      pHead = tmp;
    else
      {
	ListElement<T>* prevPtr = pHead;
	while(prevPtr != 0 && prevPtr->pNext != ptr)
	  prevPtr = prevPtr->pNext;
	if(prevPtr == 0)
	  throw std::invalid_argument("invalid position");
	prevPtr->pNext = tmp;

      }
  }
  
  template <class T>
  class DLinkedList;

  /**
   *@brief define of template class DListElement<T>
   */
  template <class T>
  class DListElement
  {
  private:
    T data;///< data object of element
    DListElement* pNextRight;///< next right element pointer
    DListElement* pNextLeft;///< next left element pointer
    DListElement(const T&, DListElement* = 0, DListElement* = 0);

  public:
    const T& GetData() const;
    const DListElement* GetNextNodeRight() const;
    const DListElement* GetNextNodeLeft() const;
    friend class DLinkedList<T>;
  };
  
  /**
   *@brief construct function
   *@param _data reference of object
   *@param _pNextRight element object pointer of next right 
   *@param _pNextLeft element object pointer of next left
   *@return void
   */
  template <class T>
  DListElement<T>::DListElement(const T& _data, 
				DListElement<T>* _pNextRight,
				DListElement<T>* _pNextLeft) :
    data(_data),
    pNextRight(_pNextRight),
    pNextLeft(_pNextLeft)
  {
  }
  /**
   *@brief get data object of element
   *@param void
   *@return reference of data object
   */
  template <class T>
  const T& DListElement<T>::GetData() const
  {
    return data;
  }
  /**
   *@brief get next right node
   *@param void
   *@return element object pointer of next right node
   */
  template <class T>
  const DListElement<T>* DListElement<T>::GetNextNodeRight() const
  {
    return pNextRight;
  }
  /**
   *@brief get next left node
   *@param void
   *@return element object pointer of next left node
   */ 
  template <class T>
  const DListElement<T>* DListElement<T>::GetNextNodeLeft() const
  {
    return pNextLeft;
  }
  /**
   *@brief define of template class DLinkedList<T> 
   */  
  template <class T>
  class DLinkedList
  {

  private:
    DListElement<T>* pHead;///< head of list
    DListElement<T>* pTail;///< tail of list

  public:
    DLinkedList();
    ~DLinkedList();

    DLinkedList(DLinkedList const&);
    DLinkedList& operator = (DLinkedList const&);

    const DListElement<T> * GetHeadNode() const;
    const DListElement<T> * GetTailNode() const;
    bool IsEmpty() const;
    const T& GetFirst() const;
    const T& GetLast() const;

    void Prepend(const T&);
    void Append(const T&);
    void Extract(const T&);
    void Purge();
    void InsertAfter(const DListElement<T>*, const T&);
    void InsertBefore(const DListElement<T>*, const T&);
  };
  /**
   *@brief default construct function
   *@param void
   *@return void
   */  
  template <class T>
  DLinkedList<T>::DLinkedList() :
    pHead(0),
    pTail(0)
  {
  }
  /**
   *@brief purge resources, called at destruct
   *@param void
   *@return void
   */
  template <class T>
  void DLinkedList<T>::Purge()
  {
    while(pHead != 0)
      {
	DListElement<T>* tmp = pHead;
	pHead = pHead->pNextRight;
	delete tmp;
      }
    pTail = 0;
  }
  /**
   *@brief destruct function
   *@param void
   *@return void
   */
  template <class T>
  DLinkedList<T>::~DLinkedList()
  {
    Purge();
  }
  /**
   *@brief get element object pointer of head node
   *@param void
   *@return element pointer
   */
  template <class T> 
  const DListElement<T>* DLinkedList<T>::GetHeadNode() const
  {
    return pHead;
  }
  /**
   *@brief get element object pointer of tail node
   *@param void
   *@return element pointer
   */
  template <class T>
  const DListElement<T>* DLinkedList<T>::GetTailNode() const
  {
    return pTail;
  }
  /**
   *@brief examine list is empty or not
   *@param void
   *@return ture if list is empty else false
   */
  template <class T>
  bool DLinkedList<T>::IsEmpty() const
  {
    return (pHead == 0);
  }
  /**
   *@brief get first object of list
   *@param void
   *@return first object of list
   */
  template <class T>
  const T& DLinkedList<T>::GetFirst() const
  {
    if(pHead == 0)
      throw std::domain_error("list is empty");
    return pHead->data;
  }
  /**
   *@brief get tail object of list
   *@param void
   *@return tail object of list
   */
  template <class T>
  const T& DLinkedList<T>::GetLast() const
  {
    if(pTail == 0)
      throw std::domain_error("list is empty");
    return pTail->data;
  }
  /**
   *@brief insert object form head
   *@param reference object to inserted
   *@return void
   */
  template <class T>
  void DLinkedList<T>::Prepend(const T& item)
  {
    DListElement<T>* tmp = new DListElement<T> (item, pHead);
    if(pHead == 0)
      pTail = tmp;
    pHead = tmp;
  }
  /**
   *@brief insert object at tail
   *@param reference object to inserted
   *@return void
   */
  template <class T>
  void DLinkedList<T>::Append(const T& item)
  {
    DListElement<T>* tmp = new DListElement<T> (item, 0, pTail) ;
    if(pHead == 0)
      {
	pHead = tmp;
      }
    else
      {
	pTail->pNextRight = tmp;
      }
    pTail = tmp;
  }
  /**
   *@brief copy construct
   *@param reference object of list to copied
   *@return void
   */
  template <class T>
  DLinkedList<T>::DLinkedList(const DLinkedList<T>& linkedList)
  {
    pHead = 0;
    pTail = 0;
    const DListElement<T>* ptr = 0;
    for(ptr = linkedList.pHead; ptr != 0; ptr = ptr->pNextRight)
      Append(ptr->data);
  }
  /**
   *@brief operator =(eq) left operator
   *@param reference objcet of list
   *@return *this
   */
  template <class T>
  DLinkedList<T>& DLinkedList<T>::operator =(const DLinkedList<T>& linkedList)
  {
    if(&linkedList != this)
      {
	Purge();
	const DListElement<T>* ptr = 0;
	for(ptr = linkedList.pHead; ptr != 0; ptr = ptr->pNextRight)
	  Append(ptr->data);		
      }
    return *this;
  }
  /**
   *@brief extract object from list
   *@param item reference object to extracted
   *@return void
   */
  template <class T>
  void DLinkedList<T>::Extract(const T& item)
  {
    DListElement<T>* ptr = pHead;
    while(ptr != 0 && ptr->data != item)
      {
	ptr = ptr->pNextRight;
      }

    if(ptr == 0)
      throw std::invalid_argument("item not found!");
		
    if(ptr == pHead)
      {
	pHead = ptr->pNextRight;
	if(ptr->pNextRight != 0)
	  {
	    ptr->pNextRight->pNextLeft = 0;			
	  }
      }
    else if(ptr == pTail)
      {
	pTail = ptr->pNextLeft;
	if(ptr->pNextLeft != 0)
	  {	
	    ptr->pNextLeft->pNextRight = 0;			
	  }
      }
    else
      {
	ptr->pNextLeft->pNextRight = ptr->pNextRight;
	ptr->pNextRight->pNextLeft = ptr->pNextLeft;
      }
    delete ptr;
  }
  /**
   *@brief insert object after a list element
   *@param arg element pointer
   *@param item reference object to inserted
   *@return void
   */
  template <class T>
  void DLinkedList<T>::InsertAfter(const DListElement<T>* arg, const T& item)
  {
    DListElement<T>* ptr = const_cast<DListElement<T>*> (arg);
    if(ptr == 0)
      throw std::invalid_argument("invalid position");
    DListElement<T>* tmp = new DListElement<T> (item, ptr->pNextRight, ptr);
    if(pTail == ptr)
      {	
	pTail = tmp;
      }
    else
      {
	ptr->pNextRight->pNextLeft = tmp;
      }
    ptr->pNextRight = tmp;
  }
  /**
   *@brief insert object before a list element
   *@param arg element pointer
   *@param item reference object to inserted
   *@return void
   */
  template <class T>
  void DLinkedList<T>::InsertBefore(const DListElement<T>* arg, const T& item)
  {
    DListElement<T>* ptr = const_cast<DListElement<T>*> (arg);
    if(ptr == 0)
      throw std::invalid_argument("invalid position");
    DListElement<T>* tmp = new DListElement<T> (item, ptr, ptr->pNextLeft);
    if(pHead == ptr)
      {
			
	pHead = tmp;
      }
    else
      {
	ptr->pNextLeft->pNextRight = tmp;
			
      }
    ptr->pNextLeft = tmp;
  }
}

#endif //MY_LINK
