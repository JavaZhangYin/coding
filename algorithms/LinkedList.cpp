#include <iostream>
#include <cstdlib>
#include <ctime>

class Node {
public:
  Node() { data = 0; next = NULL; }
  Node(int d) { data = d; next = NULL; } 
  int getData() {
    return data; 
  }
  void setData(int d) {
    data = d; 
  }
  Node* next; 
  
private:
  int data; 
};

class LinkedList {
public:
  LinkedList() { head = NULL; }

  // insert from the tail of the list.
  void insertTail(int d) {
    Node *n = new Node (d);
    if (head == NULL) {
      head = n;
    } else {
      Node *nn = head;
      while (nn -> next != NULL)  nn = nn -> next;
      nn -> next = n; 
    }
  }

  // Insert from the head of the list.
  void insertHead(int d) {
    Node *n = new Node(d);
    if (head == NULL) {
      head = n; 
    } else {
      n->next = head;
      head = n; 
    }
  }
  
  void deleteElem(int d) {
    std::cout << "TODO" << std::endl;
  }

  // find node in the list. 
  Node* find(int d){
    Node *n = head;
    while (NULL != n && n -> getData() != d) {
      n = n -> next; 
   }

    return n; 
  }

  // reverse a linked list.
  void reverse() {
    if (NULL == head || NULL == head -> next) return;

    Node *a = NULL; 
    Node *b = head;
    Node *c = b -> next; 
    
    while (b) {
      b -> next = a;
      a = b;
      b = c;
      if (b) head = b; else head = a; 
      if (c) c = c -> next; 
    }
    
    return; 
  }

  // print all nodes. 
  void printAll () {
    Node *n = head;
    while (n != NULL) {
      std::cout << n -> getData() << ' ';
      n = n->next; 
    }
    std::cout << std::endl; 
  }
  
  Node* getList() {
    return head; 
  }
private:
  Node *head; 
  
};

// Double linked list.
class DNode {
public:
  DNode() {
    next = prev = NULL; 
  }
  DNode(int d) {
    data = d; 
  }
  DNode *next;
  DNode *prev;
  int getData() {
    return data; 
  }

private:
  int data;

};

class DoubleLinkedList {
public:
  DoubleLinkedList() {
    head = tail = NULL; 
  }
  void insertFront(int d) {
    DNode *node = new DNode(d);
    
    if (head == NULL) {
      head = node;
      tail = node; 
    } else {
      node -> next = head;
      head -> prev = node; 
      head = node; 
    }
  }

  void insertTail(int d) {
    DNode *node = new DNode(d);
    if (head == NULL) {
      head = node;
      tail = node; 
    } else {
      tail -> next = node;
      node -> prev = tail;
      tail = node; 
    }
  }

  void printAll () {
    DNode *dn = head;
    while(dn != NULL) {
      std::cout << dn->getData() << ' ';
      dn = dn -> next; 
    }
    std::cout << std::endl; 
  }
private: 
  DNode *head;
  DNode *tail;
};

int main(int argc, char **argv) {
  LinkedList *list = new LinkedList(); // the linked list header.
  srand(time(NULL)); 
  for(int i = 0; i < 10; i++) {
    int num = rand() % 100;
    list -> insertTail(num);
  }

  for(int i = 0; i < 5; i++) {
    int num = rand() % 10;
    list -> insertHead(num);
  }

  std::cout << "original value: " << std::endl; 
  list -> printAll();
  list -> reverse();
  std::cout << "reversed value: " << std::endl;
  list -> printAll();

  Node *n = list -> find(10);
  std::cout << "Node is: " << n << std::endl; 
  if (n) {
    std::cout << "------------------" << std::endl; 
    std::cout << n -> getData() << std::endl; 
    std::cout << n << std::endl;
    std::cout << "++++++++++++++++++" << std::endl; 
    
  }

  // double linked list.
  DoubleLinkedList *dlist = new DoubleLinkedList();
  for (int i = 0; i < 10 ; i++) {
    dlist->insertFront(i);
  }

  dlist->printAll();
  
  return 0;  
}
