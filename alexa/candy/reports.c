#include "reports.h" 

// report what is happending production line. 
void report(STATUS &stat, char what[255]) {
  printf("Belt: %d frogs + %d escargots = %d\t %s", stat.frog, nesc, total, what);
}

void summaryReport(STATUS &stat) {
  printf("PRODUCTION REPORT\n");
  printf("----------------------------------------"); 
  printf("crunchy frog bite producer generated %d candies.\n", stat.frog);
  printf("escargot sucker producer generated %d candies. \n", stat.escargot);
  printf("Lucy consumed %d crunchy frog bites + %d escargot suckers = %d.\n", 
	 stat.frog, stat.escargot, stat.frog + stat.escargot); 
  printf("Ethel consumed %d crunchy frog bites + %d escargot suckers = %d.\n", 
	 stat.frog, stat.escargot, stat.frog + stat.escargot);
}
