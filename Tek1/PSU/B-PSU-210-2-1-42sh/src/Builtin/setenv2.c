/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** setenv2
*/

#include "sh.h"

char **add_env2(char **spl, char **env, char **tmp, int i)
{
    char *tmp_str;

    tmp_str = my_strcat(spl[1], "=");
    if (tmp_str == NULL)
        exit(84);
    if (spl[2] != NULL) {
        tmp[i] = my_strcat(tmp_str, spl[2]);
        if (tmp[i] == NULL)
            exit(84);
    } else {
        tmp[i] = my_strdup(tmp_str);
        if (tmp[i] == NULL)
            exit(84);
    }
    tmp[i + 1] = NULL;
    free_charss(env);
    free(tmp_str);
    return tmp;
}