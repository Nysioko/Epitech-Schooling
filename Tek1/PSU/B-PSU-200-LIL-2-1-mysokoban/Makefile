##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile for my_sokoban
##

SRC     =	src/winlose.c			\
			src/main.c				\
			src/map_checker.c		\
			src/open_file.c			\
			src/move.c				\
			src/map_center.c		\
			src/init.c				\
			src/moveplusplus.c

OBJ     =	$(SRC:.c=.o)

NAME    =	my_sokoban

CFLAGS	=	-I./include -I./lib -W -Wall -Wextra -lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) $(CFLAGS) -lm -L./lib -lmy

debug:
	make -C lib/my
	gcc $(SRC) lib/my/*.c -g -o $(NAME) $(CFLAGS) -lm -L./lib -lmy

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:	fclean all
