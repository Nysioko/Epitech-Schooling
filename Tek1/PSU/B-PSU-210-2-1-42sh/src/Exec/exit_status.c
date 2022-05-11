/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** exit_status
*/

#include "sh.h"

void segmentation(sh_t *sh)
{
    if (WTERMSIG(sh->status) == SIGSEGV && __WCOREDUMP(sh->status)) {
        write(2, "Segmentation fault (core dumped)\n", 33);
        sh->status = 139;
    } else if (WTERMSIG(sh->status) == SIGSEGV) {
        write(2, "Segmentation fault\n", 19);
        sh->status = 139;
    }
}

void aborted(sh_t *sh)
{
    if (WTERMSIG(sh->status) == SIGABRT && __WCOREDUMP(sh->status)) {
        write(2, "Aborted (core dumped)\n", 22);
        sh->status = 134;
    } else if (WTERMSIG(sh->status) == SIGABRT) {
        write(2, "Aborted\n", 8);
        sh->status = 134;
    }
}

void fpe(sh_t *sh)
{
    if (WTERMSIG(sh->status) == SIGFPE && __WCOREDUMP(sh->status)) {
        write(2, "Floating exception (core dumped)\n", 33);
        sh->status = 136;
    } else if (WTERMSIG(sh->status) == SIGFPE) {
        write(2, "Floating exception\n", 19);
        sh->status = 136;
    }
}

int exit_child(sh_t *sh)
{
    if (WIFSIGNALED(sh->status)) {
        segmentation(sh);
        aborted(sh);
        fpe(sh);
        if (WTERMSIG(sh->status) == SIGINT)
            sh->status = 1;
    }
    sh->status = WEXITSTATUS(sh->status);
    return (1);
}