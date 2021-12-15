#include <stdio.h>
#include "algo.h"

// Remove afterwards
int firstGematria = 1;
int firstAtbash = 1;
int firstAnagram = 1;

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

int GematriaCharValue(char c){
    int res = 0;
    if(65<=c && c <= 90)
        res += c - 64;
    if(97<=c && c <=122)
        res += c - 96;
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

    void GematriaSequence(char *text, int pos, int GValue){
        char *start = text;
        int currentPos = pos;
        int curVal =0;
        while (start[currentPos]!='\0' && curVal<GValue)
        {
            curVal+=GematriaCharValue(start[currentPos]);
            currentPos++;
        }
        if(curVal==GValue){
            int length = currentPos-pos+1;
            char subtext[length];
            strncpy(subtext,&text[pos],length-1);
            subtext[length-1] = '\0';
            if(firstGematria){
                firstGematria=0;
                printf("%s",subtext);
            }
            else printf("~%s");
        }
    }

    void AtbashSequences(char *text, int pos,char *atbashW){
        printf("%d,",counter2++);
    }

    void AnagramSequences(char *text, int pos,char *w){
        printf("%d,",counter3++);
    }
