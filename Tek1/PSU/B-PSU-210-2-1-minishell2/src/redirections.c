/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** reditections
*/

#include "my.h"

void redirection_sd(mysh_t *mysh, int flag, char *file, char *func)
{
    int fd = open(file, O_CREAT | O_RDWR | flag, 0664);
    int tmp = dup(1);

    dup2(fd, 1);
    user_command2(mysh->env, func, true);
    dup2(tmp, 1);
    close(fd);
    free(func);
    free(file);
}

void see_str(mysh_t *mysh, int j)
{
    char **splited_at_redirect = spliter(mysh->str, '>', 0);
    char *store_file;
    char *store_ftc_arg;

    if (!splited_at_redirect)
        exit(84);
    store_file = clear_arg(splited_at_redirect[1]);
    if (!store_file)
        exit(84);
    store_ftc_arg = clear_arg(splited_at_redirect[0]);
    if (!store_ftc_arg)
        exit(84);
    freetab(splited_at_redirect);
    if (j == 1)
        redirection_sd(mysh, O_TRUNC, store_file, store_ftc_arg);
    else
        redirection_sd(mysh, O_APPEND, store_file, store_ftc_arg);
}

int redirection(mysh_t *mysh)
{
    int j = 0;

    for (int i = 0; mysh->str[i] != '\0'; i++)
        if ('>' == mysh->str[i])
            j++;
    if (j > 2)
        my_puterror("Missing name for redirect.\n");
    else
        see_str(mysh, j);
    return 0;
}