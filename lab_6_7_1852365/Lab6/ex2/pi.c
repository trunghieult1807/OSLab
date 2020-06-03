#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define NUM_THREADS 10000

long double pi = 0.0;
pthread_mutex_t piLock;
long numOfPoints;
clock_t start, end;


void *calPi(void *tid) {
    long double x, width, area = 0;
    int threadID = *((int*)tid);

    width = 1.0 / numOfPoints ;

    for(int i = threadID; i < numOfPoints; i += NUM_THREADS) {
        x = (i+0.5) * width;
        area += 4.0 / (1.0 + x*x);
    }

    area *= width;
    pthread_mutex_lock(&piLock);
    pi += area;
    pthread_mutex_unlock(&piLock);

    return NULL;
}
int main (int argc, char *argv[]) {
    time_t start, end;
    //start = time(NULL);
    start = clock();

    pthread_t threads[NUM_THREADS];
    void *retVal;
    int threadID[NUM_THREADS];

   if (argc == 2) {
      numOfPoints = atol(argv[1]);
      pthread_mutex_init(&piLock, NULL);

      for (int i = 0; i < NUM_THREADS; i++) {
        threadID[i] = i;
        pthread_create(&threads[i], NULL, calPi, &threadID[i]);
      }

      for (int i = 0; i < NUM_THREADS; i++) {
         pthread_join(threads[i], &retVal);
      }
      printf("%0.40Lf \n", pi);
    }
    else {
      printf("Need an argument!\n");
    }

    //end = time(NULL);
    end = clock();
    printf("Running time: %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    return 0;
}
