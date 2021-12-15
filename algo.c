#include <stdio.h>
#include "algo.h"

// Remove afterwards
int counter1 = 1;
int counter2 = 1;
int counter3 = 1;

char* Atbash(char *dest,char *source){
    char *start = dest;
    while (*source != '\0')
    {
        if(65<=*source && *source <= 90)
            *dest = 90 - *source + 65;
        else if(97<=*source && *source <=122)
                *dest = 122 -  *source + 97;
        else *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
    
    return start;
}

int GematriaValue(char *w){
    int res = 0;
    while (*w!='\0')
    {
        if(65<=*w && *w <= 90)
            res += *w - 64;
        if(97<=*w && *w <=122)
            res += *w - 96;
        w++;
    }
    return res;
    
}

int contains(char *w,char character){
    while (*w!='\0')
    {
        if(character==*w)
            return 1;
        w++;
    }
    return 0;
}

    void GematriaSequence(char *txt, int pos, int GValue){
        printf("%d,",counter1++);
    }

    void AtbashSequences(char *txt, int pos,char *atbashW){
        printf("%d,",counter2++);
    }

    void AnagramSequences(char *txt, int pos,char *w){
        printf("%d,",counter3++);
    }
