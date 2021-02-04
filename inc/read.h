#ifndef READ_H 
#define READ_H

typedef struct Sentence{
    wchar_t* sent;
    int act_size;
    int max_size;
}Sentence;

typedef struct Text{
    wchar_t** buf;
    int size;
    int number;
}Text;

Sentence readSentence();
Text readText();
#endif
