#include <sys/syscall.h>
#include <stdio.h>
#define SIZE 10
int main()
{
  long sysvalue;
  unsigned long info[SIZE];
  sysvalue = syscall (546, 1, info);
  printf("My MSSV: %lu\n", info [0]);
}
