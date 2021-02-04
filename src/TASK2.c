#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include "PRandDEl.h"
#include "TASK2.h"
#include "read.h"

void TASK2(Text* text){
    wchar_t out[100];
    int k;
    for (int f = 0; f < text->number; f++) {
        int m = wcslen(text->buf[f]);
        int count = 1;
        for (int i = 0; i < m; i++) {
            i = i - 1 + count;
            if (i >= wcslen(text->buf[f]))
                break;
            count = 1;
            if (!iswalpha(text->buf[f][i]) && !iswspace(text->buf[f][i]) &&
                text->buf[f][i] != '.' && text->buf[f][i] != ',') {
                k = (int) text->buf[f][i];
                for (int j = i; j < wcslen(text->buf[f]); j++)
                    text->buf[f][j] = text->buf[f][j + 1];
                if (k >= 100) {
                    count = 3;
                } else {
                    if (k < 100 && k > 9)
                        count = 2;
                    text->buf[f] = realloc(text->buf[f], sizeof(wchar_t)*(m+count));
                    swprintf(out, 100, L"%d", k);
                    wcscpy(out + count, text->buf[f] + i);
                    wcscpy(text->buf[f] + i, out);
                    m += count - 1;
                }
            }
        }
    }
    printTEXT(text);
}
