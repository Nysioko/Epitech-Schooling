/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** finally able to use printf i guess?
*/

#include <stdarg.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int p_str(va_list *ap, int *c)
{
    char *str = va_arg(*ap, char *);

    my_putstr(str);
    (*c) = (*c) + my_strlen(str);
    return 0;
}

int p_nb(va_list *ap, int *c)
{
    int i = va_arg(*ap, int);
    char *str = malloc(sizeof(char) * 10);

    if (str == NULL)
        return 84;
    my_put_nbr(i);
    str = int_to_str(i, str);
    (*c) = (*c) + my_strlen(str);
    free(str);
    return 0;
}

int p_c(va_list *ap, int *c)
{
    char a = va_arg(*ap, int);

    my_putchar(a);
    (*c)++;
    return 0;
}

int p_dec(va_list *ap, int *c)
{
    unsigned int i = va_arg(*ap, unsigned int);
    char *str = malloc(sizeof(char) * 10);

    if (str == NULL)
        return 84;
    uint_to_str(i, str);
    my_putstr(str);
    (*c) = (*c) + my_strlen(str);
    free(str);
    return 0;
}