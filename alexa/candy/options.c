#include <stdio.h>
#include <stdlib.h>
#include "options.h"

void parseOptions(int argc, char** argv, DELAYS *dlys) {
  if(argc < 2) return;
  int i = 1; 
  while(i < argc) {
    if(argv[i][0] == '-') {
      int opt = argv[i][1]; // the option letter.
      if (i >= argc - 1) return; 

      char *optval = argv[i+1]; 
      switch (opt) {
      case 'E':
	dlys->delay_frog = atoi(optval); 
	printf("option %s\n", optval); 
	break; 
      case 'L':
	dlys->delay_escargot = atoi(optval); 
	break; 
      case 'f':
	dlys->delay_lucy = atoi(optval); 
	break; 
      case 'e':
	dlys->delay_ethel = atoi(optval); 
	break; 
      default: 
	fprintf(stderr, "Unknow option -%c.\n", opt); 
      }
    }
    printf("arg[%d] = %s\n", i, argv[i]);
    i++;
  }
}

// for testing. 
/* int main(int argc, char** argv) { */

/*   DELAYS * dl = (DELAYS *)malloc(sizeof(DELAYS)); */
/*   if(!dl) return -1;  */
/*   parseOptions(argc, argv, dl); */

/*   printf("Frog Delay: %d\n", dl->delay_frog );  */
/*   printf("Escargot Delay: %d\n", dl->delay_escargot );  */
/*   printf("Ethel Delay: %d\n", dl->delay_ethel );  */
/*   printf("Lucy Delay: %d\n", dl->delay_lucy );  */
/*   return 0; */
/* } */
