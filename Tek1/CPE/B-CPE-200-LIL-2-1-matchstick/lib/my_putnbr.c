/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-matchstick
** File description:
** my_putnbr
*/

#include "../include/matchstick.h"

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
    return 0;
}
