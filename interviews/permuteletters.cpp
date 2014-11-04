#include <iostream>
#include <string> 
#include <cmath>

std::string decToBin(int n) {
  if(0 == n) return "0";
  if(1 == n) return "1"; 

  if(0 == n % 2) return decToBin(n - 1) + "0"; 
  else return decToBin(n - 1) + "1"; 
}

std::string permute1(int n) {

  if(0 == n) return ""; 
  std::string out = ""; 

  return "A" + permute1(n - 1) << std::endl; 
  return "B" + permute
}

void permute(int n) {

  // numbers from 0 to n - 1. 
  // transform to binary format 
  // change 0 to "A" and 1 to "B". 
  int total = pow(n, 2); 

  for(int i = 0; i < total; i++) {
    
    std::cout << decToBin(i) << std::endl; 
  }
}

int main() {
  permute(4); 
}
