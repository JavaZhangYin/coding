// This code test if a given number is palindrome number or not. 
#include <iostream> 
#include <string> 

bool isPalindrome(int num) {
  if(num < 0) return false; 
  int x = 0; 
  int num1 = num; 
  while(num1 > 0) {
    x *= 10; 
    x += num1 % 10; 
    num1 /= 10; 
  }
  std::cout << num << " " << x << std::endl;  
  return num == x; 
}

bool isPalindrome(std::string str) {
  if(str.length() == 0) return true; 
  int len = str.length(); 
  for(int i = 0; i < len / 2; i++) {
    if(str[i] != str[len-1-i]) return false; 
  }
  return true; 
}

int main(int argc, char** argv) {
  int x = 10100101; 
  std::string str("ababbaba"); 
  std::cout << isPalindrome(x) << std::endl; 
  std::cout << isPalindrome(str) << std::endl; 
  return 0;
}
