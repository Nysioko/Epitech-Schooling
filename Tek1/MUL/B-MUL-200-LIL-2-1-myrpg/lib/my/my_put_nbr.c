/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** printing a number
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int i;

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
            my_putchar(48 + i);
        } else
            my_putchar(48 + nb % 10);
    }
    return (0);
}
