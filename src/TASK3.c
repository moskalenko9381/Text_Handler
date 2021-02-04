#include <wchar.h>
#include <stdlib.h>
#include "PRandDEl.h"
#include "TASK3.h"
#include "read.h"

int letters(wchar_t* a){
    int count = 0;
    for (int i = 0; i <= wcslen(a); i++){
        if (iswalpha(a[i]) && (int)a[i] >= 65 && (int)a[i] <= 122)
            count++;
    }
    return count;
}

int cmp (const void* str, const void* tok){
    int countA = letters(*(wchar_t **)str);
    int countB = letters(*(wchar_t **)tok);
    if (countA - countB > 0)
        return 1;
    if (countA - countB == 0)
        return 0;
    if (countA - countB < 0)
        return -1;
}

void TASK3(Text* text){
    qsort(text->buf, text->number, sizeof(wchar_t *), cmp);
    printTEXT(text);
}

