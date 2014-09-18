#include <stdio.h> 

// pointers. 
// references and dereferences of pointers. 
// value and address. 
int main() {
  int a = 10; 
  int* ap = &a; 

  printf("Reference  : %x, %x\n", &a, ap); 
  printf("Dereference: %d, %d\n", a, *ap); 
}
