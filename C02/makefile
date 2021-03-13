CC=gcc
CFLAGS=-std=c11 -ggdb3 -O0 -Wall -Werror -Wextra -Wshadow -fsanitize=signed-integer-overflow -fsanitize=undefined -fsanitize=address

all: $(target).c 
	$(CC) $(CFLAGS) -o $(target) $(target).c

