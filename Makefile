CC=g++
CFLAGS=-c -Wall	

all: run

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

stack.o: stack.cpp
	$(CC) $(CFLAGS) stack.cpp -o stack.o

stackoperations.o: stackoperations.cpp
	$(CC) $(CFLAGS) stackoperations.cpp -o stackoperations.o

run: main.o stack.o stackoperations.o
	$(CC) main.o stack.o stackoperations.o -o run

clean:
	rm *.o
