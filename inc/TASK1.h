 #ifndef TASK1_H
 #define TASK1_H
 #include "read.h"
 typedef struct Words{
 wchar_t** tokes;
 int amount;
 }Words;
 int countWords(Text text);
 int cmpWords (const void* str, const void* tok);
 void printWords(Words* words);
 void freeMemoryWORDS(Words* words);
 void TASK1(Text* text);
 #endif
