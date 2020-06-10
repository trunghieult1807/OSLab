#include <stdio.h>
#include <stdlib.h>
int *a [100000];
int main() {
  int i;
  for (i = 0; i < 100000; i++) {
    if ((a[i] = (int*)malloc((1 << 10) * sizeof(int))) == NULL) {
      break;
    }
  }
  printf("Created %d 4KB memory region(s)\n", i);
  free(a[0]), free(a[2]);
  int * b = (int*)malloc((1 << 11) * sizeof(int));
  if (b == NULL) {
    printf("Cannot allocate more memory\n");
  }

  else {
    printf("Allocated a new 8KB memory region\n");
  }
}
