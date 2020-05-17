// main.c
#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include "findsubstr.h"

int main(int argc, const char *argv[]) {
    int count = 1;
    FILE *fp;
    char line[100];
    
    if(!(fp= fopen(argv[1], "r"))) {
        printf("open %s failed\n", argv[1]);
        exit(1);
    }
    
    // Concatenate argv[]
    char temp[100000];
    int k = 0;
    
    if(argc > 2) {
        for(int i = 2; i < argc; i++) {
            if(i != 2) {
                temp[k] = ' ';
                k++;
            }


            while(*argv[i] != '\0') {
                temp[k] = *argv[i];
                argv[i]++;
                k++;
            }
        }
    }
    
    // Pass concatenated char array to sub pointer array
    char *sub = temp;
 
    while(fgets(line, 100, fp) != NULL) {
        if(find_sub_string(line, sub) != -1) {
            printf("Line %d: %s", count, line);
            if(find_sub_string(line, "\n") == -1) {
                printf("\n");
            }
        }
        count++;
        
    }
    
    fclose(fp);
    return 0;
}

