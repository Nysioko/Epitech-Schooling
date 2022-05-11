/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_charssdup
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char **my_charssdup(char **tab)
{
    char **new = malloc(sizeof(char *) * (my_charsslen(tab) + 1));
    int i = 0;

    if (!new)
        exit(84);
    for (i = 0; tab[i] != NULL; i++) {
        new[i] = my_strdup(tab[i]);
        if (!new[i])
            exit(84);
    }
    new[i] = NULL;
    return new;
}