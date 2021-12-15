#ifndef _algo_
#define _algo_

//w - word,txt - the Text

    char* Atbash(char* dest,char* source);

    int GematriaValue(char *w);

    int contains(char *w,char character);

    void GematriaSequence(char *text, int pos, int GValue);

    void AtbashSequences(char *text, int pos,char *atbashW);

    void AnagramSequences(char *text, int pos,char *w);

    #endif