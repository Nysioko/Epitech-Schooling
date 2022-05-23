/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int x)
{
    int y = 0;

    if (x < 0) {
        my_putchar(45);
        x = -x;
    }
    if (x >= 0) {
        if (x >= 10) {
            y = x % 10;
            x = (x - y) / 10;
            my_put_nbr(x);
            my_putchar(48 + y);
        }
        else
            my_putchar(48 + x);
    }
    return EXIT_SUCCESS;
}