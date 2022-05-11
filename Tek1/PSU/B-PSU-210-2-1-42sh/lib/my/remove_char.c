/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** remove_char
*/

#include "my.h"
#include <stdlib.h>

void remove_char_wmalloc(char *str, int pos)
{
    for (; str[pos]; pos++)
        str[pos] = str[pos + 1];
}

char *remove_char(char *str, int pos)
{
    char *new = malloc(sizeof(char) * (my_strlen(str)));
    int a = 0;

    if (!new)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == pos);
        else {
            new[a] = str[i];
            a++;
        }
    }
    new[a] = '\0';
    return new;
}