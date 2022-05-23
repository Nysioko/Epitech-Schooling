##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile for my_rpg
##

SRC     =	src/main.c					\
			src/func_useful.c			\
			src/save.c					\
			src/create/create1.c		\
			src/create/create2.c		\
			src/create/destroy.c		\
			src/create/cynthia.c		\
			src/create/load.c			\
			src/inputs/inputs.c			\
			src/inputs/htp.c			\
			src/inputs/menu.c			\
			src/inputs/pause.c			\
			src/inputs/select.c			\
			src/inputs/play.c			\
			src/inputs/play2.c			\
			src/inputs/dialog.c			\
			src/display/display.c		\
			src/display/display2.c		\
			src/display/player.c		\
			src/fight/fight.c			\

OBJ     =	$(SRC:.c=.o)

NAME    =	my_rpg

CFLAGS	=	-I./include -l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio -lm -L lib/my/ -lmy -Wall -Wextra -W

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

debug:
	make -C lib/my
	gcc $(SRC) lib/my/*.c -g -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:	fclean all
