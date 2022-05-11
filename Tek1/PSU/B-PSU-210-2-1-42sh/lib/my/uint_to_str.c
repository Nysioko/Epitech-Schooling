/*
** EPITECH PROJECT, 2020
** my_unigned_int_to_str
** File description:
** like the name implies
*/

#include "my.h"

char *uint_to_str(unsigned int x, char *str)
{
    int i = 0;
    int y = 0;

    if (x == 0) {
        str[i] = '0';
        i++;
    }
    for (; x != 0; i++) {
        y = x % 10;
        str[i] = (char)y + 48;
        x = x / 10;
    }
    str[i] = '\0';
    return (my_revstr(str));
}