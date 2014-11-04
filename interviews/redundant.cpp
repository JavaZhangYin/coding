#include <iostream> 
#include <stack>
#include <string> 

bool is_redundant(std::string s) {
  std::stack<int> stack;
  stack.push(0);  

  int e; 
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '(') {

      stack.push(0);
 
   } else if(s[i] == ')') {

      if(stack.top() == 0) return true; 
      stack.pop(); 

    } else {

      e = stack.top(); 
      stack.pop();
      stack.push(e + 1); 

    }
  }
  std::cout << stack.size() << std::endl; 
  if(stack.size() > 1) 
    std::cout << "parenthesis does not match..." << std::endl; 
  
  return false; 
}

int main() {
  std::string str = "()"; 
  if(is_redundant(str)) {
    std::cout << "redundant...." << std::endl; 
  } else {
    std::cout << "not redundant...." << std::endl; 
  }
}
