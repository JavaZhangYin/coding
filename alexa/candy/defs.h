#ifndef _DEFS_H_
#define _DEFS_H_

#include <semaphore.h>
#include "queue.h" 

#define TRUE 1
#define FALSE 0

#define FROG_BITES_CANDY 0
#define ESCARGOT_CANDY 1
#define TOTAL_CANDY_PROD 100 /* total candies to produce. */
#define TOTAL_CANDY_BELT 10  /* maximum candies on belt. */

typedef struct {
  QUEUE *belt_queue; 
  int total; 	
  int frog; 	
  int escargot; 

  // consumer statistics.
  int lucy_frog; 
  int lucy_escargot; 
  int ethel_frog; 
  int ethel_escargot; 

  // producer statistics.
  int frog_cnt; 
  int escargot_cnt;
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

void init_belt(BELT_STATUS *st); 
void init_cc(CANDY_COMPANY *cc); 
void init_delays(DELAYS *); 
#endif
