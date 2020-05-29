#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


static volatile long int counter = 0;
pthread_mutex_t lock;
void *mythread(void *arg){
  printf("%s: begin\n", (char *) arg);

  pthread_mutex_lock(&lock);
  for (long int i = 0; i < 1e7; i++) {
    counter = counter + 1;
    // if(i%100==0){
    //   printf("%ld\n", i);
    // }
  }
  pthread_mutex_unlock(&lock);
  printf("%s: done\n", (char *) arg);
  return NULL;
}
int main(int argc, char *argv[]) {
  pthread_t p1 , p2 ;
  int rc;
  printf("main: begin (counter = %ld)\n", counter);
  rc = pthread_create(&p1 , NULL, mythread , "A" );
  assert(rc==0);

  rc = pthread_create(&p2 , NULL, mythread , "B" );
  assert(rc==0);
  // join waits for the threads to finish
  rc = pthread_join(p1, NULL);
  assert(rc==0);
  rc = pthread_join(p2, NULL);
  assert(rc==0);
  printf("main: done with both (counter = %ld)\n", counter);
  return 0;
}
