#ifndef _algo_
#define _algo_

//w - word,txt - the Text

    //Returns the given string in its Atbash from
    char* Atbash(char* dest,char* source);

    // Returns the GematriaValue of a Word
    int GematriaValue(char *w);

    //Return true if the given character is in the given word, False else
    int contains(char *w,char character);

    // gets a placement in the text an if its the start of an GematriaSequence, it will print the Sequence
    void GematriaSequence(char *text, int pos, int GValue);

    // gets a placement in the text an if its the start of an AtbashSequences, it will print the Sequence
    void AtbashSequencesForward(char *text, int pos,char *atbashW);

    // gets a placement in the text an if its the start of an AtbashSequences, it will print the Sequence
    void AtbashSequencesBackward(char *text, int pos,char *atbashW);

    // gets a placement in the text an if its the start of an AnagramSequences, it will print the Sequence
    void AnagramSequences(char *text, int pos,char *w);

    #endif