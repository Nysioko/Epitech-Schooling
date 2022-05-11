/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** redir
*/

#include "sh.h"

void manage_pipes2(sh_t *sh, int i, char **spl)
{
    if (i != 0) {
        dup2(sh->old_pipe[0], 0);
        close(sh->old_pipe[1]);
        close(sh->old_pipe[0]);
    }
    if (spl[i + 1] != NULL) {
        close(sh->new_pipe[0]);
        dup2(sh->new_pipe[1], 1);
        close(sh->new_pipe[1]);
    }
}

void manage_pipes(sh_t *sh, char *str, int i, char **spl)
{
    if (fork() == 0) {
        manage_pipes2(sh, i, spl);
        if (sh->right)
            exit(manage_redirection_right(sh, str));
        sh->str = str;
        sh->args = split(sh->str, " ", 1);
        if (!sh->args)
            exit(84);
        sh->env = cmd_handler(sh);
        free_charss(sh->args);
        remove_all_nodes(sh->alias, sh->history);
        exit(sh->status);
    }
    manage_builtins(sh, str);
    if (sh->old_pipe != NULL) {
        close(sh->old_pipe[0]);
        close(sh->old_pipe[1]);
    }
    signal(SIGINT, sig_handler2);
}

void handle_pipes(sh_t *sh, char *str, int i, char **spl)
{
    if (spl[i + 1] != NULL)
        sh->new_pipe = new_pipe();
    manage_pipes(sh, str, i, spl);
    if (i != 0)
        free(sh->old_pipe);
    sh->old_pipe = sh->new_pipe;
}

void handle_string(char *str, char **spl, sh_t *sh, int i)
{
    sh->display = true;
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == '>' && ((sh->right && str[a - 1] != '>') ||
        spl[i + 1] != NULL)) {
            write(2, "Ambiguous input redirect.\n", 26);
            sh->status = 84;
            sh->quit = true;
            return;
        }
        sh->left = str[a] == '<' ? true : sh->left;
        sh->right = str[a] == '>' ? true : sh->right;
    }
    handle_pipes(sh, str, i, spl);
}

void check_special_char(sh_t *sh)
{
    char **spl = split(sh->str, "|", 0);
    char *str;

    if (!spl)
        exit(84);
    if (null_command(spl)) {
        sh->status = 84;
        return;
    }
    for (int i = 0; spl[i] != NULL; i++) {
        str = filter_str(spl[i]);
        handle_string(str, spl, sh, i);
        free(str);
        if (sh->quit)
            break;
    }
    free_charss(spl);
    while (wait(&sh->status) > 0);
    sh->status = WEXITSTATUS(sh->status);
}