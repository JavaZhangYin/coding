#ifndef MY_QUEUE
#define MY_QUEUE

namespace ADT
{
    static unsigned int  DEFAULT_QUEUE_SIZE = 1024;
    
	class Queue : public virtual Container
	{
	public:
		virtual Object& GetHead() const = 0;
		virtual void EnQueue(Object&) = 0;
		virtual Object& DeQueue() = 0;
	};

	class QueueAsArray : public virtual Queue
	{
	protected:
		Array<Object*> array;
		unsigned int nHead;
		unsigned int nTail;
	public:
		QueueAsArray(unsigned int = DEFAULT_QUEUE_SIZE);
		~QueueAsArray();
	//Object virtual function
		int CompareTo(Object const&) const;
	//Container virtual function
		void Purge();
		void Accept(Visitor&) const;
		bool IsFull() const;
	//Queue vitual function
		Object& GetHead() const;
		void EnQueue(Object&);
		Object& DeQueue();
	};
	///////////////////////////////////////////////////////////
	class QueueAsLinkedList : public virtual Queue
	{
	protected:
		DLinkedList<Object*> list;
	public:
		QueueAsLinkedList();
		~QueueAsLinkedList();
	//Object virtual function
		int CompareTo(Object const&) const;
	//Container virtual function
		void Purge();
		void Accept(Visitor&) const;
	//Queue vitual function
		Object& GetHead() const;
		void EnQueue(Object&);
		Object& DeQueue();
	};
	//////////////////////////////////////////////////////////
	class Deque : public virtual Queue
	{
	public:
		virtual Object& GetHead() const = 0;
		virtual Object& GetTail() const = 0;
		virtual void EnQueue(Object&);
		virtual void EnQueueHead(Object&) = 0;
		virtual void EnQueueTail(Object&) = 0;
		virtual Object& DeQueue();
		virtual Object& DeQueueHead() = 0;
		virtual Object& DeQueueTail() = 0;
	};
	class DequeAsArray : public Deque, public QueueAsArray
	{
	public:
		DequeAsArray(unsigned int);
		~DequeAsArray();

		Object& GetHead() const;
		Object& GetTail() const;
		void EnQueue(Object&);
		void EnQueueHead(Object&);
		void EnQueueTail(Object&);
		Object& DeQueue();
		Object& DeQueueHead();
		Object& DeQueueTail();
	};
	///////////////////////////////////////////////////////////////////////
	class DequeAsLinkedList : public Deque, public QueueAsLinkedList
	{
	public:
		DequeAsLinkedList();
		~DequeAsLinkedList();

		Object& GetHead() const;
		Object& GetTail() const;
		void EnQueue(Object&);
		void EnQueueHead(Object&);
		void EnQueueTail(Object&);
		Object& DeQueue();
		Object& DeQueueHead();
		Object& DeQueueTail();
	};

	
///////////////////////////////////////////////////////////////////////////
	class PriorityQueue : public virtual Container
	{
	public:
		virtual void EnQueue(Object&) = 0;
		virtual Object& FindMin() const = 0;
		virtual Object& DeQueueMin() = 0;
	};
///////////////////////////////////////////////////////////////////////////
	class MergeablePriorityQueue : public virtual PriorityQueue
	{
	public:
		virtual void Merge(MergeablePriorityQueue&) = 0;
	};
///////////////////////////////////////////////////////////////////////////
}
#endif //MY_QUEUE
