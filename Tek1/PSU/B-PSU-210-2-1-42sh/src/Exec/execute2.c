/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** execute2
*/

#include "sh.h"

int need_place_to_free(char *envi, char **path, int status)
{
    free_charss(path);
    free(envi);
    return status;
}

void cat_path(char **path_str, char *name, char **path, int i)
{
    char *str = my_strcat(path[i], "/");

    if (str == NULL)
        exit(84);
    (*path_str) = my_strcat(str, name);
    if ((*path_str) == NULL)
        exit(84);
    free(str);
}