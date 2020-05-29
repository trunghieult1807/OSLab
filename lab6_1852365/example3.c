#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_ITEMS 1
#define THREADS 1
#define LOOPS 2*MAX_ITEMS

int buffer[MAX_ITEMS];
int fill = 0;
int use = 0;

sem_t empty;
sem_t full;

void put(int value);
int get();

void *producer(void *arg) {
	int i;
	int tid = (int) arg;
	for(i = 0; i < LOOPS; i++){
		sem_wait(&empty);
		put(i);
		printf("Producer %d put data %d\n", tid, i);
		sleep(1);
		sem_post(&full);
	}
	pthread_exit(NULL);
}

void *consumer(void *arg){
	int i, tmp = 0;
	int tid = (int) arg;
	while(tmp != -1){
		sem_wait(&full);
		tmp = get();
		printf("Consumer %d get data %d\n", tid, tmp);
		sleep(1);
		sem_post(&empty);
	}
	pthread_exit(NULL);
}

int main(int argc, char **argv){
	int i, j;
	int tid[THREADS];
	pthread_t producers[THREADS];
	pthread_t consumers[THREADS];
	
	
	sem_init(&empty, 0, MAX_ITEMS);
	sem_init(&full, 0, 0);
	
	for(i = 0; i < THREADS; i++){
		tid[i] = i;
		pthread_create(&producers[i], NULL, producer, (void *)tid[i]);
		pthread_create(&consumers [i] , NULL, consumer, (void*)tid[i]);
	}
	
	for(i = 0; i < THREADS; i++){
		pthread_join(producers[i], NULL);
		pthread_join(consumers[i], NULL);
	}
	
	sem_destroy(&full);
	sem_destroy(&empty);
	
	return 0;
}

void put(int value){
	buffer[fill] = value;
	fill = (fill + 1) % MAX_ITEMS;
}

int get(){
	int tmp = buffer[use];
	use = (use + 1) % MAX_ITEMS;
	return tmp;
}
