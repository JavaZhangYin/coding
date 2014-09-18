#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <ctime>

using namespace std;

#ifdef USE_DEBUG
#include "common.h"
#include "log.h"
#include "debug.h"
#endif

#include "adt.hpp"

#include "test.hpp"
#include "array_test.hpp"

using namespace ADT;
class myVisit : public Visitor
{
public:
  void Visit(ADT::Object& obj){cout << obj << endl;}
};

class A
{
public:
  int b;
  int c;
public:
  A():b(0){}//{cout << "A()" << "A::b = " << b << endl;}
  ~A(){}//{cout << "~A()"<< "A::b = " << b << endl;}
};

int main(void)
{
  if(1)
    {
      array_test array_test;
      bool rf = array_test.do_test();
      cout << rf << endl;
      // if(rf)
      // 	{
      // 	  DEBUG("Error");
      // 	}
      // else
      // 	{
      // 	  DEBUG("Errors."); 
      // 	}
      //return 0;
    }

  {
    StackAsArray stack(10);
    stack.Push(* new Int(3));
    stack.Push(* new Int(4));
    stack.Push(* new Int(5));
    stack.Push(* new Int(6));
    stack.Push(* new Int(7));
    stack.Push(* new Int(8));
    stack.Push(* new Int(9));

    Iterator& iter = stack.NewIterator();
    while(!iter.IsDone())
      {
	cout << *iter << endl;
	++iter;
      }
    delete &iter;
  }

  {
    NaryTree naryTree(5, * new Int(7));
    NaryTree& tree1 = naryTree.GetSubTree(1);
    tree1.AttachKey(*new ADT::Char('s'));
    int iHeight = naryTree.GetHeight();
    unsigned int nCount = naryTree.GetCount();
    BinaryTree tree2(* new Int(54));
    BinaryTree& tree3 = dynamic_cast<BinaryTree&> (tree2.GetLeft());
    tree3.AttachKey(* new ADT::String("asdfasdf"));
    tree3.AttachLeft(* new BinaryTree(* new Int(3)));
    iHeight = tree2.GetHeight();
    nCount = tree2.GetCount();

    //BTree bst(4);
    BST bst;

    bst.Insert(* new Int(8));
    bst.Insert(* new Int(9));
    bst.Insert(* new Int(10));

    bst.Insert(* new Int(4));
    bst.Insert(* new Int(5));
    bst.Insert(* new Int(6));
    bst.Insert(* new Int(7));

    bst.Insert(* new Int(1));
    bst.Insert(* new Int(2));
    bst.Insert(* new Int(3));

    bst.Insert(* new Int(11));
    bst.Insert(* new Int(12));
    bst.Insert(* new Int(13));

	

    Iterator& ii = bst.NewIterator();
    while(!ii.IsDone())
      {
	cout << *ii << endl;
	++ii;
      }
	

    myVisit v;
    PreOrder v1(v);
    bst.DepthFirstTraversal(v1);
    cout << "InOrder" << endl;
    InOrder v2(v);
    bst.DepthFirstTraversal(v2);
    cout << "BreadthFirstTraversal" << endl;
	
    bst.BreadthFirstTraversal(v);

    Int& a = dynamic_cast<Int&>(bst.Find(Int(3)));
    Int& b22 = dynamic_cast<Int&>(bst.Find(Int(7)));
    bst.WithDraw(b22);
    delete &b22;
    bst.DepthFirstTraversal(v2);
    Int& c23 = dynamic_cast<Int&>(bst.Find(Int(4)));
    bst.WithDraw(c23);
    bst.DepthFirstTraversal(v2);
    delete &c23;
  }

  {
    //BinaryHeapAsArray heap(100);
    BinomialQueue heap;
    heap.EnQueue(* new Int(1));
    heap.EnQueue(* new Int(2));
    heap.EnQueue(* new Int(3));
    heap.EnQueue(* new Int(12));
    heap.EnQueue(* new Int(11));
    heap.EnQueue(* new Int(10));
    heap.EnQueue(* new Int(9));
    heap.EnQueue(* new Int(8));
    heap.EnQueue(* new Int(7));
    heap.EnQueue(* new Int(6));

    for(int j = 1; j<= 10; j++)
      {
	cout << heap.DeQueueMin() << endl;
      }

    Iterator& heapIter = heap.NewIterator();
    while(!heapIter.IsDone())
      {
	cout << *heapIter << endl;
	++heapIter;
      }
    delete &heapIter;
  }

  {
    MultisetAsArray myset(100);
    UInt i0(1);
    UInt i1(2);
    UInt i2(3);
    UInt i3(4);
    UInt i4(5);
    UInt i5(6);
    UInt i6(7);
    UInt i7(8);
    UInt i8(9);
    UInt i9(10);
	
    myset.Insert(i0);
    myset.Insert(i1);
    myset.Insert(i2);
    myset.Insert(i3);
    myset.Insert(i4);
    myset.Insert(i5);
    myset.Insert(i6);

    myset.Insert(i7);
    myset.Insert(i8);
    myVisit visit;
    myset.Accept(visit);
  }
  
  {
    Association a(*new Int(6), *new Int(7));
	
    cout << a.GetKey() << endl;
    cout << a.GetValue() << endl;
  }
  
  {
    ListAsLinkedList list;

    list.Insert(*new Int(1));
    list.Insert(*new Int(2));
    list.Insert(*new Int(3));
    list.Insert(*new Int(4));
    list.Insert(*new Int(5));
    list.Insert(*new Int(6));
    list.Insert(*new Int(7));
    list.Insert(*new Int(8));
    list.Insert(*new Int(9));
    list.Insert(*new Int(10));

    SortedListAsLinkedList& tree = *new SortedListAsLinkedList;
    tree.RescindOwnership();
    cout <<" tree.IsOwner() = " << tree.IsOwner() << endl;
    //cout <<" tree.IsOwner() = " << (dynamic_cast<BinaryTree&>(tree)).IsOwner() << endl;

    Iterator& list_iter = list.NewIterator();
    while(!list_iter.IsDone())
      {
	//cout << *list_iter << endl;
	cout << "addr:" << &(*list_iter) << endl;
	tree.Insert(*list_iter);
	++list_iter;
      }
    delete &list_iter;
    cout << "\n" << endl;
    Iterator& _iter1 = tree.NewIterator();
    while(!_iter1.IsDone())
      {
	//cout << *_iter1 << endl;
	cout << "addr:" << &(*_iter1) << endl;
	++_iter1;
      }
    delete &_iter1;
    cout << "\n" << endl;

    cout << "tree= " << tree << endl;
    cout << "list" << list << endl;
    tree.Purge();
    cout << "tree= " << tree << endl;
    cout << "list" << list << endl;
    delete &tree;
    cout << " 11111111111111111" << endl;
    cout << "list" << list << endl;
    Iterator& list_iter1 = list.NewIterator();
    while(!list_iter1.IsDone())
      {
	//cout << *list_iter1 << endl;
	cout << "addr:" << &(*list_iter1) << endl;
	++list_iter1;
      }
    delete &list_iter1;
    cout << "\n" << endl;
  }
  /*
  //pool test
  {
  //DoublyLinkedPool p((size_t)8000090 * 80);
  //SinglyLinkedPool p((size_t)10000 * 80);
  BuddyPool p(10000000 * 40);
  //SinglyLinkedPool p(10000000 * 40);
  //DoublyLinkedPool p(10000000 * 40);
  cout << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << endl;
  
  A* pa[400000];
  time_t t1 = time(NULL);
  for(int i = 0; i < 400000; i++)
  {
  cout << "i = " << i << endl;
  pa[i] = new(p) A[i % 100];
  pa[i]->b = i;
  }
  
  for(int i = 0; i < 400000; i++)
  {
  delete [] pa[i];
  }
  time_t t2 = time(NULL);
  int tt = t2 - t1; 
  cout << "time = " << tt << endl;

  //     DoublyLinkedPool q(100000 * 40 * 100);
  //     t1 = time(NULL);
  //     for(int i = 0; i < 40000; i++)
  //       {
  // 	pa[i] = new A[i%1000];
  // 	pa[i]->b = i;
  //       }
  
  //     for(int i = 0; i < 40000; i++)
  //       {
  // 	delete[] pa[i];
  //       }
  //     t2 = time(NULL);
  //     tt = t2 - t1; 
  //     cout << "time = " << tt << endl;
  
  //delete(dynamic_cast<StoragePool&>(p), p1);
  //delete(dynamic_cast<StoragePool&>(p), p1);
  //cout << "now is right!" << endl;
  //int *p2 = ADT::new(p, int);
  //int *p3 = ADT::new(q, int);
  }
  */
  {
    Vertex& v0 = *new Vertex(0);
    Vertex& v1 = *new Vertex(1);
    Vertex& v2 = *new Vertex(2);
    Vertex& v3 = *new Vertex(3);
    Vertex& v4 = *new Vertex(4);
    Vertex& v5 = *new Vertex(5);
    Vertex& v6 = *new Vertex(6);

    Edge& e01 = *new Edge(v0, v1);
    Edge& e12 = *new Edge(v1, v2);
    Edge& e13 = *new Edge(v1, v3);
    Edge& e23 = *new Edge(v2, v3);
    Edge& e24 = *new Edge(v2, v4);
    Edge& e56 = *new Edge(v5, v6);

    GraphAsMatrix g(100);

    g.AddVertex(v0);
    g.AddVertex(v1);
    g.AddVertex(v2);
    g.AddVertex(v3);
    g.AddVertex(v4);
    g.AddVertex(v5);
    g.AddVertex(v6);
    
    g.AddEdge(e01);
    g.AddEdge(e12);
    g.AddEdge(e13);
    g.AddEdge(e23);
    g.AddEdge(e24);
    g.AddEdge(e56);

    Iterator& i1 = g.Vertices();
    while(!i1.IsDone())
      {
	cout << "11111111111111" << endl;
	cout << *i1 << endl;
	++i1;
      }
    delete &i1;

    Iterator& i2 = g.Edges();
    while(!i2.IsDone())
      {
	cout << "22222222222222" << endl;
	cout << *i2 << endl;
	++i2;
      }
    delete &i2;
    
    Iterator& i3 = g.IncidentEdges(v1);
    while(!i3.IsDone())
      {
	cout << "33333333333333333" << endl;
	cout << *i3 << endl;
	++i3;
      }
    delete &i3;
 
    Iterator& i4 = g.EmanatingEdges(v1);
    while(!i4.IsDone())
      {
	cout << "4444444444444444444" << endl;
	cout << *i4 << endl;
	++i4;
      }
    delete &i4;
  }
}
