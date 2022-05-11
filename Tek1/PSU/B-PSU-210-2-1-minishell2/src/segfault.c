/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** segfault
*/

#include "my.h"

void coredumped(int status)
{
    if (WTERMSIG(status) == SIGSEGV)
        my_puterror("Segmentation fault (core dumped)\n");
    if (WTERMSIG(status) == SIGABRT)
        my_puterror("Aborted (core dumped)\n");
    if (WTERMSIG(status) == SIGFPE)
        my_puterror("Floating exception (core dumped)\n");
}

void without_cd(int status)
{
    if (WTERMSIG(status) == SIGFPE)
        my_puterror("Floating exception\n");
    if (WTERMSIG(status) == SIGABRT)
        my_puterror("Aborted\n");
    if (WTERMSIG(status) == SIGSEGV)
        my_puterror("Segmentation fault\n");
}

int segfault(int status)
{
    if (WIFSIGNALED(status)) {
        if (__WCOREDUMP(status))
            coredumped(status);
        else
            without_cd(status);
        return EXIT_ERROR;
    }
    return EXIT_ERROR;
}