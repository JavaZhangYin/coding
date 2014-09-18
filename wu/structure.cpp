#include <stdio.h> 
#include <stdlib.h> // for malloc

struct student {
  char* name; 
  int age; 
  double height;
}; 

int main() {
  student* s = (student*) malloc(sizeof(student)); 

  s->name = (char*)"Shumin Guo"; 
  //s->name = (char*) malloc(sizeof(char) * 20); // "Shumin Guo"; 
  s->age = 30;
  s->height = 5.8;

  // *s = {(char*)"Shumin", 31, 5.9}; // some compilers does not support this.

  printf("Name: %s\nAge: %d\nHeight: %3.2lf", s->name, s->age, s->height);
  
  delete(s);
}
