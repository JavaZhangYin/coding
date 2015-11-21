#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int x[], int len) {
  if (len <= 0) return;
  srand(time(NULL));
  for(int i = 0; i < len; i++) {
    int rpos = rand() % len;
    int tmp = x[i];
    x[i] = x[rpos];
    x[rpos] = tmp; 
  }
}
void print(int x[], int len) {
  for(int i = 0; i < len; i++) {
    printf("%d ", x[i]); 
  }
  printf("\n");
}

int main(int argc, char** argv) {
  int x[5] = {4,35,100,53,1};
  print(x, 5);
  shuffle(x, 5);
  print(x, 5); 

}
