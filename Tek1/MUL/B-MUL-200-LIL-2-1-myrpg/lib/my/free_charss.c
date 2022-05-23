/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** free_charss
*/

#include <stdlib.h>
#include "my.h"

void free_charss(char **to_free)
{
    int i;

    for (i = 0; to_free[i] != NULL; i++)
        free(to_free[i]);
    free(to_free[i]);
    free(to_free);
}