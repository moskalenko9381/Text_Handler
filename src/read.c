#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>
#include <wctype.h>
#include <stdlib.h>
#include "read.h"
#define INIT 10

Sentence readSentence(){
    int max_size_sentence = INIT;
    int act_size_sentence = 0;
    wchar_t* sent = malloc(max_size_sentence * sizeof(wchar_t));
    wchar_t c = getwchar();
    while((c == L'\t') || (c == L' ')){
        c = getwchar();
    }
    sent[act_size_sentence++] = c;
    do{
        c = getwchar();
        sent[act_size_sentence] = c;
        act_size_sentence++;
        if (act_size_sentence == max_size_sentence - 2){
            max_size_sentence += INIT;
            sent = realloc(sent, max_size_sentence * sizeof(wchar_t));
        }
    }while(!wcschr(L".\n", c));
    sent[act_size_sentence] = L'\0';
    Sentence sentence;
    sentence.sent = sent;
    sentence.act_size = act_size_sentence;
    sentence.max_size = max_size_sentence;
    return sentence;
}


Text readText(){
    int size = INIT;
    int number = 0;
    Text text;
    text.buf = malloc(size * sizeof(wchar_t*));
    while(1){
        struct Sentence sentence = readSentence();
        if (sentence.sent[0] == L'\n') {
            free(sentence.sent);
            break;
        }
        else {
            text.buf[number] = malloc(sizeof(wchar_t) * (sentence.act_size + 10));
            for (int j = 0; j <= sentence.act_size + 1; j++)
                text.buf[number][j] = sentence.sent[j];
            free(sentence.sent);
            number++;
            if (number == size - 2) {
                size += INIT;
                text.buf = realloc(text.buf, size * sizeof(wchar_t *));
            }
        }
    }
    text.size = size;
    text.number = number;
    return text;
}
