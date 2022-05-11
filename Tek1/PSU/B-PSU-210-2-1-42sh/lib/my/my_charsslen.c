/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** my_charsslen
*/

#include "my.h"
#include <unistd.h>

int my_charsslen(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; i++);
    return i;
}