#ifndef MY_STACK
#define MY_STACK

////////////////////////////////////////////////////////////////////
namespace ADT
{
	class Stack : public virtual Container
	{
	public:
		virtual Object& Top() const = 0;
		virtual void Push(Object&) = 0;
		virtual Object& Pop() = 0;
	};

	class StackAsArray : public Stack
	{
	private:
		Array<Object*> array;
		class Iter;
	public:
		StackAsArray();
		StackAsArray(unsigned int);
		~StackAsArray();
	//Object virtual funtion
		int CompareTo(Object const&) const;
	//Container virtual function
		void Purge();
		void Accept(Visitor&) const;
		Iterator& NewIterator() const;
	//stack vitual function
		Object& Top() const;
		void Push(Object&);
		Object& Pop();
		
		friend class Iter;
	};

	class StackAsArray::Iter : public Iterator
	{
	private:
		StackAsArray const& stack;
		unsigned int nPosition;
	public:
		Iter(StackAsArray const&);
		void Reset();
		bool IsDone() const;
		Object& operator *() const;
		void operator ++();
	};
	////////////////////////////////////////////////////
	class StackAsLinkedList : public Stack
	{
	private:
		DLinkedList<Object*> list;
		class Iter;
	public:
		StackAsLinkedList();
		~StackAsLinkedList();
	//Object virtual funtion
		int CompareTo(Object const&) const;
	//Container virtual function
		void Purge();
		void Accept(Visitor&) const;
		Iterator& NewIterator() const;
	//stack vitual function
		Object& Top() const;
		void Push(Object&);
		Object& Pop();
		
		friend class Iter;
	};


	class StackAsLinkedList::Iter : public Iterator
	{
	private:
		StackAsLinkedList const& stack;
		DListElement<Object*> const* pPosition;
	public:
		Iter(StackAsLinkedList const&);
		void Reset();
		bool IsDone() const;
		Object& operator *() const;
		void operator ++();
	};
}
#endif //MY_STACK
