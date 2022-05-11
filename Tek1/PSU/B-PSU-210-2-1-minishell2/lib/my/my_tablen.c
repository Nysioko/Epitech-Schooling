/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** my_tablen
*/

#include "my.h"

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return i;
}