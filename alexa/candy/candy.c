#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h> 
#include <string.h> 
#include <semaphore.h> 
#include "queue.h"
#include "options.h"
#include "defs.h" 
#include "reports.h" 
#include "producer.h" 
#include "consumer.h" 


int main(int argc, char** argv) {
  sem_t sc;	    /* mutex to protect */
  sem_t tb;	    /* barrier for threads to reach the same state. */

  sem_init(&sc, 0, 1); 
  sem_init(&tb, 0, 0);
  
  // we use a queue to represent the candy convey belt. 
  // and a BELT_STATUS struc to represent the belt status.
  QUEUE *candy_belt = (QUEUE *)malloc(sizeof(QUEUE)); 
  BELT_STATUS *status = (BELT_STATUS *)malloc(sizeof(BELT_STATUS)); 
  DELAYS *delays = (DELAYS *)malloc(sizeof(DELAYS));
  if(!status || !candy_belt || !delays) {
    perror("error allocation memory for queue. \n"); 
    exit(-1);
  }
  
  init_belt(status);
  status->belt_queue = candy_belt; 
  init_delays(delays); 

  parseOptions(argc, argv, delays);
 
  CANDY_COMPANY *cc1 = (CANDY_COMPANY *)malloc(sizeof(CANDY_COMPANY));
  if(!cc1) {
    perror ("Error creating a candy company object.");
    exit(-1); 
  }
  cc1->stat = status; 
  cc1->delays = delays;
  cc1->sem_candy = sc; 
  cc1->barrier = tb;  

  ///////////////////////////////////////////
  // threads for producers and consumers.
  ///////////////////////////////////////////
  // producer threads. 
  pthread_t frog_bites, escargot_suckers; 
  
  int th; 
  th = pthread_create(&frog_bites, NULL, (void *)&producer_frog, (CANDY_COMPANY *)cc1);
  th = pthread_create(&escargot_suckers, NULL, (void *)&producer_escargot, (CANDY_COMPANY *)cc1);

  // consumer threads. 
  pthread_t thread_lucy, thread_ethel; 

  pthread_create(&thread_lucy, NULL, (void *)&consumer_lucy, (CANDY_COMPANY *)cc1);
  pthread_create(&thread_ethel, NULL, (void *)&consumer_ethel, (CANDY_COMPANY *)cc1);

  // the main thread will wait for the children threads to finish. 
  pthread_join(frog_bites, NULL);
  pthread_join(escargot_suckers, NULL);
  pthread_join(thread_lucy, NULL);
  pthread_join(thread_ethel, NULL); 

  // report the final status.
  summaryReport(cc1->stat);

  exit(0); 
}
