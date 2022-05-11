/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** my_putnbr
*/

#include "my.h"

int my_putnbr(int nbr)
{
    int i;

    if (nbr >= 0) {
        if (nbr >= 10) {
            i = (nbr % 10);
            nbr = (nbr - i) / 10;
            my_putnbr(nbr);
            my_putchar(48 + i);
        }
        else
            my_putchar(48 + nbr % 10);
    }
    return nbr;
}
