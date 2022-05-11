/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** my_getenv
*/

#include "my.h"

char *my_getenv(char **env, char *name)
{
    int x = 0;
    int y = 0;

    while (env[x] != NULL) {
        y = 0;
        while (name[y] == env[x][y] && name[y] != '\0')
            y++;
        if (y == my_strlen(name))
            return (my_strdup(&env[x][y + 1]));
        x++;
    }
    return NULL;
}