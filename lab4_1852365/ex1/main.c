#include <stdlib.h>
#include <stdio.h>
#include "ex1.h"
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  printf("Allocate x: \n");
    char *x = (char*)aligned_malloc(50,64);
    printMemory();
    printf("Allocate y: \n");
    char *y = (char*)aligned_malloc(55,64);
    printMemory();
    printf("Allocate z: \n");
    char *z = (char*)aligned_malloc(60,64);
    printMemory();
    printf("Free x: \n");
    aligned_free(x);
    printMemory();
    printf("Free y: \n");
    aligned_free(y);
    printMemory();

    return 0;
}
