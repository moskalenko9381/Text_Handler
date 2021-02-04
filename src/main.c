#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>
#include <wctype.h>
#include <stdlib.h>
#include "TASK1.h"
#include "TASK2.h"
#include "TASK3.h"
#include "TASK4.h"
#include "TASK1.h"
#include "FREE.h"
#include "PRandDEl.h"
#include "read.h"
#include "menu.h"

int get()
{
 int input;
 char ch;
 while (scanf("%d", &input) != 1)
 {
 while ((ch = getchar()) != '\n')
         putchar(ch); // отбросить неправильный ввод
         printf(" - неверно. Вы должны ввести целое число.\n ");
 }
 return input;
}

int main() {
    setlocale(LC_CTYPE, "");  //rus_rus.866
    printf("Для выбора действия введите текст:\n");
    Text text = readText();
    delete(&text);
    print_menu();
    while (1){
        switch (get()) {  
           case 1:
                TASK1(&text);
                break;
            case 2:
                TASK2(&text);
                break;
            case 3:
                TASK3(&text);
                break;
            case 4:
                TASK4(&text);
                break;
            case 5:
                printTEXT(&text);
                break;
            case 6:
                printf("До свидания.");
                freeMemoryTEXT(&text);
                return 0;
            default:
                printf("Данные некорректны. Выберите действие от 1 до 6.\n");
                break;
        }
    }
    return 0;
}

