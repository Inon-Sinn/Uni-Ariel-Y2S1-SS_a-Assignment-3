#include <stdio.h>
#include "algo.h"
#include <string.h>

int firstGematria = 1;
int firstAtbash = 1;
int firstAnagram = 1;

void printSubString(char *text,int start, int end, int *first);

void removeOnce(char* wordCopy,char c);

char *strrev(char *str);

//Returns the given string in its Atbash from
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

// Returns the GematriaValue of a Word
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

//Returns the Gematria value of a char
int GematriaCharValue(char c){
    int res = 0;
    if(65<=c && c <= 90)
        res += c - 64;
    if(97<=c && c <=122)
        res += c - 96;
    return res;
}

//Return true if the given character is in the given word, False else
int contains(char *w,char character){
    while (*w!='\0')
    {
        if(character==*w)
            return 1;
        w++;
    }
    return 0;
}

// gets a placement in the text an if its the start of an GematriaSequence, it will print the Sequence
void GematriaSequence(char *text, int pos, int GValue){
    char *start = text;
    int currentPos = pos;
    int curVal =0;
    while (start[currentPos]!='\0' && curVal<GValue)        {
        curVal+=GematriaCharValue(start[currentPos]);
        currentPos++;
    }
    if(curVal==GValue){
        printSubString(text,pos,currentPos,&firstGematria);
    }
}

// gets a placement in the text an if its the start of an AtbashSequences, it will print the Sequence
void AtbashSequencesForward(char *text, int pos,char *atbashW){
    char *start = text;
    int currentPos = pos;
    int atbashPos = 0;
    int found = 0;
    while (start[currentPos]!='\0' && found==0)
    {
        if(start[currentPos]!=' '){
            if(start[currentPos] != atbashW[atbashPos])
                break;
            else atbashPos++;
            if(atbashPos == strlen(atbashW)){
                found = 1;
            }
        }
        currentPos++;
    }
    if(found){
        printSubString(text,pos,currentPos,&firstAtbash);
    }
}

 // gets a placement in the text an if its the start of an AtbashSequences, it will print the Sequence
void AtbashSequencesBackward(char *text, int pos,char *atbashW){
    strrev(atbashW);
    AtbashSequencesForward(text,pos,atbashW);
    strrev(atbashW);
}

// gets a placement in the text an if its the start of an AnagramSequences, it will print the Sequence
void AnagramSequences(char *text, int pos,char *w){
    char *start = text;
    int currentPos = pos;
    char copy[strlen(w)];
    strcpy(copy,w);
    int found = 0;
    while (start[currentPos]!='\0' && found==0)
    {
        if(contains(copy,start[currentPos])){
            removeOnce(copy,start[currentPos]);
            if(strlen(copy)==0)
                found=1;
        }
        else if(start[currentPos]!=' ')
           break;
        currentPos++;
    }
    if(found){
        printSubString(text,pos,currentPos,&firstAnagram);
    }
}

// Prints a Substring from a given text
void printSubString(char *text,int start, int end, int *first){
    int length = end-start+1;
    char subtext[length];
    strncpy(subtext,&text[start],length-1);
            subtext[length-1] = '\0';
    if(*first){
        printf("%s",subtext);
        *first = 0;
    }
    else printf("~%s",subtext);
}

//Removes the first occurrence of the specified in the given word
void removeOnce(char* wordCopy,char c){
    int pos = 0;
    while(wordCopy[pos] != c && wordCopy[pos]!='\0')
        pos++; 
    memmove(&wordCopy[pos], &wordCopy[pos + 1], strlen(wordCopy) - pos);
}

//Reverse a given string, strrev isn't implemented in linux
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



