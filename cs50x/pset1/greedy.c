#include <stdio.h> 
#include <stdlib.h> 

double getDouble(); 

int main(void) {
  double change = -1;
  printf("O hai!  "); 

  while (change < 0) {
    printf("How much change is owed?\n");
    change = getDouble();
  }
  // round the number by plusing 0.5.
  int cents = (int)(change * 100 + 0.5); 
  // change dollars to cents. 
  // four types of coins, 25 cents, 10 cents, 5 cents and 1 cent. 
  int cnt = 0; 

  cnt += cents / 25; 
  cents %= 25; 

  cnt += cents / 10; 
  cents %= 10; 

  cnt += cents / 5; 
  cents %= 5; 

  printf("%d\n", cnt + cents); 
}

double getDouble() {
  char str[20]; 
  
  char ch; 
  int idx = 0; 
  do {
    ch = getchar(); 
    str[idx++] = ch; 
  } while (ch != '\n'); 

  str[idx] = '\0';

  // handle empty input. 
  if(ch == '\n' && idx == 1) {
    printf("Retry: ");
    return getDouble();
  } 
  
  for(int i = 0; i < idx - 1; i++) {
    if(str[i] == '-' || str[i] == '+' || str[i] == '.') continue; 

    if(!(str[i] >= '0' && str[i] <= '9')) {
      printf("Retry: "); 
      return getDouble(); 
    }
  }
  return atof(str); 

}
