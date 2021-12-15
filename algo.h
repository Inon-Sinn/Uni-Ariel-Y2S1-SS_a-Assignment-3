#ifndef _algo_
#define _algo_

//w - word,txt - the Text

    char* Atbash(char* dest,char* source);

    int GematriaValue(char *w);

    int contains(char *w,char character);

    void GematriaSequence(char *txt, int pos, int GValue);

    void AtbashSequences(char *txt, int pos,char *atbashW);

    void AnagramSequences(char *txt, int pos,char *w);

    #endif