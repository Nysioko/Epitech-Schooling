/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** manage_char2
*/

#include "sh.h"

void manage_builtins(sh_t *sh, char *str)
{
    char *cmp[8] = {"cd", "setenv", "unsetenv", "alias",
    "exit", "true", "false", NULL};
    char **args = split(str, " ", 1);

    if (!args)
        exit(84);
    for (int i = 0; cmp[i] != NULL; i++) {
        if (my_alpcmp(args[0], cmp[i]))
            sh->display = false;
    }
    if (!sh->display)
        sh->env = cmd_handler(sh);
    sh->display = true;
    free_charss(args);
}

int *new_pipe(void)
{
    int *new = malloc(sizeof(int) * 2);

    if (!new)
        exit(84);
    pipe(new);
    return new;
}

bool null_command(char **spl)
{
    for (int i = 0; spl[i] != NULL; i++) {
        if (contains(spl[i], "|")) {
            write(2, "Invalid null command.\n", 22);
            free_charss(spl);
            return true;
        }
    }
    return false;
}