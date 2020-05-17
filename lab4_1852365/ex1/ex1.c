#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "ex1.h"

char Mymemory[20000] = {'\0'};
char *head = Mymemory;
char alocatedFlag = 'a';
char freeFlag = 'f';
char endFlag = 'e';


void* aligned_malloc(unsigned int size , unsigned int align) {
  //Check for multiple of align
  intptr_t n = head;
  if(n % align != 0){
      int a = align - (n % align);
      head += a;
  }

  if(!*head){
      *(head + 19999) = endFlag;
      *(int *)(head +1) = 19999;
      *head = freeFlag;
  }
  if(!size){
    return NULL;
  }


  char *nextblock = head;
  int blocksize;
  char *bestblck = NULL;
  int bestblocksize = -1;

  while(*nextblock != endFlag){
    blocksize = *(int *)(nextblock+1);
    if((*nextblock == freeFlag) && blocksize >= size + 5){
      bestblck = nextblock;
      bestblocksize = blocksize;
    }
    nextblock = nextblock + blocksize;
  }

  if(bestblck){
    int num = *(int *)(bestblck +1);
    *(bestblck) = alocatedFlag;
    *(int *)(bestblck+1) = size + 5;
    if(*(bestblck + size+5) != endFlag){
      *(bestblck + size+5) = freeFlag;
      *(int *)(bestblck + size+6) = num - size - 5;
      }
  }
  else{
    printf("Not enough memory ");
  }
  return (void *)bestblck;
}

void *aligned_free(void *ptr) {
  char *block = (char *)ptr;
  int blocksize;
  char *nextblock = head;
  char *backblock;
  while((nextblock != block )){
    blocksize = *(int *)(nextblock+1);
    if(*nextblock == endFlag){
      printf("Invalid address");
      break;
    }
    backblock = nextblock;
    nextblock = nextblock + blocksize;
  }
  if(*nextblock != endFlag){
    *nextblock = freeFlag;

    int num = *(int *)(nextblock+1);
    char *isNextblockFree = nextblock + num;

    if(*isNextblockFree == freeFlag){     //if next block is free -> merge
      *(int *)(nextblock+1) = *(int *)(nextblock + 1) +  *(int *)(isNextblockFree+1);
    }
    if(*backblock == freeFlag){     //if previous block is free -> merge
      *(int *)(backblock+1) = *(int *)(backblock+1)+  *(int *)(nextblock+1);
    }
  }
  else {
    printf("Invalid address");
  }

  return NULL;
}


void printMemory() {
  char *nextblock = head;
  int blocksize;
  while(*nextblock != endFlag) {
    blocksize = *(int *)(nextblock+1);
    printf("%c   ",*nextblock);
    printf("Address: %p  ", nextblock);
    printf("Block size: %d\n",*(int *)(nextblock+1));
    nextblock = nextblock + blocksize;
  }
  printf("++++++++\n");
}
