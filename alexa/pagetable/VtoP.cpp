#include <stdio.h>
#include <stdlib.h>


typedef struct {

} PAGETABLE; 

typedef struct {

} LEVEL; 

typedef struct {

} MAP; 

// the
unsigned int LogicalToPage(unsigned int LogicalAddress, 
			   unsigned int Mask, 
			   unsigned int Shift); 

MAP *PageLookup (PAGETABLE *PageTable, unsigned int LogicalAddress);
void PageInsert (PAGETABLE *PageTable, unsigned int LocalAddress, unsigned int Frame); 


int main(int argc, char **argv) {
  
  char *input = NULL; 

  // number of bits for each level.
  int ll[10]; 
  int llidx = 0; 

  // process first n memory references.
  int n;

  // output to specified file. 
  char *output = NULL;	

  // show logical to physical translation. 0 for non show. 1 for show. 
  int show = 0; 

  // parse options. 
  int i ; 
  for(i = 1; i < argc; i++) {
    
    printf("%s\n", argv[i]);
    
    if(strcmp(argv[i], "-n") == 0) {
      n = atoi(argv[++i]);
    } else if(strcmp(argv[i], "-p") == 0) {
      output = argv[++i];
    } else if (strcmp(argv[i], "-t") == 0) {
      show = 1; 
    } else break; 

  }

  input = argv[i];
  for (int j = i; j < argc; j++) {
    ll[llidx++] = atoi(argv[j]); 
    printf("Level %d has %d bits...\n", llidx, ll[llidx-1]); 
  }

  // do translation. 

  // output. 


  return 0; 
}
