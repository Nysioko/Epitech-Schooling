##
## EPITECH PROJECT, 2021
## B-PSU-101-LIL-1-1-minishell1
## File description:
## Makefile
##

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	=	./lib/my/clean_str.c \
		./lib/my/my_atoi.c \
		./lib/my/freetab.c \
		./lib/my/my_getnbr.c \
		./lib/my/my_putchar.c \
		./lib/my/my_puterror.c \
		./lib/my/my_putnbr.c \
		./lib/my/my_putstr.c \
		./lib/my/my_split.c \
		./lib/my/my_strcat.c \
		./lib/my/my_strcmp.c \
		./lib/my/my_strcpy.c \
		./lib/my/my_strdup.c \
		./lib/my/my_strlen.c \
		./lib/my/my_swap.c \
		./lib/my/my_tablen.c \
		./lib/my/my_putcharstarstar.c	\
		./src/cd.c \
		./src/execution1.c \
		./src/execution2.c \
		./src/main.c \
		./src/my_getenv.c \
		./src/path.c \
		./src/segfault.c \
		./src/clear_arg.c	\
		./src/strtraitor.c\
		./src/setenv.c	\
		./src/unsetenv.c	\
		./src/modif_env.c	\
		./src/redirections.c	\
		./src/pip.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

debug:   $(OBJS)
	 $(CC) $(OBJS) -o -g $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
