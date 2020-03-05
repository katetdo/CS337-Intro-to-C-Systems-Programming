main: list.o main.o
	gcc list.o main.o -o main
list.o: list.c list.h
	gcc -Wall -c list.c
main.o: main.c list.h
	gcc -Wall -c main.c
clean:
	rm *.o
