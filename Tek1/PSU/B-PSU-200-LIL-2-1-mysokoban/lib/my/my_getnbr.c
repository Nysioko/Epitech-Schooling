/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr2(char *str, int i)
{
    int a = 0;

    for (; (str[i] >= '0' && str[i] <= '9') && str[i] != '\0'; i++) {
        a = a * 10;
        a += (str[i] - 48);
    }
    return a;
}

int my_getnbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            return (my_getnbr2(str, i));
    }
    return EXIT_SUCCESS;
}