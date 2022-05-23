##
## EPITECH PROJECT, 2021
## B-MUL-200-LIL-2-1-mydefender
## File description:
## Makefile
##

NAME	=	my_defender

CC	=	gcc

RM	=	rm -f

SRCS	=	./src/destroy.c 				\
	  		./src/game/game.c 				\
			./src/event/eventgameone.c 		\
	  		./src/event/eventgametwo.c		\
		  	./src/event/eventgamethree.c	\
	  		./src/main.c 					\
			./src/my_strcat.c				\
			./src/my_strlen.c				\
		  	./src/text/text.c				\
			./src/menu/loadvarmenu.c 		\
			./src/game/loadvargame.c 		\
			./src/game/freecage_game.c 		\
			./src/game/coingiver.c			\
			./src/game/loading_enemy.c 		\
			./src/game/enemy.c		 		\
			./src/game/tower_one_shot.c		\
			./src/game/tower_two_shot.c		\
			./src/game/tower_shot.c		\
			./src/game/stepone.c	 		\
			./src/game/steptwo.c	 		\
			./src/game/stepthree.c	 		\
			./src/game/stepfour.c	 		\
			./src/event/eventhelp.c 		\
			./src/event/eventpause.c 		\
			./src/event/eventstart.c 		\
	  		./src/menu/menuend.c 			\
	  		./src/menu/menuhelp.c 			\
	  		./src/menu/menupause.c 			\
	  		./src/menu/menustart.c 			\
	  		./src/spites/drawgame.c 		\
	  		./src/spites/drawmenuend.c 		\
	  		./src/spites/drawmenuhelp.c 	\
	  		./src/spites/drawmenupause.c	\
	  		./src/spites/drawmenustart.c	\
	  		./src/spites/sprite.c			\
	  		./src/spites/sprite_two.c		\
	  		./src/textures/texture.c		\
	  		./src/textures/texture_two.c	\
			./src/mouse/mouse.c				\
			./src/my_revstr.c				\
			./src/int_to_str.c				\
			./src/music/sound.c				\
			./src/init.c					\
			./src/spites/sprite_three.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS +=	-I./include -W -Wall -Wextra -l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

debug:	CFLAGS += -g
debug:	re