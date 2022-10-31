all: run

main.o: main.cpp
	g++ -c main.cpp -o main.o

stack.o: stack.cpp
	g++ -c stack.cpp -o stack.o

stackoperations.o: stackoperations.cpp
	g++ -c stackoperations.cpp -o stackoperations.o

run: main.o stack.o stackoperations.o
	g++ main.o stack.o stackoperations.o -o run
	.\run

clean:
	rm *.o
