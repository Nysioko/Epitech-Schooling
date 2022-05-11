/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** get nbr
*/

#include <stdlib.h>

int ifneg(char const *str, int n)
{
    if (str[n] == '-')
        return (-1);
    return (1);
}

int ifnumber(char const *str, int n, int minus)
{
    int nb = 0;

    for (int counter = 0; str[n] >= 48 && str[n] <= 57; counter++) {
        if (counter >= 10)
            return (0);
        nb = nb * 10;
        nb = nb + (str[n] - 48);
        n++;
    }
    nb = nb * minus;
    return (nb);
}

int my_getnbr(char const *str, int n)
{
    int minus = 1;

    for (; str[n] != '\0'; n++) {
        minus = minus * (ifneg(str, n));
        if (str[n] >= '0' && str[n] <= '9')
            return (ifnumber(str, n, minus));
    }
    return (0);
}