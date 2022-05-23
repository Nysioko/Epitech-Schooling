/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** no_malloc_strcat
*/

#include "my.h"

char *my_strcat_clean(char *str1, char const *str2)
{
    int i;
    int f;

    for (i = 0; str1[i] != '\0'; i++);
    for (f = 0; str2[f] != '\0'; f++) {
        str1[i] = str2[f];
        i++;
    }
    str1[i] = '\0';
    return (str1);
}