/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** cmd_handler
*/

#include "sh.h"

void history_cmd(sh_t *sh, char *path)
{
    int i = 0;

    if (!sh->display)
        return;
    path[my_strlen(path)] = '\0';
    for (linked_t *tmp = sh->history; tmp->next != NULL; tmp = tmp->next, i++)
        my_printf("%d %s\n", i, tmp->func);
}

char **cmd_handler(sh_t *sh)
{
    char *path = my_getenv("PATH", sh->env);
    char *cmp[9] = {"alias", "exit", "true", "false", "history",
    "cd", "setenv", "unsetenv", NULL};
    void (*tablo[8]) (sh_t *, char *) = {aliases, exit_cmd,
    ftc_true, ftc_false, history_cmd, pre_cd, setenv_cmd, unsetenv_cmd};

    sh->status = 0;
    signal(SIGINT, sig_handler3);
    sh->str = globbing(sh->str);
    sh->str == NULL ? exit(84) : sh->str;
    for (int i = 0; cmp[i] != NULL; i++) {
        if (my_alpcmp(cmp[i], sh->args[0])) {
            (*tablo[i]) (sh, path);
            free(path);
            return sh->env;
        }
    }
    other_cmd(sh);
    free(path);
    return sh->env;
}