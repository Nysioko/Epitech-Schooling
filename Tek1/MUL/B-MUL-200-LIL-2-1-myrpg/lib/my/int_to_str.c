/*
** EPITECH PROJECT, 2020
** int_to_str
** File description:
** like the name implies
*/

#include "my.h"

char *int_to_str(int x, char *str)
{
    int i = 0;
    int y = 0;
    int save = x;

    if (x == 0) {
        str[i] = '0';
        i++;
    } else if (x < 0)
        x = x * -1;
    for (; x != 0; i++) {
        y = x % 10;
        str[i] = (char)y + 48;
        x = x / 10;
    }
    if (save < 0 && str[i - 1] != '-') {
        str[i] = '-';
        str[i + 1] = '\0';
    } else
        str[i] = '\0';
    return (my_revstr(str));
}