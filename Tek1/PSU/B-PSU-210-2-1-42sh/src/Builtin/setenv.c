/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** setenv
*/

#include "sh.h"

char **add_env(char **spl, char **env)
{
    char **tmp = malloc(sizeof(char *) * (my_charsslen(env) + 2));
    int i;

    if (tmp == NULL)
        exit(84);
    for (i = 0; env[i] != NULL; i++) {
        tmp[i] = my_strdup(env[i]);
        if (tmp[i] == NULL)
            exit(84);
    }
    return add_env2(spl, env, tmp, i);
}

char **errors_addenv(char **spl, sh_t *sh)
{
    if ((spl[1][0] >= 'A' && spl[1][0] <= 'Z') ||
    (spl[1][0] >= 'a' && spl[1][0] <= 'z'));
    else {
        sh->display ? write(2, "setenv: Variable name must begin"
        " with a letter.\n", 48) : sh->display;
        sh->status = 84;
        return sh->env;
    }
    for (int i = 0; spl[1] != NULL && spl[1][i] != '\0'; i++) {
        if (!(is_alphanum(spl[1][i]))) {
            sh->display ? write(2, "setenv: Variable name must contain "
            "alphanumeric characters.\n", 59) : sh->display;
            sh->status = 84;
            return (sh->env);
        }
    }
    return add_env(spl, sh->env);
}

void change_env2(char **env, char **spl, int i)
{
    char *tmp = my_strcat(spl[1], "=");

    if (tmp == NULL)
        exit(84);
    free(env[i]);
    if (my_charsslen(spl) == 3)
        env[i] = my_strcat(tmp, spl[2]);
    else
        env[i] = my_strdup(tmp);
    if (env[i] == NULL)
        exit(84);
    free(tmp);
}

char **change_env(char **spl, sh_t *sh)
{
    char *get = my_getenv(spl[1], sh->env);
    int x;

    if (get == NULL)
        return errors_addenv(spl, sh);
    for (int i = 0; sh->env[i] != NULL; i++) {
        for (x = 0; sh->env[i][x] == spl[1][x]; x++);
        if (sh->env[i][x] == '=' && spl[1][x] == '\0') {
            change_env2(sh->env, spl, i);
            break;
        }
    }
    free(get);
    return sh->env;
}

void setenv_cmd(sh_t *sh, char *path)
{
    char **spl = split(sh->str, " ", 0);

    if (spl == NULL)
        exit(84);
    path[my_strlen(path)] = '\0';
    if (spl[1] == NULL && sh->display)
        my_putcharss(sh->env);
    else if (my_charsslen(spl) == 2 || my_charsslen(spl) == 3)
        sh->env = change_env(spl, sh);
    else {
        sh->display ?
        write(2, "setenv: Too many arguments.\n", 28) : sh->display;
        sh->status = 84;
    }
    free_charss(spl);
}