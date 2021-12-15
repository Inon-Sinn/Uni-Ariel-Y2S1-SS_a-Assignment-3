#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo.h"

#define word 30
#define Txt 256

// char* Atbash(char* dest,char* source);

int main(){
// collect the texts, check if there will be a problem with an input that has text after ~
    //char text[Txt];
    char Word[word];
    scanf("%s",Word);
    //scanf("%[^~]",text);
    // printf("The word you gave is:'%s'\n",Word);
    // printf("The text you gave is:%s",text);
    char abeshWord[word];
    Atbash(abeshWord,Word);
    printf("\nThe Atbash Word is: %s",abeshWord);

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