run:
	./app

build : main.o unit/unit.h unit1.o
	gcc main.o unit1.o -o app

main.o: main.c 
	gcc -c main.c -o main.o

unit1.o: unit/test1/unit1.c
	pwd
	gcc -c ./unit/test1/unit1.c -o ./unit1.o