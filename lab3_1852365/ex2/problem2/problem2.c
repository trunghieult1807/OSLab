#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  printf("This is A with id: %d\n", getpid());
  //Create B
  pid_t fB = fork();
  if (fB > 0) {
    //MARK: In A
    //wait(NULL);
    //create C
    pid_t fC = fork();
    if(fC > 0) {
      //MARK: In A
      //wait(NULL);
      //create D
      pid_t fD = fork();
      if(fD > 0) {
        //wait(NULL);
      }
      if(fD == 0) {
          wait(NULL);
        printf("This is D with id: %d with parent id: %d\n", getpid(), getppid());
      }
    }
    if(fC == 0) {
        wait(NULL);
      printf("This is C with id: %d with parent id: %d\n", getpid(), getppid());
      //create G
      pid_t fG = fork();
      if(fG > 0) {
        wait(NULL);
      }
      if(fG == 0) {
        printf("This is G with id: %d with parent id: %d\n", getpid(), getppid());
      }
    }
  }
  if(fB == 0) {
    //MARK: In B
      wait(NULL);
    printf("This is B with id: %d with parent id: %d\n", getpid(), getppid());
    //create E
    pid_t fE = fork();
    if(fE > 0) {
      //create F
      //wait(NULL);
      pid_t fF = fork();
      if(fF == 0) {
        printf("This is F with id: %d with parent id: %d\n", getpid(), getppid());
      }
    }
    if(fE == 0) {
        wait(NULL);
      printf("This is E with id: %d with parent id: %d\n", getpid(), getppid());
      //create I
      pid_t fI = fork();
      if(fI == 0) {
        printf("This is I with id: %d with parent id: %d\n", getpid(), getppid());
      }
    }
  }
  char a;
  a = getchar();
  return 0;
}
