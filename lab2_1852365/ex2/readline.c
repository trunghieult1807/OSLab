#include "readline.h"
int read_line(char *str) {
    int count = 0;
    //char *temp = str;
    while (1) {
        count++;
        if(*str == '\0') {
            return -1;
        }
        else if(*str == '\n') {
            return count;
        }
        str++;
    }
}
