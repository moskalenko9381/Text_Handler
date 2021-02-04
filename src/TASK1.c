#include <stdio.h>
#include <wctype.h>
#include <wchar.h>
#include <stdlib.h>
#include "TASK1.h"
#include "read.h"

int cmpWords (const void* str, const void* tok)
{
    return wcscmp(*(const wchar_t**)str, *(const wchar_t**)tok);
}

int countWords(Text text){
    int count = 0;
    for( int index  = 0; index < text.number; index++) {
        for (int i = 0; i < wcslen(text.buf[index]); i++) {
            if (iswblank(text.buf[index][i]) || text.buf[index][i] == L',') {
                count++;
            }
        }
        count++;
    }
    return count;
}

void printWords(Words* words) {
    qsort(words->tokes, words->amount, sizeof(wchar_t *), cmpWords);
    int count = 1;
    for (int j = 0; j < words->amount; j++) {
        if (j > 0 && wcscmp(words->tokes[j],words->tokes[j - 1]) == 0){
            continue;}
        else {
            for (int k = j + 1; k < words->amount; k++) {
                if (wcscmp(words->tokes[j], words->tokes[k]) == 0) {
                    count++;
                }
            }
            wprintf(L" \"%ls\"  в тексте %d раз \n", words->tokes[j] , count);
            count = 1;
        }
    }
}

void freeMemoryWORDS(Words* words){
    for (int i = 0; i < words->amount; i++)
        free(words->tokes[i]);
    free(words->tokes);
}

void TASK1(Text* text) {
    int count = countWords(*text);
    wchar_t** buffer = malloc(text->number * sizeof(wchar_t*));
    for(int i = 0; i < text->number; i++){
        int k = wcslen(text->buf[i]);
        buffer[i] = malloc((k + 100)* sizeof(wchar_t));
       text->buf[i][k] = L'\0';
       wcscpy(buffer[i], text->buf[i]);
    }
    Words words;
    words.tokes = malloc(count * sizeof(wchar_t *));
    int n = 0;
    wchar_t *tmp;
    for (int i = 0; i < text->number; i++) {
        wchar_t *tok = wcstok(buffer[i], L" \t.,", &tmp);
        while (tok != NULL) {
            int h = wcslen(tok);
            words.tokes[n] = malloc((h + 100) * sizeof(wchar_t));
            wcscpy(words.tokes[n], tok);
            n++;
            tok = wcstok(NULL, L" .,\t", &tmp);
        }
    }
    words.amount = n;
    printWords(&words);
    freeMemoryWORDS(&words);
    for (int i = 0; i < text->number; i++)
        free(buffer[i]);
    free(buffer);
}

