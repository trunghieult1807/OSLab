#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t child_pid;
  FILE *fp;
  int myArray[1000];
  char line[100];
  int count = 0;
  if(!(fp = fopen("numbers.txt", "r"))) {
    printf("Open number.txt failed\n");
    exit(1);
  }
  while(fgets(line, 100, fp) != NULL) {
    sscanf(line, "%d", &myArray[count]);
    count++;
  }
  child_pid = fork();
  if(child_pid == -1) {
    perror("Cannot fork the program");
    exit(1);
  }
  if(child_pid == 0) {
    int output = 0;
    for(int i = 0; i < count; i++){
      if(myArray[i] % 3 == 0) {
        output++;
      }
    }
    printf("%d\n", output);
    fflush(stdout);
  }
  else {
    int output = 0;
    for(int i = 0; i < count; i++){
      if(myArray[i] % 2 == 0) {
        output++;
      }
    }
    printf("%d\n", output);
    fflush(stdout);
  }

  fclose(fp);
  return 0;
}
