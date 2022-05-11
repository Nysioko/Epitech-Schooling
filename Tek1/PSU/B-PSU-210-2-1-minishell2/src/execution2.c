/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** execution2
*/

#include "my.h"

void signal_handler(int i)
{
    if (i == SIGINT)
        my_putstr("\n-> ");
}

void signal_handler2(int i)
{
    if (i == SIGINT)
        my_putstr("\n");
}

int execution_ext(pid_t pad, char **env, char **cmdstore, char *exec)
{
    int status = 0;

    signal(SIGINT, signal_handler2);
    if (pad == -1)
        exit(EXIT_ERROR);
    else if (pad == 0) {
        signal(SIGINT, SIG_DFL);
        execve(exec, cmdstore, env);
        exit(EXIT_SUCCESS);
    } else {
        waitpid(pad, &status, WUNTRACED);
        signal(SIGINT, signal_handler);
        return segfault(status);
    }
}