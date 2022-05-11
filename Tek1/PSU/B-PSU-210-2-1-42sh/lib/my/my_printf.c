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

int p_n(va_list *ap, int *c)
{
    char *str = malloc(sizeof(char) * 10);

    if (str == NULL)
        return 84;
    if (!(ap))
        str[0] = '\0';
    int_to_str((*c), str);
    my_putstr(str);
    (*c) = (*c) + my_strlen(str);
    free(str);
    return 0;
}

int check_per(char *str, int *i, va_list *ap, int *c)
{
    char list[7] = {'d', 'i', 'c', 's', 'o', 'n', 0};
    int (*tablo[6]) (va_list *, int *) = {p_nb, p_nb, p_c, p_str, p_dec, p_n};

    (*i)++;
    for (int d = 0; list[d] != 0; d++) {
        if (list[d] == str[(*i)]) {
            (*tablo[d]) (ap, c);
            return (0);
        }
    }
    if (str[(*i)] == '%') {
        my_putchar('%');
        (*c)++;
    } else {
        my_putchar('%');
        my_putchar(str[(*i)]);
        (*c) = (*c) + 2;
    }
    return (0);
}

int my_printf(char *format, ...)
{
    va_list ap;
    int c = 0;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%')
            check_per(format, &i, &ap, &c);
        else {
            my_putchar(format[i]);
            c++;
        }
    }
    va_end(ap);
    return (c);
}
