/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** strtraitor
*/

#include "my.h"

void exit_cmd(char *str, char **env)
{
    free(str);
    freetab(env);
    my_putstr("exit\n");
    exit(EXIT_SUCCESS);
}

char **function_setenv(char **env, char *str, bool see)
{
    char *selectsetenv = "setenv";
    char *selectunsetenv = "unsetenv";
    int j = 0;

    for (j = 0; selectsetenv[j] == str[j]; j++);
    if (selectsetenv[j] == '\0' && (str[j] == ' ' || str[j] == '\0'))
        return create_setenv(env, str, see);
    for (j = 0; selectunsetenv[j] == str[j]; j++);
    if (selectunsetenv[j] == '\0' && (str[j] == ' ' || str[j] == '\0'))
        return create_unsetenv(env, str, see);
    init(env, str);
    return env;
}

char **user_command2(char **env, char *str, bool see)
{
    if (my_strcmp(str, "exit") == 0)
        exit_cmd(str, env);
    else if (str[0] == 'c' && str[1] == 'd' &&
    (str[2] == '\0' || str[2] == ' ')) {
        return cd(env, str, see);
    } else
        env = function_setenv(env, str, see);
    return env;
}