#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include "PRandDEl.h"
#include "read.h"

void printTEXT(Text* text){
    for (int i = 0; i < text->number; i++)
        wprintf(L"%ls ",text->buf[i]);
    printf("\n");
}

void delete(Text* text) {
    for (int i = 0; i < text->number; i++) {
        for (int j = i + 1; j < text->number; j++) {
            if (wcscasecmp(text->buf[i], text->buf[j]) == 0) {
                for (int k = j; k < text->number - 1; k++)
                    text->buf[k] = text->buf[k + 1];
                (text->number)--;
                j = i;
            }
        }
    }
    text->buf = realloc(text->buf, text->number * sizeof(wchar_t*));
}

