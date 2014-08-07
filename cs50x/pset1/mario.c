#include <stdio.h> 
#include <stdlib.h> 

int getInt();

int main(void) {
  int height = -1; 

  while (height < 0 || height > 23) {
    printf("Height: ");
    height = getInt(); 
  }
  
  for(int i = 0; i < height; i++) {
    // print space. 
    for(int j = 0; j < height - i - 1; j++) {
      printf(" "); 
    }

    // print #
    for(int j = 0; j < i + 2; j++) {
      printf("#"); 
    }
    printf("\n"); 
  }
}

int getInt() {
  char str[20]; 

  char ch; 
  int idx = 0; 
  do {
    ch = getchar(); 
    str[idx++] = ch; 
  } while (ch != '\n'); 

  str[idx] = '\0';
  if(ch == '\n' && idx == 1) {
    printf("Retry: ");
    return getInt();
  }

  for(int i = 0; i < idx - 1; i++) {
    if(str[i] == '-' || str[i] == '+') continue; 

    if(!(str[i] >= '0' && str[i] <= '9')) {
      printf("Retry: "); 
      return getInt(); 
    }
  }
  return atoi(str); 
}
