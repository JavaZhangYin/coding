#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std; 

void getSentence(char *str);
void capitalizer(char *str); 
int wordcount(char *str); 
// void capitalizer(char str[]); '\0'
// void foo(int nums[], int size); 

int main() {
  const int SIZE = 255; 
  char str[SIZE]; 
  cout << "Please enter the original sentence: "; 
  // cin >> str;
  // getline(cin, str);  
  getSentence(str); 

  cout << "Original string is: " << str << endl; 
  capitalizer(str); 
  cout << "Capitalized string is: " << str << endl; 

  cout << "Number of words in sentence: " << wordcount(str) << endl; 
}

void capitalizer(char *str) {
  if(strlen(str) <= 0) return; 
  int diff = 'a' - 'A'; // 97 - 65 = 32;  
  if(str[0] > 'a' && str[0] < 'z') str[0] = str[0] - diff; 

  int i = 1; 
  while(str[i] != '\0') {
    if(str[i] == '.' || str[i] == '?' || str[i] == '!') {
      i++; 
      if(str[i] == '\0') break; 
      i++; 
      if(str[i] > 'a' && str[i] < 'z') str[i] -= diff; 
    } 
    i++;
  }
}

int wordcount(char *str) {
  if(strlen(str) == 0) return 0; 
  int len = 1; 
  
  int i = 0; 
  while(str[i] != '\0') {
    if(str[i] == ' ') len++; 
    i++; 
  }
  return len; 
}

void getSentence(char *str) {
  int idx = 0; 
  while (1) {
    char ch = getchar();

    if(ch == '\n') {
      str[idx++] = '\0';
      break;
    }
    str[idx++] = ch;
    if (idx >= 255) {
      printf("Error, longer than the 255 will be ignored.");
      str[--idx] = '\0';
      break;
    }
  }
}

