/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *av)
{
    int x = 0;
    int y = 1;
    int i = 0;

    if (av[i] == '-') {
        y *= -1;
        i++;
    }
    while (av[i] != '\0') {
        x = x * 10 + av[i] - 48;
        i++;
    }
    return x * y;
}