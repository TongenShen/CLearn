app: main.o ziunit.o
	gcc main.o ziunit.o -o app
	rm -f *.o
	
main.o: main.c unit.h
	gcc -c main.c -Wall

ziunit.o: main.o ziunit.c unit.h
	gcc -c ziunit.c -Wall

clean:
	rm -f *.o

fuck :
	uname -a