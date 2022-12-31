CC=g++
CFLAGS=-c -Wall	

all: run_coder run_stack run_uncoder

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

stack.o: stack.cpp
	$(CC) $(CFLAGS) stack.cpp -o stack.o

stackoperations.o: stackoperations.cpp
	$(CC) $(CFLAGS) stackoperations.cpp -o stackoperations.o

coder.o: coder.cpp
	$(CC) $(CFLAGS) coder.cpp -o coder.o

coderfunctions.o: coderfunctions.cpp
	$(CC) $(CFLAGS) coderfunctions.cpp -o coderfunctions.o

run_coder: coder.o coderfunctions.o
	$(CC) coder.o coderfunctions.o -o run_coder

uncoder.o: uncoder.cpp
	$(CC) $(CFLAGS) uncoder.cpp -o uncoder.o

uncoderfunctions.o: uncoderfunctions.cpp
	$(CC) $(CFLAGS) uncoderfunctions.cpp -o uncoderfunctions.o

run_uncoder: uncoder.o uncoderfunctions.o
	$(CC) uncoder.o uncoderfunctions.o -o run_uncoder

run_stack: main.o stack.o stackoperations.o
	$(CC) main.o stack.o stackoperations.o -o run_stack

clean:
	rm *.o *.exe *.stackdump *.code *.bin
