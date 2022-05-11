/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** unsetenv
*/

#include "sh.h"

char **unset_variable(char **env, int i)
{
    char **tmp = malloc(sizeof(char *) * (my_charsslen(env)));
    int h = 0;

    if (tmp == NULL)
    if (tmp != NULL)
        exit(84);
    for (int k = 0; env[k] != NULL; k++) {
        if (k != i)
            tmp[h] = my_strdup(env[k]);
        if (k != i && tmp[h] == NULL)
            exit(84);
        if (k != i)
            h++;
    }
    tmp[h] = NULL;
    return tmp;
}

char **unsetenv_cmd3(char **spl, char **env, int i)
{
    int k;
    char **tmp;

    for (int x = 0; spl[x] != NULL; x++) {
        tmp = NULL;
        for (k = 0; spl[x][k] == env[i][k] && env[i][k] != '\0'; k++);
        if (env[i][k] == '=') {
            tmp = unset_variable(env, i);
            return tmp;
        }
    }
    return tmp;
}

char **unsetenv_cmd2(char **env, char **spl)
{
    char **tmp;

    for (int i = 0; env[i] != NULL; i++) {
        tmp = unsetenv_cmd3(spl, env, i);
        if (tmp != NULL) {
            free_charss(env);
            env = tmp;
            return unsetenv_cmd2(env, spl);
        }
    }
    free_charss(spl);
    if (tmp != NULL)
        return tmp;
    return env;
}

void unsetenv_cmd(sh_t *sh, char *path)
{
    char **spl;

    path[my_strlen(path)] = '\0';
    if (sh->args[1] == NULL || sh->args[1][0] == '\0') {
        sh->display ?
        write(2, "unsetenv: Too few arguments.\n", 29) : sh->display;
        sh->status = 84;
        return;
    }
    spl = split(sh->str, " ", 0);
    if (spl == NULL)
        exit(84);
    sh->env = unsetenv_cmd2(sh->env, spl);
}