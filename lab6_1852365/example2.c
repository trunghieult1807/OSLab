#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#define NUM_TICKETS 35
#define NUM_SELLERS 4
#define true 1
#define false 0

static int numTickets = NUM_TICKETS;
static sem_t ticketLock;

void *sellTicket(void *arg);
int main(int argc , char **argv){
  int i;
  int tid [NUM_SELLERS];
  pthread_t sellers [NUM_SELLERS] ;
  sem_init(&ticketLock , 0, 1);
  for(i=0;i<NUM_SELLERS;i++){
    tid[i] = i;
    pthread_create(&sellers[i], NULL, sellTicket, (void *) tid[i]);
  }
  for(i=0;i<NUM_SELLERS;i++) {
    pthread_join( sellers [ i ] , NULL);
  }
  sem_destroy(&ticketLock ) ;
  pthread_exit(NULL);
  return 0 ;
}
void *sellTicket(void *arg){
  int done = false;
  int numSoldByThisThread = 0;
  int tid = (int) arg;
  while(!done){
    sleep(1);
    sem_wait(&ticketLock );
    if(numTickets == 0){
      done = true;
    }
    else{
      numTickets−−;
      numSoldByThisThread++;
      printf("Thread %d sold one (%d left)\n", tid , numTickets);
    }
    sem_post(&ticketLock ) ;
    sleep(1);
  }
  printf("Thread %d sold %d tickets\n", tid , numSoldByThisThread);
  pthread_exit(NULL);
}
