##
## EPITECH PROJECT, 2021
## B-CPE-200-LIL-2-1-matchstick
## File description:
## Makefile
##

NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	= ./lib/my_getnbr.c \
	  ./lib/my_putchar.c \
	  ./lib/my_puterror.c \
	  ./lib/my_putstr.c \
	  ./lib/my_strlen.c \
	  ./lib/my_putcharstarstar.c \
	  ./lib/my_putnbr.c \
	  ./lib/my_freeter.c \
	  ./src/error.c \
	  ./src/map_gen.c \
	  ./src/iaecoplusdevparuntek1.c \
	  ./src/player.c \
	  ./src/player2.c \
	  ./src/main.c	\
	  ./src/sticks.c	\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

debug: debug
	$(CC) $(OBJS) -g -o $(NAME) $(LDFLAGS)

re: fclean all

.PHONY: all clean fclean re
