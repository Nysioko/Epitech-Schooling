/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** allocating right memory
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src)) + 2);
    if (dest == NULL)
        return NULL;
    my_strcpy(dest, src);
    return (dest);
}
