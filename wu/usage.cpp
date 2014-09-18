#include <stdio.h> 

double add(int a, int b); 
double minus(int a, int b); 
double multiply(int a, int b);
double divide(int a, int b); 

double ops(int a, int b, double (*fp)(int a, int b)); 

int main() {
  // normal pointers. 
  
  // pointers and arrays. 
  const int SIZE = 5;
  int ia[SIZE] = {2,34,6,7,3};
  int* pia = ia; 

  // constant pointers 
  int* const cp = ia;

  // pointer's pointer 
  int** p = &pia; 

  // function pointers
  double (*fp)(int a, int b); 
  fp = &add; 
  printf("Addition: %f\n", fp(10, 20)); 
  fp = &minus; 
  printf("Subtraction: %f\n", fp(10, 20)); 
  fp = &multiply;
  printf("Multiplication: %f\n", fp(10, 20));
  fp = &divide;
  printf("Division: %f\n", fp(10, 20));

  double ops(int a, int b, double (*fp)(int a, int b));
  printf("%f\n", ops(10, 20, &add)); 

}

double add(int a, int b) {
  return a + b; 
}
double minus(int a, int b) {
  return a - b; 
}

double multiply(int a, int b) {
  return a * b; 
} 

double divide(int a, int b) {
  if(0 == b) {
    printf("divisor can't be 0!"); 
    return -1; 
  }
  return a / b; 
}

double ops(int a, int b, double (*fp)(int a, int b)) {
  return fp(a, b); 
}
