#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
typedef struct {

  long CurrentStatus;
  long TerminationValue;

} PROGRESS_STATUS; 

long wordcount(FILE *file); 
void progress_monitor(PROGRESS_STATUS *status); 

int main(int argc, char** argv) {
  if (argc < 2) {
    fprintf(stderr, "%s\n", "Error opening file. "); 
    return 1; 
  }

  FILE* file = fopen(argv[1], "r");

  long wc = wordcount(file); 
  printf("\nThere are %ld words in the file. \n", wc); 

  fclose(file); 
  return 0;
}

long wordcount(FILE* file) {
  PROGRESS_STATUS *status = (PROGRESS_STATUS *)malloc(sizeof(PROGRESS_STATUS));

  // get file length (in bytes).
  struct stat buf; 

  fseek(file, 0L, SEEK_END); 
  status->TerminationValue = ftell(file);
  fseek(file, 0L, SEEK_SET); 

  int byteCnt = 0; 
  long wc = 0;
  
  // read byte by byte. 
  char c = 'a'; 
  pthread_t pmt;// progress monitor thread. 

  // start the monitoring process.
  int th;
  th = pthread_create(&pmt, NULL, (void *)&progress_monitor, (PROGRESS_STATUS *)status);

  // make sure that the thread created corrrectly.
  if (th) {
    perror("Error creating new thread...\n"); 
    pthread_exit(NULL);
  }

  do {

    byteCnt++; 
    status->CurrentStatus = byteCnt; 
    // putchar(c);
    if(isspace(c)) {
      wc++; 
    }
     
  } while((c = fgetc(file)) != EOF); 
  
  pthread_join(pmt, 0);

  return wc; 
}

void progress_monitor(PROGRESS_STATUS *status) {
  static int p = 0; 

  while (1) {
    int pp = ((double)status->CurrentStatus / status->TerminationValue) * 100;
    
    for(int i = 0; i < pp - p; i++) {
      int cur = p + i;
      if ((cur > 0) && (cur % 20 == 0)) printf("+");
      printf("-"); 
      fflush(stdout);
    }

    if (100 == pp) {
      printf("+");
      pthread_exit(NULL);      
    }
    p = pp;
  }
}
