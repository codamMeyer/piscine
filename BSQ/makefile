# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmeyer <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/29 20:01:42 by mmeyer        #+#    #+#                  #
#    Updated: 2020/07/29 20:05:32 by mmeyer        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Wall -Werror -Wextra 
NAME = BSQ
SRCS = allocator.c ft_string.c min.c main.c solve.c parse.c utils.c
HEADERS = allocator.h ft_string.h min.h solve.h parse.h utils.h

all: $(NAME)

$(NAME): $(HEADERS) 
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm *.map

re: fclean all
