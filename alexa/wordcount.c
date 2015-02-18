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
  printf("There are %ld words in the file. \n", wc); 

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
  pid_t pid = fork(); 
  // read byte by byte. 
  char c; 
  do {

    
    if(pid == 0) {
      printf("child --> %d\n", pid); 
      fflush(stdout);
      status->CurrentStatus = byteCnt; 
      progress_monitor(status);
      
    } else if (pid > 0) {
      //printf("parent.\n"); 
      fflush(stdout);
      byteCnt++; 
      if(isspace(c)) wc++; 
    } else {
      //printf("error.");
      fflush(stdout);
      perror("Fork failed..."); 
      return -1; 
    }

  } while((c = fgetc(file)) != EOF); 

  if (pid > 0) {
    pid_t wpid; 
    int sts = 0;
    while((wpid = wait(&sts)) >= 0) printf("Exit status of %d is %d.\n", (int)wpid, sts);
    return wc; 
  } else return wc; 
}

void progress_monitor(PROGRESS_STATUS *status) {
  static int p = 0; 
  int pp = ((double)status->CurrentStatus / status->TerminationValue) * 100;

  for(int i = 0; i < pp - p; i++) printf("-"); 
  if(pp > p && pp > 0 && (pp % 20) == 0) printf("+");
  //printf("%d, %d\n", p, pp);
  if(p == 100) printf("+\n"); 

  p = pp;
}
