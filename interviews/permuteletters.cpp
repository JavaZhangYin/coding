// 
// Interview question with rally health. 
//
#include <iostream>
#include <string> 
#include <cmath>

std::string decToBin(int n, int len) {

  std::string out = ""; 
  int r = n; 
  do {
    char c = r % 2 + 'A'; 
    out = c + out;
    r /= 2; 
  } while (r > 0); 
  
  while(out.size() < len) {
    out = "A" + out; 
  }
  
  return out; 
}

void permute(int n) {

  // numbers from 0 to n - 1. 
  // transform to binary format 
  // 0 corresponds to "A" and 1 corresponds to "B". 
  int total = pow(2, n); 

  for(int i = 0; i < total; i++) {
    std::cout << decToBin(i, n) << std::endl; 
  }
}

int main() {
  permute(5); 
}
