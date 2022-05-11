/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** my_eprintf
*/

#include "my.h"
#include <unistd.h>

static void my_eput_nbr(int nb)
{
    int i;
    char c;

    if (nb < 0) {
        my_putchar('-');
        nb = (-1) * nb;
    }
    if (nb >= 0)
    {
        if (nb >= 10) {
            i = (nb % 10);
            nb = (nb - i) / 10;
            my_put_nbr(nb);
            c = 48 + i;
            write(2, &c, 1);
        } else {
            c = 48 + nb % 10;
            write(2, &c, 1);
        }
    }
}

void my_eputstr(char *str)
{
    write(2, str, my_strlen(str));
}

void my_eputchar(char c)
{
    write(2, &c, 1);
}


void flags(char *str, int *i, va_list *ap)
{
    (*i)++;
    if (str[*i] == '%')
        my_eputchar('%');
    if (str[*i] == 'd' || str[*i] == 'i')
        my_eput_nbr(va_arg(*ap, int));
    if (str[*i] == 's')
        my_eputstr(va_arg(*ap, char *));
    if (str[*i] == 'c')
        my_eputchar(va_arg(*ap, int));
}

int my_eprintf(char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%')
            my_putchar(format[i]);
        else
            flags(format, &i, &ap);
    }
    va_end(ap);
    return (0);
}
