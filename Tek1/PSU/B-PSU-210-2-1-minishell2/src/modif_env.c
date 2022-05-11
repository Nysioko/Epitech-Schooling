/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** modif_env
*/

#include "my.h"

void modif_env(char **env, char **envsplit, int i)
{
    free(env[i]);
    if (envsplit[2] != NULL)
        env[i] = malloc(sizeof(char) * (my_strlen(envsplit[2]) + 2 +
        my_strlen(envsplit[1])));
    else
        env[i] = malloc(sizeof(char) * (my_strlen(envsplit[1]) + 2));
    if (env[i] == NULL)
        exit(84);
    env[i][0] = '\0';
    my_strcat(env[i], envsplit[1]);
    my_strcat(env[i], "=");
    if (envsplit[2] != NULL)
        my_strcat(env[i], envsplit[2]);
}

