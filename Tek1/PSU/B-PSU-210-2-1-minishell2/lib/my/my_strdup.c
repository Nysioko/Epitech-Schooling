/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-pushswap
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char *src)
{
    char *dest;
    int count = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        exit(EXIT_ERROR);
    while (src[count] != '\0') {
        dest[count] = src[count];
        count++;
    }
    dest[count] = '\0';
    return (dest);
}