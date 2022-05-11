/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** pip
*/

#include "my.h"

void restore_shell(mysh_t *mysh)
{
    char *selectsetenv = "setenv";
    char *selectunsetenv = "unsetenv";
    int j = 0;
    bool exec = (my_strcmp(mysh->str, "exit") == 0 || (mysh->str[0] == 'c' &&
    mysh->str[1] == 'd' && (mysh->str[2] == '\0' || mysh->str[2] == ' ')))
    ? true : false;

    for (j = 0; selectsetenv[j] == mysh->str[j]; j++);
    if (selectsetenv[j] == '\0' && (mysh->str[j] == ' ' ||
    mysh->str[j] == '\0'))
        exec = true;
    for (j = 0; selectunsetenv[j] == mysh->str[j]; j++);
    if (selectunsetenv[j] == '\0' && (mysh->str[j] == ' ' ||
    mysh->str[j] == '\0'))
        exec = true;
    if (exec)
        mysh->env = user_command2(mysh->env, mysh->str, false);
}

void pip_linker(mysh_t *mysh, char **split_at_pip, int i)
{
    if (i != 0) {
        dup2(mysh->old[0], 0);
        close(mysh->old[0]);
        close(mysh->old[1]);
    }
    if (split_at_pip[i + 1] != NULL) {
        close(mysh->new[0]);
        dup2(mysh->new[1], 1);
        close(mysh->new[1]);
    }
}

void execbelike(mysh_t *mysh, char **split_at_pip, int i)
{
    bool ifredirect = false;

    if (fork() == 0) {
        pip_linker(mysh, split_at_pip, i);
        for (int i = 0; mysh->str[i] != '\0'; i++)
            ifredirect =  mysh->str[i] == '>' ? true : ifredirect;
        if (ifredirect)
            exit(redirection(mysh));
        user_command2(mysh->env, mysh->str, true);
        exit(0);
    }
    restore_shell(mysh);
}

void manager_fd(mysh_t *mysh, char **split_at_pip, int i)
{
    if (split_at_pip[i + 1] != NULL) {
        mysh->new = malloc(sizeof(int) * 2);
        if (!mysh->new)
            exit(84);
        pipe(mysh->new);
    }
    execbelike(mysh, split_at_pip, i);
    if (mysh->old != NULL) {
        close(mysh->old[0]);
        close(mysh->old[1]);
    }
    if (i != 0)
        free(mysh->old);
    mysh->old = mysh->new;
}

char **pip(char **env, char *str)
{
    char **split_at_pip = spliter(str, '|', 0);
    mysh_t mysh;

    if (!split_at_pip)
        exit(84);
    mysh.env = env;
    mysh.old = NULL;
    mysh.new = NULL;
    for (int i = 0; split_at_pip[i] != NULL; i++) {
        mysh.str = clear_arg(split_at_pip[i]);
        manager_fd(&mysh, split_at_pip, i);
        free(mysh.str);
    }
    freetab(split_at_pip);
    while (wait(NULL) > 0);
    return mysh.env;
}