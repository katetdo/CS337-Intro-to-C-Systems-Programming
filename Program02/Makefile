main: main.o histo.o
	gcc main.o histo.o -o main

main.o: main.c histo.h
	gcc -Wall -c main.c

histo.o: histo.c histo.h
	gcc -Wall -c histo.c

clean:
	rm *.o
