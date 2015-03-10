#include "options.h"

void parseOptions(int argc, char** argv, DELAYS *dlys) {
  opterr = 0; 
  char *val; // the value of an option. 

  int o; 
  while((o = getopt(argc, argv, "ELfe:")) != -1) {
    switch(o) {
    case 'E':
      dlys->delay_frog = atoi(optarg); 
    case 'L':
      dlys->delay_escargot = atoi(optarg); 
    case 'f':
      dlys->delay_lucy = atoi(optarg); 
    case 'e':
      dlys->delay_ethel = atoi(optarg); 
    case '?':
      if (optopt == 'c')
	fprintf(stderr, "Option -%c requires an argument. ", optopt);

      else if (isprint (optopt))
	fprintf(stderr, "Unknown option -%c.\n", optopt);
      else perror("Unknown option character."); 
      return; 
    default: 
      return; 
    }
  }
}
