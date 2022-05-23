/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** nothing for now
*/

#include "my_defender.h"

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