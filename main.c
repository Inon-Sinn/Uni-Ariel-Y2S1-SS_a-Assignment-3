#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo.h"

//I could the define the Strings: Word and text here

#define word 30
#define Txt 256

char* copy(char *dest,char *source);

void scan_Once(char *Word,char *text);

void scan_ByChar(char *Word, char *text);

int main(){
    // collect the texts, check if there will be a problem with an input that has text after ~
    char text[Txt+1];
    char Word[word+1];
    scan_Once(Word,text);
    //TODO - this is only to test so Remove it
    printf("The word you gave is:'%s'\n",Word);
    printf("The text you gave is:'%s'\n",text);

    //TODO still untested
    int i;

    //print the Gematira Sequences
    printf("Gematria Sequences: ");
    int Gvalue = GematriaValue(Word);
    for (i = 0; i < strlen(text); i++){
        if ((65<=text[i] && text[i] <= 90)||(97<=text[i] && text[i] <=122))
            GematriaSequence(text,i,Gvalue);
    }
    
    // //print the Atbash Sequences
    // TODO one too long?
    printf("\nAtbash Sequences: ");
    char atbashWord[word];
    Atbash(atbashWord,Word);
    for (i = 0; i < strlen(text); i++){
        if(text[i]==atbashWord[0])
            AtbashSequencesForward(text,i,atbashWord);
        else if(text[i]==atbashWord[strlen(Word)-1])
            AtbashSequencesBackward(text,i,atbashWord);
    }

    // //print the Anagram Sequences
    printf("\nAnagram Sequences: ");
    // for (i = 0; i < strlen(text); i++){
    //    if(contains(Word,text[i]))
    //         AnagramSequences(text,i,Word);
    // }
    
    return 0;
}



//Scans the input - my answer
void scan_Once(char *Word,char *text){
    scanf("%s",Word);
    scanf("%[^~]",text);
}

// What everyone did - Langweilig aka boring
void scan_ByChar(char *Word, char *text){
    char input;
    char *start = Word;

    //Collect the word
    scanf("%c", &input);
    while (input != '\n' && input != '\t' && input != ' '){
        *start = input;
        start++;
        scanf("%c", &input);
    }
    *start = '\0';

    //Collect the Text
    char *start2 = text;
    while (input != '~'){
                *start2 = input;
        start2++;
        scanf("%c", &input);
    }
    *start2 = '\0';
}


char* copy(char *dest,char *source){
    char *start = dest;
    while (*source != '\0')
    {
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
    return start;
}
