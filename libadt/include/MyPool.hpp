#ifndef MY_POOL
#define MY_POOL

#pragma pack (push, 1)

#define MYSIZE (sizeof(int*) * 4)

namespace ADT
{
  class StoragePool
  {
  public:
    virtual ~StoragePool();
    virtual void* Acquire(size_t) = 0;
    virtual void Release(void*) = 0;
  };
  
  
  struct Tag
  {
    StoragePool* pPool;
  };

  class SinglyLinkedPool : public StoragePool
  {
  public:
    struct Header
    {
      unsigned int nLength;
    };
    struct Block : public Header
    {
      enum {size = MYSIZE};
      union
      {
	Block *pNext;
	char szUserPart[size - sizeof(Header)];
      };
    };
  private:
    unsigned int nNumberOfBlocks;
    Block *pPool;
    Block& sentinel;
  public:
    SinglyLinkedPool(size_t);
    ~SinglyLinkedPool();

    void* Acquire(size_t);
    void Release(void*);
  }; 

  class DoublyLinkedPool : public StoragePool
  {
  public:
    enum PoolStatus{free, reserved};
    
    struct Header
    {
      PoolStatus status : 1;
      unsigned int nLength : sizeof (unsigned int) * BITSOFBYTE - 1U;
    };

    struct Block : public Header
    {
      enum {size = MYSIZE};
      
      struct Links
      {
	Block *pNext;
	Block *pPrev; 
      };
      
      union
      {
	Links link;
	char szUserPart[size - sizeof(Header)];
      };
    };
    
  private:
    unsigned int nNumberOfBlocks;
    Block *pPool;
    Block &sentinel;

    static void Unlink(Block&);
    static void InsertAfter(Block&, Block&);
  public:
    DoublyLinkedPool(size_t);
    ~DoublyLinkedPool();

    void* Acquire(size_t);
    void Release(void*);
  };
  //////////////////////////////////////////////////////////////////////////////
  
  class BuddyPool : public StoragePool
  {
  public:
    enum PoolStatus{free, reserved};


    struct Header
    {
      PoolStatus status: 1;
      unsigned int k: sizeof(unsigned int) * BITSOFBYTE - 1U;
    };
      
    struct Block : public Header
    {
      enum {size = MYSIZE};
      struct Links
      {
	Block *pNext;
	Block *pPrev; 
      };

      union
      {
	Links link;
	char szUserPart[size - sizeof(Header)];
      };
    };

    
  private:
    unsigned int m;
    unsigned int nNumberOfBlocks;
    Block *pPool;
    Block *pSentinel;

    static void Unlink(Block&);
    static void InsertAfter(Block&, Block&);
    Block& Buddy(Block&) const;
  public:
    BuddyPool(size_t);
    ~BuddyPool();

    void* Acquire(size_t);
    void Release(void*);
  };
}; 

#pragma pack (pop)

extern void* operator new(size_t bytes, ADT::StoragePool& p) throw(std::bad_alloc);
extern void* operator new(size_t bytes) throw(std::bad_alloc);
extern void operator delete(void* arg) throw();
extern void operator delete(void* arg, ADT::StoragePool& p) throw();

extern void* operator new(size_t bytes, ADT::StoragePool& p, char* file, int line) throw();
extern void* operator new(size_t bytes, char* file, int line) throw(std::bad_alloc);
extern void operator delete(void* arg, char* file, int line) throw();
extern void operator delete(void* arg, ADT::StoragePool& p, char* file, int line) throw();

extern void* operator new[](size_t bytes, ADT::StoragePool& p) throw();
extern void* operator new[](size_t bytes) throw(std::bad_alloc);
extern void operator delete[](void* arg) throw();
extern void operator delete[](void* arg, ADT::StoragePool& p) throw();

extern void* operator new[](size_t bytes, ADT::StoragePool& p, char* file, int line) throw();
extern void* operator new[](size_t bytes, char* file, int line) throw(std::bad_alloc);
extern void operator delete[](void* arg, char* file, int line) throw();
extern void operator delete[](void* arg, ADT::StoragePool& p, char* file, int line) throw();

#endif //MY_POOL
