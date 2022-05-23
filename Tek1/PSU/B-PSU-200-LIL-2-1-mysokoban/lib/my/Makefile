##
## EPITECH PROJECT, 2021
## B-PSU-200-LIL-2-1-mysokoban
## File description:
## Makefile
##

SRC 	=	my_atoi.c		\
			my_getnbr.c		\
			my_put_nbr.c	\
			my_putchar.c	\
			my_puterror.c	\
			my_putstr.c		\
			my_split.c		\
			my_strlen.c		\
			my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
