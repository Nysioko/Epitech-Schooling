/*
** EPITECH PROJECT, 2020
** strcat
** File description:
** task2
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
