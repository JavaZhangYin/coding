#include <iostream>

int ba (int a, int b) {
  while (b > a) {
    b = b & b - 1; 
  }
  return a & b; 
}

int main() {
  int a = 5;
  int b = 7;
  std::cout << "Enter a: "; 
  std::cin >> a;
  std::cout << "Enter b: "; 
  std::cin >> b;
  std::cout << "result is: " << ba(a, b) << std::endl; 
}
