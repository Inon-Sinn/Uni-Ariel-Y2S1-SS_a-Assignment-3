#include <stdio.h>
#include "algo.h"
#include <string.h>

// Remove afterwards
int firstGematria = 1;
int firstAtbash = 1;
int firstAnagram = 1;

void printSubString(char *text,int start, int end, int first);
void removeOnce(char* wordCopy,char c);
char *strrev(char *str);

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

// >>>bee beeb~ -> bee~eeb
void GematriaSequence(char *text, int pos, int GValue){
    char *start = text;
    int currentPos = pos;
    int curVal =0;
    while (start[currentPos]!='\0' && curVal<GValue)        {
        curVal+=GematriaCharValue(start[currentPos]);
        currentPos++;
    }
    if(curVal==GValue){
        if(firstGematria){
            printSubString(text,pos,currentPos,firstGematria);
            firstGematria=0;
        }
        else printSubString(text,pos,currentPos,firstGematria);
    }
}

void AtbashSequencesForward(char *text, int pos,char *atbashW){
    char *start = text;
    int currentPos = pos;
    int atbashPos = 0;
    int found = 0;
    int valid = 1;
    while (start[currentPos]!='\0' && found==0 && valid)
    {
        if(atbashPos == strlen(atbashW))
            found = 1;
        if(start[currentPos]!=' '){
            if(start[currentPos] != atbashW[atbashPos])
                valid=0;//TODO break;//check it goes out of the while
            else atbashPos++;
        }
        currentPos++;
    }
    if(found){
        if(firstAtbash){
            printSubString(text,pos,currentPos,firstAtbash);
            firstAtbash=0;
        }
        else printSubString(text,pos,currentPos,firstAtbash);
    }
}

 
void AtbashSequencesBackward(char *text, int pos,char *atbashW){
    strrev(atbashW);//TODO check if its sends the reversed string
    AtbashSequencesForward(text,pos,atbashW);
}

void AnagramSequences(char *text, int pos,char *w){
    char *start = text;
    int currentPos = pos;
    char copy[strlen(w)+1];
    strcpy(copy,text);
    int found = 0;
    int valid = 1;
    while (start[currentPos]!='\0' && found==0 && valid)
    {
        if(strlen(copy)==0)// TODO check if it will work
            found=1;
        else if((65<=start[currentPos] && start[currentPos] <= 90)||(97<=start[currentPos] && start[currentPos] <=122)){
            if (contains(copy,start[currentPos]))
                removeOnce(copy,start[currentPos]);
            else valid=0;//TODO check if breack would work here
        }
        currentPos++;
    }
    if(found){
        if(firstAnagram){
            printSubString(text,pos,currentPos,firstAnagram);
            firstAnagram=0;
        }
        else printSubString(text,pos,currentPos,firstAnagram);
    }
}

//TODO check when it works if you can change int to int* - giving &firstGematria and so on
void printSubString(char *text,int start, int end, int first){
    int length = end-start+1;
    char subtext[length];
    strncpy(subtext,&text[start],length-1);
            subtext[length-1] = '\0';
    if(first)
        printf("%s",subtext);
    else printf("~%s",subtext);
}

//TODO check the code
void removeOnce(char* wordCopy,char c){
    int pos = 0;
    while(wordCopy[pos] != c && wordCopy[pos]!='\0')
        pos++; 
    memmove(&wordCopy[pos], &wordCopy[pos + 1], strlen(wordCopy) - pos);
}

//strrev isn't implemented in linux
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}



