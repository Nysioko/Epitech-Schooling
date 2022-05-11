##
## EPITECH PROJECT, 2020
## make file
## File description:
## making files
##

SRC 	=	my_find_prime_sup.c				\
		my_is_prime.c						\
		my_revstr.c							\
		my_swap.c							\
		my_getnbr.c							\
		my_putchar.c						\
		my_strcat.c							\
		my_strlen.c							\
		my_strncpy.c						\
		my_compute_power_rec.c				\
		my_put_nbr.c						\
		my_strcmp.c							\
		my_str_in_str.c						\
		my_compute_square_root.c			\
		my_isneg.c							\
		my_putstr.c							\
		my_strcpy.c							\
		my_strncat.c						\
		my_strdup.c							\
		my_strswap.c						\
		my_charswap.c						\
		dop.c								\
		my_strgetnbr.c						\
		insert_str.c						\
		my_printf.c							\
		my_secprintf.c						\
		my_ostrgetnbr.c						\
		uint_to_str.c						\
		int_to_str.c						\
		my_putcharss.c						\
		my_alpcmp.c							\
		split.c								\
		extract_str.c						\
		isletter.c							\
		clean_str.c							\
		free_charss.c						\
		my_charsslen.c						\
		contain.c							\
		no_malloc_strcat.c					\
		my_eprintf.c						\
		alnum.c								\
		remove_char.c						\
		my_charssdup.c

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
