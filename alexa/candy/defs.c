#include "defs.h"

void init_belt(BELT_STATUS *st) {
  st->belt_queue = NULL; 
  st->total = 0; 
  st->frog = 0; 
  st->escargot = 0; 
  
  st->lucy_frog = 0;
  st->lucy_escargot = 0; 
  st->ethel_frog = 0; 
  st->ethel_escargot = 0;

  st->frog_cnt = 0; 
  st->escargot_cnt = 0; 
}

void init_delays(DELAYS *delays) {
  delays->delay_frog = 0; 
  delays->delay_escargot = 0; 
  delays->delay_lucy = 0; 
  delays->delay_ethel = 0;
}

void init_cc(CANDY_COMPANY *cc) {
  cc->stat = NULL; 
  cc->delays = NULL;
}
