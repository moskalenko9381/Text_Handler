all: prog
prog: main.o FREE.o PRandDEl.o TASK2.o TASK1.o TASK3.o TASK4.o menu.o read.o
	gcc -o cw main.o FREE.o PRandDEl.o TASK1.o TASK2.o TASK3.o TASK4.o menu.o read.o
main.o: main.c
	gcc -c main.c
read.o: read.c
	gcc -c read.c
PRandDEL.o: PRandDEl.c
	gcc -c PRandDEl.c
menu.o: menu.c
	gcc -c menu.c
FREE.o: FREE.c
	gcc -c FREE.c
TASK1.o: TASK1.c
	gcc -c TASK1.c
TASK2.o: TASK2.c
	gcc -c TASK2.c
TASK3.o: TASK3.c
	gcc -c TASK3.c
TASK4.o: TASK4.c
	gcc -c TASK4.c
clean:
	rm -rf *.o

