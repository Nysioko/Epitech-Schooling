/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** unsetenv
*/

#include "my.h"

char **unsetenv_changer(char **env, int i)
{
    char **new_env2 = malloc(sizeof(char *) * my_tablen(env));
    int a = 0;

    if (new_env2 == NULL)
        exit(EXIT_ERROR);
    for (int w = 0; env[w] != NULL; w++) {
        if (w != i)
            new_env2[a] = my_strdup(env[w]);
        if (w != i && new_env2[a] == NULL)
            exit(EXIT_ERROR);
        if (w != i)
            a += 1;
    }
    new_env2[a] = NULL;
    freetab(env);
    return new_env2;
}

char **iffer_unsetenv(char **env, char **unsetenv_split, int i)
{
    int k = 0;

    for (int j = 0; unsetenv_split[j] != NULL; j++) {
        for (k = 0; unsetenv_split[j][k] == env[i][k]; k++);
        if (env[i][k] == '=' && unsetenv_split[j][k] == '\0') {
            return unsetenv_changer(env, i);
        }
    }
    return NULL;
}

char **create_unsetenv(char **env, char *str, bool see)
{
    char **unsetenv_split = spliter(str, ' ', 0);
    char **iffer = NULL;

    if (unsetenv_split == NULL)
        exit(EXIT_ERROR);
    if (unsetenv_split[1] == NULL) {
        see ? my_puterror("unsetenv: Too few argument.\n") : see;
        return env;
    }
    for (int i = 0; env[i] != NULL; i++) {
        iffer = iffer_unsetenv(env, unsetenv_split, i);
        if (iffer != NULL) {
            freetab(unsetenv_split);
            return create_unsetenv(iffer, str, see);
        }
    }
    freetab(unsetenv_split);
    return env;
}