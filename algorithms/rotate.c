/* rotate one array of integers. */
#include<stdio.h>

void reverse(int x[], int len, int start, int end) {
  if (len == 0 || end <= start) return;
  
  for(int i = start, j = end; i < j; i++, j--) {
    int tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;
  }
}

void rotate(int x[], int len, int pivot) {
  if (len <= 0 || pivot >= len) return;

  reverse(x, len, 0, pivot-1);
  reverse(x, len, pivot, len-1);
  reverse(x, len, 0, len-1);
}

void print(int x[], int len) {
  for(int i = 0; i < len; i++) {
    printf("%d ", x[i]); 
  }
  printf("\n");
}

int main(int argc, char** argv) {
  int x[5] = {3,1,4,10,4};
  print(x, 5);
  rotate(x, 5, 4);
  print(x, 5);
}
