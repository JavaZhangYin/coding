#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h> 

// handlers for producers and consumers. 
void producer_frog(queue<int> &cq);
void producer_escargot(queue<int> &cq);
void consumer_lucy(queue<int> &cq); 
void consumer_ethel(queue<int> &cq); 

int main(int argc, char* argv[]) {

  // option variables. 
  int delay_ethel = 0; // delay in milliseconds for ethel. 
  int delay_lucy = 0;	// delay for lucy. 
  int delay_frog = 0; // delay for producing frog. 
  int delay_escargot = 0; // delay for producing the escargot candy. 

  // handle options. 
  while ((c = getopt (argc, argv, "ELfe:")) != -1)
    switch (c)
      {
      case 'E':
        delay_ethel = optarg;
        break;
      case 'L':
        delay_lucy = optarg;
        break;
      case 'f':
        delay_frog = optarg;
        break;
      case 'e':
	delay_escargot = optarg; 
	break; 
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  // queue for candies. 
  queue<int> candy_queue; 

  // threads.
  pthread_t ths[4];
  
  int r[4];
  r[0] = pthread_create(&ths[0], NULL, (void *)&producer_frog, (void *)candy_queue); 
  r[1] = pthread_create(&ths[1], NULL, (void *)&producer_escargot, (void *)candy_queue); 
  r[2] = pthread_create(&ths[2], NULL, (void *)&consumer_lucy, (void *)candy_queue); 
  r[3] = pthread_create(&ths[3], NULL, (void *)&consumer_ethel, (void *)candy_queue); 

  // error checking. 
  if (r[0] + r[1] + r[2] + r[3]){
    printf("Error creating thread for producer frog - %d\n", r);
    exit(-1);
  }

  // join. 
  void *join_status;
  int rv[4];
  for(int i = 0; i < 4; i++) {
    rv[i] = pthread_join(ths[i], &join_status); 
    if (rv[i]) {
      perror("Error doing pthread_join." );
      exit(-1); 
    }
  }
 
  return 0; 
  pthread_exit(NULL);
}

// when to stop? 

void producer_frog(queue<int> &cq) {
  // use 0 to represent frog candy. 
  cq.push(0); 
  pthread_exit(NULL); 
}

void producer_escargot(queue<int> &cq) {
  // escargot candy
  cq.push(1); 
  pthread_exit(NULL); 
}

void consumer_lucy(queue<int> &cq) {
  // consume a candy from queue. 
  int ret = cq.front();
  cq.pop(); 
  pthread_exit(NULL); 
}

void consumer_ethel(queue<int> &cq) {
  int ret = cq.front();
  cq.pop(); 
  pthread_exit(NULL); 
}
