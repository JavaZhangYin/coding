#include <unistd.h>
#include <pthread.h>
#include "defs.h"
#include "consumer.h"
#include "reports.h"

void consumer_lucy(CANDY_COMPANY *cc) 
{  
  while (TRUE) {
    sem_wait(&cc->sem_candy); 
    if(isEmpty(cc->stat->belt_queue) == FALSE) {
      int c = dequeue(cc->stat->belt_queue);

      if(FROG_BITES_CANDY == c) {
	cc->stat->frog--;
	cc->stat->lucy_frog++;
	report(cc->stat, "Lucy consumed crunchy frog bite."); 
      } else if(ESCARGOT_CANDY == c) {
	cc->stat->lucy_escargot++; 
	cc->stat->escargot--;
	report(cc->stat, "Lucy consumed escargot sucker."); 
      } else {
	perror("error candy type."); 
      }
    }
    sem_post(&cc->sem_candy);
    if((cc->stat->total >= TOTAL_CANDY_PROD) && (isEmpty(cc->stat->belt_queue) == 1))
      pthread_exit(0);
    sleep(cc->delays->delay_lucy / 1000);
  }
}

void consumer_ethel(CANDY_COMPANY *cc) {
  while (TRUE) {
    sem_wait(&cc->sem_candy); 

    if(isEmpty(cc->stat->belt_queue) == FALSE) {
      int c = dequeue(cc->stat->belt_queue);
      
      if(FROG_BITES_CANDY == c) {
	cc->stat->ethel_frog++;
	cc->stat->frog--;
	report(cc->stat, "Ethel consumed crunchy frog bite."); 
      } else if(ESCARGOT_CANDY == c) {
	cc->stat->ethel_escargot++; 
	cc->stat->escargot--;
	report(cc->stat, "Ethel consumed escargot sucker.");
      } else {
	perror("error candy type.");
      }
    }
    sem_post(&cc->sem_candy);
    if((cc->stat->total >= TOTAL_CANDY_PROD) && (isEmpty(cc->stat->belt_queue) == 1))
      pthread_exit(0);

    sleep(cc->delays->delay_ethel / 1000);
  }
}
