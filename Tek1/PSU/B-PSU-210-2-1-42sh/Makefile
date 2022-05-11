##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile 42sh
##

SRC	=	src/main.c				\
		src/Builtin/cd.c			\
		src/Builtin/cd2.c			\
		src/Exec/cmd_handler.c			\
		src/Exec/execute.c			\
		src/Exec/execute2.c			\
		src/Exec/exit_status.c			\
		src/filter_str.c			\
		src/Exec/my_getenv.c		\
		src/Builtin/setenv.c		\
		src/Builtin/setenv2.c		\
		src/Builtin/unsetenv.c		\
		src/Exec/signals.c			\
		src/Bundle/manage_char.c	\
		src/Bundle/manage_char2.c	\
		src/Bundle/right.c			\
		src/Bundle/left.c			\
		src/Bundle/double_left.c	\
		src/Prompt/prompt.c			\
		src/Prompt/prompt2.c		\
		src/linked_list.c			\
		src/Builtin/aliases.c		\
		src/Builtin/aliases2.c		\
		src/Builtin/echo.c			\
		src/Builtin/truefalse.c		\
		src/Builtin/exit.c			\
		src/Builtin/my_getline.c	\
		src/Prompt/manage_special_char.c		\
		src/Prompt/del_getline.c	\
		src/Builtin/history.c		\
		src/Prompt/getfiles.c		\
		src/Bundle/check_if_separators.c 	\
		src/Prompt/completion.c 	\
		src/Exec/globbing.c

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

CFLAGS	=	-I./include -I./lib -W -Wall -Wextra

all:    	$(NAME)

$(NAME):    	$(OBJ)
		make -C lib/my
		gcc $(OBJ) -o $(NAME) $(CFLAGS) -lm -L./lib -lmy

debug:
		make -C lib/my
		gcc $(SRC) lib/my/*.c -g -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
