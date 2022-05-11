/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** my_getenv
*/

#include "sh.h"

char *create_string(char **env, int i, int count)
{
    char *str = malloc(sizeof(char) * (my_strlen(env[i]) + 2));
    int a = 0;

    if (str == NULL)
        exit(84);
    for (; env[i][count] != '\0'; a++) {
        str[a] = env[i][count];
        count++;
    }
    str[a] = '\0';
    return (str);
}

char *my_getenv(char *name, char **env)
{
    int count;

    for (int i = 0; env[i] != NULL; i++) {
        for (count = 0; name[count] == env[i][count]; count++);
        if (env[i][count] == '=')
            return (create_string(env, i, count + 1));
    }
    return (NULL);
}