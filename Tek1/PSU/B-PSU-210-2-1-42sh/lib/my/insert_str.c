/*
** EPITECH PROJECT, 2020
** insert_str
** File description:
** inserting a char in the middle of a string
*/

#include "my.h"
#include <stdlib.h>

char *insert_str(char *str, char *c, int n)
{
    int i = my_strlen(str) + 1;
    int y = 0;
    int x;
    char *newstr = malloc(sizeof(char) * i + my_strlen(c) + 5);

    !newstr ? exit(84) : newstr;
    for (y = 0; y != n; y++)
        newstr[y] = str[y];
    x = y;
    for (int b = 0; c[b] != '\0'; y++) {
        newstr[y] = c[b];
        b++;
    }
    for (; str[x] != '\0'; x++) {
        newstr[y] = str[x];
        y++;
    }
    newstr[y] = '\0';
    return (newstr);
}
