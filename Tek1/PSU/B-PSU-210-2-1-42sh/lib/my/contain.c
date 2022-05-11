/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** contain
*/

#include "my.h"

bool contains(char *str, char *c)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        for (a = 0; str[i] == c[a] && str[i] != '\0'; a++, i++);
        if (a == my_strlen(c))
            return true;
        if (str[i] == '\0')
            i--;
    }
    return false;
}