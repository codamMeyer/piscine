CC=gcc
CFLAGS= -Wall -Werror -Wextra 

NAME = rush-02
SRCS = main.c parse.c utils.c translator.c ft_string.c helpers.c
HEADERS = *.h
OBJECTS = *.o

all: $(NAME)

$(NAME): $(HEADERS) $(SRCS)
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
