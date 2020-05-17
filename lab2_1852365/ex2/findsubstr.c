#include "findsubstr.h"

int find_sub_string(const char *str, const char *sub) {
    const char *charStr = str;
    const char *charSub = sub;
    int countStr = 0;
    while(*charStr != '\0') {
        countStr++;
        charStr++;
    }
    int countSub = 0;
    while(*charSub != '\0') {
        countSub++;
        charSub++;
    }
    const char *tempStr = str;
    const char *tempSub = sub;
    int count = 0;
    for(int i = 0; i < countStr; i++) {
        if(*tempStr == *tempSub) {
            tempSub++;
            count++;
            if(count == countSub) {
                return i - countSub + 1;
            }
        }
        else {
            tempSub = sub;
            count = 0;
            
        }
        tempStr++;
    }
    return -1;
}
