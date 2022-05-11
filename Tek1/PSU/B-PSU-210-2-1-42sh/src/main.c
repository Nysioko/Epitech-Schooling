/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** main
*/

#include "sh.h"

static char *new_line(sh_t *sh)
{
    char *line = NULL;

    isatty(0) ? display_prompt(sh->status) : 0;
    init_termios(&sh->old_term, &sh->new_term);
    line = my_getline(sh);
    reset_termios(&sh->old_term);
    if (line == NULL) {
        isatty(0) ? write(1, "exit\n", 5) : 0;
        free_charss(sh->env);
        remove_all_nodes(sh->alias, sh->history);
        exit(0);
    }
    if (line[my_strlen(line) - 1] == '\n')
        line[my_strlen(line) - 1] = '\0';
    return (line);
}

void main_loop3(sh_t *sh, char *str)
{
    char *aliases;

    sh->left = false;
    sh->right = false;
    sh->quit = false;
    sh->old_pipe = NULL;
    sh->new_pipe = NULL;
    aliases = replace_aliases(str, sh);
    sh->str = filter_str(aliases);
    free(aliases);
    if (sh->str == NULL)
        exit(84);
    sh->args = split(sh->str, " ", 1);
    if (sh->args == NULL)
        exit(84);
    if (sh->args[0][0] != '\0')
        check_special_char(sh);
    free_charss(sh->args);
    free(sh->str);
}

void main_loop2(sh_t *sh, char *str)
{
    char *redir_left;

    sh->mult = split(str, ";", 0);
    if (!sh->mult)
        exit(84);
    for (int i = 0; sh->mult[i] != NULL; i++) {
        sh->left = false;
        sh->right = false;
        sh->quit = false;
        sh->old_pipe = NULL;
        sh->new_pipe = NULL;
        redir_left = left(sh->mult[i], sh);
        check_if_separators(sh, redir_left);
        free(redir_left);
    }
    free_charss(sh->mult);
}

int main_loop(sh_t *sh)
{
    char *str;
    linked_t *history;

    sh->history = NULL;
    while (true) {
        sh->quit = false;
        sh->history_tmp = NULL;
        str = new_line(sh);
        history = new_node();
        history->func = str;
        link_node(&sh->history, history);
        str = echo_cmd(str, sh->status);
        signal(SIGINT, sig_handler2);
        if (!sh->quit)
            main_loop2(sh, str);
        signal(SIGINT, sig_handler);
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    sh_t sh;

    if (ac != 1)
        return (84);
    av[1] = NULL;
    signal(SIGINT, sig_handler);
    sh.env = malloc(sizeof(char *) * (my_charsslen(env) + 1));
    if (sh.env == NULL)
        return 84;
    for (int i = 0; env[i] != NULL; i++) {
        sh.env[i] = my_strdup(env[i]);
        if (sh.env[i] == NULL)
            return 84;
    }
    sh.env[my_charsslen(env)] = NULL;
    sh.status = 0;
    sh.alias = NULL;
    sh.save_path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin";
    create_ls_alias(&sh);
    return main_loop(&sh);
}