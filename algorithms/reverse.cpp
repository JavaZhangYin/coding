#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// reverse a string. 
void reverse(char *str, int len) {
  int i = 0;
  int j = len - 1;
  while (i < j) {
    char t = str[i];
    str[i] = str[j];
    str[j] = t;
    i++, j--; 
  }
}

int main(int argc, char** argv) {
  for(int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
  printf("String after reverse.......");
  int len = strlen(argv[1]);
  char *s = (char *)malloc(len);
  strcpy(s, argv[1]);
  reverse(s, len);
  printf("String after reverse: %s.\n", s);
}
