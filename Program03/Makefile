main: main.o queue.o
	gcc main.o queue.o -o main

main.o: main.c queue.h
	gcc -Wall -c main.c

queue.o: queue.c queue.h
	gcc -Wall -c queue.c

clean:
	rm *.o
