#include <iostream> 
#include <string> 

using namespace std; 

struct student {
  int age ;
  double height; 
  string name; 
}; 

void printStudent(student *s); 
void (*fp)(student *s); 
template<typename T>void printArray(T array[], int size); 
template<typename T>void printArrayNew(T array[], int size); 

int main() {
  const int SIZE = 5; 
  int a = 10; 
  int ai[SIZE] = {4,2,4,6,7};
  student s = {30, 5.8, "Shumin Guo"}; 

  // regular pointers. 
  int * pa = &a; 
  student * ps = &s; 

  // const pointers. 
  student * const cps = &s; 
  // cps = ps; // --> error here. 

  // pointer to pointer. 
  // student ** pps1 = &&s; // this will not work, as &s is an rvalue. 
  student ** pps = &ps; 

  // Array and pointers.  
  int *ap = ai; 
  printArray(ai, SIZE); 
  printArray(ap, SIZE); 
  printArrayNew(ai, SIZE); 

  // function pointer
  void (*fp1)(student *s); 
  cout << "Function pointer ----->> " << endl;
  fp = &printStudent;
  fp1 = fp;
  fp(ps); 
  fp1(ps); 

  cout << "A is: " << a << endl; 
  cout << "Pa is: " << pa << endl; 
  cout << "*Pa is: " << *pa << endl; 

  printStudent(&s); 
  printStudent(ps);
}

void printStudent(student* s) {
  cout << endl << "Student Info: " << endl
       << "Name: " << s->name << endl
       << "Age: " << s->age << endl
       << "Height: " << s->height << endl;
}

template<typename T>
void printArray(T array[], int size) {
  for(int i = 0; i < size; i++) {
    cout << array[i] << endl; 
  }
  cout << endl; 
}

template<typename T>
void printArrayNew(T *array, int size) {
  for(int i = 0; i < size; i++) {
    cout << *(array + i) << endl;
  }
  cout << endl; 
}
