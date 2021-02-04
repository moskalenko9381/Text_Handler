#include <stdlib.h>
#include "FREE.h"
#include "read.h"

void freeMemoryTEXT(Text* text){
    for (int i = 0; i < text->number; i++)
        free(text->buf[i]);
    free(text->buf);
}

