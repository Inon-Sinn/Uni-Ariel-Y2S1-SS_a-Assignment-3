#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo.h"

//I could the define the Strings: Word and text here

#define word 30
#define Txt 256



int main(){
// collect the texts, check if there will be a problem with an input that has text after ~
    char text[Txt];
    char Word[word];
    scanf("%s",Word);
    scanf("%[^~]",text);
    printf("The word you gave is:'%s'\n",Word);
    printf("The text you gave is:%s",text);

// TODO still untested
    int i;
    
    //print the Gematira Sequences
    printf("Gematria Sequences: ");
    int Gvalue = GematriaValue(Word);
    for (i = 0; i < strlen(text); i++){
       GematriaSequence(text,i,Gvalue);
    }
    
    //print the Atbash Sequences
    printf("\nAtbash Sequences: ");
    char atbashWord[word];
    Atbash(atbashWord,Word);
    for (i = 0; i < strlen(text); i++){
       if(text[i]==atbashWord[0])
            AtbashSequences(text,i,atbashWord);
    }

    //print the Anagram Sequences
    printf("\nAnagram Sequences: ");
    for (i = 0; i < strlen(text); i++){
       if(contains(Word,text[i]))
            AnagramSequences(text,i,Word);
    }
    
    return 0;
}

char* copy(char *dest,char *source){
    char *start = dest;
    while (*source != '\0')
    {
        *dest = *source;
        dest++;
        source++;
    }
    
    return start;
}

// Retuns the given word into its Atbash form





//char, char

    // char input;
    // char w[word];   
    // // Recieving user input for word
    // int i = 0;
    // while (input != '\n' && input != '\t' && input != ' ')
    // {
    //     scanf("%c", &input);
    //     if (input == '\n' || input == '\t' || input == ' ')
    //     {
    //         break;
    //     }
    //     if (i == 30)
    //     {
    //         break;
    //     }
    //     w[i] = input;
    //     ++i;
    // }
    // for (i = 0; i <= strlen(w); i++)
    // {
    //     printf("%d ",w[i]);
    // }
    

    // char w[word];
    // char letter;
    // scanf("%c",&letter);
    // while (letter!=' ' && letter!= '\t' && letter != '\n')
    // {
    //     strcat(w,&letter);
    //     scanf("%c",&letter);
    // }
    // char text[Txt];
    // while (letter !='~')
    // {
    //     if(letter!='\n')
    //         strcat(text,letter);
    //      scanf("%c",&letter);
    // }
    // printf("The word you gave is:'%s'\n",w);
    // printf("The text you gave is:%s",text);