/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_strlen
*/

#include "../include/matchstick.h"

int my_strlen(char *str)
{
    int x = 0;
    while (str[x] != '\0') {
        x++;
    }
    return x;
}