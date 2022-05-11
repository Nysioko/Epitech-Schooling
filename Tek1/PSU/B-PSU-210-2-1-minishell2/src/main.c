/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** main
*/

#include "my.h"

char *new_line(char **env)
{
    char *str = NULL;
    size_t size;
    ssize_t ssize;

    my_putstr("-> ");
    ssize = getline(&str, &size, stdin);
    if (ssize == -1) {
        write(1, "\n", 1);
        freetab(env);
        free(str);
        exit(0);
    }
    str[my_strlen(str) - 1] = '\0';
    return str;
}

char **shell2(char **env, char *str)
{
    char *strr;
    char **tab = spliter(str, ';', 0);

    if (!tab)
        exit(84);
    for (int i = 0; tab[i] != NULL; i++) {
        strr = clear_arg(tab[i]);
        if (!strr)
            exit(EXIT_ERROR);
        if (strr[0] != '\0')
            env = pip(env, strr);
        free(strr);
    }
    freetab(tab);
    return env;
}

int shell(char **env)
{
    char *str;

    while (1) {
        str = new_line(env);
        env = shell2(env, str);
        free(str);
    }
    return EXIT_SUCCESS;
}

int iffermain(int i, char **env, char **new_env)
{
    for (i = 0; env[i] != NULL; i++) {
        new_env[i] = my_strdup(env[i]);
        if (!new_env[i])
            exit(84);
    }
    return i;
}

int main(int ac, char **av, char **env)
{
    int i = 0;
    char **new_env = malloc(sizeof(char*) * (my_tablen(env) + 1));

    if (!new_env)
        exit(84);
    if (ac > 1) {
        my_puterror("Too many arguments.\n");
        return EXIT_ERROR;
    }
    i = iffermain(i, env, new_env);
    new_env[i] = NULL;
    av[1] = NULL;
    signal(SIGINT, signal_handler);
    return shell(new_env);
}