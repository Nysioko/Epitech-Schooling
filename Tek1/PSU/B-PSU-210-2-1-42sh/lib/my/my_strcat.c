/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** nothing for now
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *str1, char const *str2)
{
    int i;
    int f;
    char *str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));

    if (!str)
        exit(84);
    my_strcpy(str, str1);
    for (i = 0; str[i] != '\0'; i++);
    for (f = 0; str2[f] != '\0'; f++) {
        str[i] = str2[f];
        i++;
    }
    str[i] = '\0';
    return (str);
}
