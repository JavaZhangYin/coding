#include "defs.h"
#include "reports.h" 

// report what is happending production line. 
void report(BELT_STATUS *stat, char what[255]) {
  printf("Belt: %d frogs + %d escargots = %d\t %s\n", stat->frog, stat->escargot, stat->total, what);
  fflush(stdout);
}

void summaryReport(BELT_STATUS *stat) {
  printf("\nPRODUCTION REPORT\n");
  printf("----------------------------------------\n"); 
  printf("crunchy frog bite producer generated %d candies.\n", stat->frog_cnt);
  printf("escargot sucker producer generated %d candies. \n", stat->escargot_cnt);
  printf("Lucy consumed %d crunchy frog bites + %d escargot suckers = %d.\n", 
	 stat->lucy_frog, stat->lucy_escargot, stat->lucy_frog + stat->lucy_escargot); 
  printf("Ethel consumed %d crunchy frog bites + %d escargot suckers = %d.\n", 
	 stat->ethel_frog, stat->ethel_escargot, stat->ethel_frog + stat->ethel_escargot);
  fflush(stdout);
}
