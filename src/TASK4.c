#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <stdlib.h>
#include "TASK4.h"
#include "read.h"
#include "PRandDEl.h"

void TASK4(Text* text) {
    printf("Начальное количество предложений %d.\n", text->number);
    for (int j = 0; j < text->number; j++) { //проходимся по предложениям
        int countN = 0;
        int Nlast = 0;
        int countB = 0;
        int Blast = 0;
        for (int i = 0; i < wcslen(text->buf[j]); i++) {

            if (iswpunct(text->buf[j][i]) && text->buf[j][i] != '.' && text->buf[j][i] != ',') {
                if (j == text->number - 1) {
                    Nlast++;
                } else
                    countN++;
            }

            if (iswupper(text->buf[j][i])) {
                if (j == text->number - 1) {
                    Blast++;
                } else
                    countB++;
            }

        }
        if (countN != 0 && countB == 0) {
            for (int k = j; k < (text->number) - 1; k++) {
                text->buf[k] = text->buf[k + 1];
            }
            (text->number)--;
            j--;
        }
        if (Nlast != 0 && Blast == 0) {
            text->buf[text->number - 1] = L"\0";
        }
    }
    printTEXT(text);
}


