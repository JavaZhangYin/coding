// Computing the gcd of two integers. 
// using the euclid's algorithm. 
// gcd(a, 0) = a
// gcd(a, b) = gcd(b, a % b); 
// 
// or in other form. 
// gcd(a, a) = a
// gcd(a, b) = gcd(a - b, b), if a > b;
// gcd(a, b) = gcd(a, b - a), if b > a; 

#include <iostream> 

int gcd(int a, int b) {
  std::cout << a << " " << b << std::endl; 
  if(b == 0) return a; 
  if(a < b) return gcd(a, b % a); 
  else return gcd(b, a % b); 
}

int main() {
  int a = 12; 
  int b = 18; 

  std::cout<< "a = "; 
  std::cin >> a; 

  std::cout << "b = "; std::cin >> b; 
  
  std::cout << gcd(a, b); 
}
