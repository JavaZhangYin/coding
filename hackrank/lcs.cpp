#include <iostream>
#include <string> 
#include <stack>

int max(int a, int b) {
  return a > b ? a : b; 
}

int main() {
  std::string a = "abcb";
  std::string b = "bdcab";

  int sa = a.size(); 
  int sb = b.size(); 

  int v[sa+1][sb+1]; 
  for(int i = 0; i < sa+1; i++) {
    for(int j = 0; j < sb+1; j++) {
      v[i][j] = 0; 
    }
  }

  // populate. 
  for(int i = 1; i < sa+1; i++) {
    for(int j = 1; j < sb+1; j++) {
      if(a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1] + 1; 
      else v[i][j] = max(v[i-1][j], v[i][j-1]); 
      //std::cout << v[i][j] << std::endl; 
    }
  }

  // print array. 
  for(int i = 0; i < sa+1; i++) {
    for(int j = 0; j < sb+1; j++) {
      std::cout << v[i][j] << " "; 
    }
    std::cout << std::endl; 
  }

  // back trace and get result. 
  std::stack<char> res; 
  for(int i = sa, j = sb; i >= 0 && j >= 0;) {
    if(a[i-1] == b[j-1]) {
      res.push(a[i-1]); 
      i--, j--; 
    } else j--; 
  }

  while(!res.empty()) {
    std::cout << res.top(); 
    res.pop(); 
  }
  std::cout << std::endl;

}
