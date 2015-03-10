#include "queue.h"

void init(QUEUE *q) {
  q->head = -1;
  q->tail = -1;
}

/**
 * clear the queue. 
 */
void empty(QUEUE *q) {
  q->head = -1;
  q->tail = -1; 
}

/**
 * Add element into the queue.
 */
int enqueue(QUEUE *q, int el) {
  if(isFull(q)) return 0;

  q->tail++;
  q->queueArray[q->tail % SIZE] = el;
  return 1;
}

int dequeue(QUEUE *q) {
  int ret;

  if(isEmpty(q)) return -1;
  else {
    q->head++;
    ret = q->queueArray[q->head % SIZE];
    return ret;
  }
}

int isEmpty(QUEUE *q) {
  return (q->head == q->tail);
}

int isFull(QUEUE *q) {
  return ((q->tail - SIZE) == q->head);
}
