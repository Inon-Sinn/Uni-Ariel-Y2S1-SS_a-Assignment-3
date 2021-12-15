#include <stdio.h>
#include "algo.h"

char* Atbash(char *dest,char *source){
    char *start = dest;
    while (*source != '\0')
    {
        if(65<=*source && *source <= 90)
            *dest = 90 - *source + 65;
        else
             *dest = 122 -  *source + 97;
        dest++;
        source++;
    }
    *dest = '\0';
    
    return start;
}