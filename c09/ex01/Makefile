NAME=srcs
CFLAGS=-Wall -Wetra -Werror -o $(NAME)
SRCS=ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
CC=gcc
 
# top-level rule to create the program.
all: main
 
# compiling the source file.
main: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)
 
# cleaning everything that can be automatically recreated with "make".
clean:
	/bin/rm -f $(NAME)
