#ifndef _DEFS_H_
#define _DEFS_H_

#include <semaphore.h>
#include "queue.h" 

const int FROG_BITES_CANDY = 0; 
const int ESCARGOT_CANDY = 1;
const int TOTAL_CANDY_PROD = 100; /* total candies to produce. */
const int TOTAL_CANDY_BELT = 10;  /* maximum candies on belt. */

typedef struct {
  QUEUE *belt_queue;       /* queue to maintain list of candies produced. */
  int total; 			/* total candies produced so far. */
  int frog; 			/* count of frog candies so far. */
  int escargot; 		/* count of escargot candies so far. */

  // consumer statistics.
  int lucy_frog; 
  int lucy_escargot; 
  int ethel_frog; 
  int ethel_escargot; 
} BELT_STATUS; 

typedef struct {
  int delay_frog;
  int delay_escargot; 
  int delay_lucy; 
  int delay_ethel; 
} DELAYS; 

typedef struct {
  BELT_STATUS *stat;
  DELAYS *delays; 
  // add mutex and barrier.

  sem_t sem_candy; 
  sem_t barrier; 

} CANDY_COMPANY; 

#endif
