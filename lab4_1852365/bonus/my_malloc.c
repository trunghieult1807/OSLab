#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size) {
  void *ptr;
  ptr = sbrk(0);
  if (sbrk(size) == (void *)-1) {
    return NULL;
  }
  return ptr;
}
