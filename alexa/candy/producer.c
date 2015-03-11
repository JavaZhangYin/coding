#include <unistd.h> // for sleep function. 
#include <pthread.h>
#include "producer.h"
#include "reports.h"
       
void producer_frog(CANDY_COMPANY *cc) {
  while (TRUE) {
    // printf("frog candy producer. ......\n");
    sem_wait(&cc->sem_candy); 
    if(cc->stat->total < TOTAL_CANDY_PROD && 
       isFull(cc->stat->belt_queue) == FALSE && 
      (cc->stat->frog < 3)) {

      enqueue(cc->stat->belt_queue, FROG_BITES_CANDY);
      cc->stat->frog++;
      cc->stat->total++; 
      cc->stat->frog_cnt++;
      report(cc->stat, "Added crunchy frog bite.");

    }
    sem_post(&cc->sem_candy);

    if(cc->stat->total >= TOTAL_CANDY_PROD) 
      pthread_exit(0);

    sleep(cc->delays->delay_frog / 1000); 
  }
}

void producer_escargot(CANDY_COMPANY *cc) {
  while (TRUE) {
    // printf("escargot candy producer. ......\n");
    sem_wait(&cc->sem_candy); 
    if(cc->stat->total < TOTAL_CANDY_PROD && 
       isFull(cc->stat->belt_queue) == FALSE) {
      enqueue(cc->stat->belt_queue, ESCARGOT_CANDY);
      cc->stat->escargot++;
      cc->stat->total++;
      cc->stat->escargot_cnt++; 
      report(cc->stat, "Added escargot sucker.");
    }
    sem_post(&cc->sem_candy);
    if(cc->stat->total >= TOTAL_CANDY_PROD) 
      pthread_exit(0); 

    sleep(cc->delays->delay_escargot / 1000);
  }
}
