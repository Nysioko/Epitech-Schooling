/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** exit
*/

#include "sh.h"
#include "my.h"

static void ifforest(sh_t *sh, char **exitsplited)
{
    if (my_charsslen(exitsplited) == 2 && my_strcmp(exitsplited[0], "exit")) {
        sh->status = atoi(exitsplited[1]);
    }
}

int exit_code2(sh_t *sh, char **exitsplited)
{
    for (int j = 0; exitsplited[1][j] != '\0'; j++) {
        if (exitsplited[1][j] < '0' || exitsplited[1][j] > '9') {
            perror("exit: Expression Syntax.\n");
            sh->status = 84;
            free_charss(exitsplited);
            sh->status = 1;
            return 84;
        }
        ifforest(sh, exitsplited);
    }
    free_charss(exitsplited);
    return 0;
}

int exit_code(sh_t *sh)
{
    char **exitsplited = split(sh->str, " ", 0);

    !exitsplited ? exit(84) : exitsplited;
    if (my_charsslen(exitsplited) > 3) {
        perror("exit: Expression Syntax.\n");
        sh->status = 84;
        free_charss(exitsplited);
        return 84;
    }
    if (my_charsslen(exitsplited) == 1) {
        free_charss(exitsplited);
        return 0;
    }
    return exit_code2(sh, exitsplited);
}

void exit_cmd(sh_t *sh, char *path)
{
    if (exit_code(sh) == 84)
        return;
    if (path != NULL)
        free(path);
    if (sh->display)
        my_printf("exit\n");
    free_charss(sh->args);
    free_charss(sh->env);
    free_charss(sh->mult);
    free(sh->str);
    remove_all_nodes(sh->alias, sh->history);
    exit(sh->status);
}