#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include "defs.h"

#define SIZE 100

typedef struct {
  int head; 
  int tail;
  int queueArray[SIZE];
  
} QUEUE;

// queue operators.
void init(QUEUE *q);      
void empty(QUEUE *q);
int enqueue(QUEUE *q, int val);  
int dequeue(QUEUE *q);
int isEmpty(QUEUE *q);
int isFull(QUEUE *q);

#endif
