CC=gcc
CFLAGS=-std=c11 -ggdb3 -O0 -Wall -Werror -Wextra -Wshadow -fsanitize=signed-integer-overflow -fsanitize=undefined 

#all: $(target).c 
#	$(CC) $(CFLAGS) -o $(target) $(target).c

all: solver.o visibility.o board.o main.o
	$(CC) $(CFLAGS) -o rush-01 main.o solver.o visibility.o board.o

test: solver.o visibility.o board.o test.o
	$(CC) $(CFLAGS) -o test test.o solver.o visibility.o board.o

test.o: test.c
	$(CC) $(CFLAGS) test.c -c
	
main.o: solver.h main.c
	$(CC) $(CFLAGS) main.c -c

solver.o: board.h solver.h solver.c
	$(CC) $(CFLAGS) solver.c -c

visibility.o: board.h visibility.h visibility.c
	$(CC) $(CFLAGS) visibility.c -c

board.o: board.h board.c
	$(CC) $(CFLAGS) board.c -c 

clean:
	rm *.o rush-01

	
