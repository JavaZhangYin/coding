#include "producer.h"

void producer_frog(CANDY_COMPNAY *cc) {
  while (true) {
    sem_wait(&cc->sem_candy); 
    if(isFull(cc->stat->belt_queue) && 
      (cc->stat->frog < 3)) {

      enqueue(cc->stat->belt_queue, FROG_BITES_CANDY);
      cc->stat->frog++;
      cc->stat->total++; 
      report(cc->stat, "Added crunchy frog bite.");

    }
    sem_post(&cc->sem_candy);

    if(cc->stat->total >= TOTAL_CANDY_PROD) 
      pthread_exit(0);

    sleep(cc->delays->delay_frog / 1000); 
  }
}

void producer_escargot(CANDY_COMPNAY *cc) {
  while (true) {
    sem_wait(&cc->sem_candy); 
    if(isFull(cc->stat->belt_queue) == 0) {
      enqueue(cc->stat->belt_queue, ESCARGOT_CANDY);
      cc->stat->escargot++;
      cc->stat->total++;
      report(cc->stat, "Added escargot sucker.");
    }
    sem_post(&cc->sem_candy);
    if(cc->stat->total >= TOTAL_CANDY_PROD) 
      pthread_exit(0); 

    sleep(cc->delays->delay_escargot / 1000);
  }
}
