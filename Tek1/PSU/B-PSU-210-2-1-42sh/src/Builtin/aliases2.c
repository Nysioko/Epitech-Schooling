/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** aliases2
*/

#include "sh.h"

void create_ls_alias(sh_t *sh)
{
    linked_t *tmp;

    link_node(&sh->alias, new_node());
    sh->alias->alias = my_strdup("ls");
    if (!sh->alias->alias)
        exit(84);
    sh->alias->func = my_strdup("ls --color=tty");
    if (!sh->alias->func)
        exit(84);
    tmp = new_node();
    link_node(&sh->alias, tmp);
    tmp->alias = my_strdup("la");
    if (!sh->alias->alias)
        exit(84);
    tmp->func = my_strdup("ls -lAh --color=tty");
    if (!sh->alias->func)
        exit(84);
}

void create_alias(linked_t *tmp, char **spl, sh_t *sh)
{
    tmp = new_node();
    link_node(&sh->alias, tmp);
    tmp->alias = my_strdup(spl[1]);
    if (!tmp->alias)
        exit(84);
    tmp->func = my_strdup(spl[2]);
    if (!tmp->func)
        exit(84);
}

void manage_aliases(sh_t *sh, char **spl, linked_t *tmp)
{
    linked_t *tmp2 = NULL;

    for (linked_t *tmp3 = sh->alias; tmp3 != NULL; tmp3 = tmp3->next) {
        if (my_alpcmp(spl[1], tmp3->alias))
            tmp2 = tmp3;
    }
    if (tmp2 == NULL)
        create_alias(tmp, spl, sh);
    else {
        free(tmp2->func);
        tmp2->func = my_strdup(spl[2]);
        if (!tmp2->func)
            exit(84);
    }
}

void aliases(sh_t *sh, char *path)
{
    char **spl;
    linked_t *tmp = NULL;

    spl = split(sh->str, " ", 0);
    if (!spl)
        exit(84);
    if (my_charsslen(spl) == 3 && my_alpcmp(spl[0], "alias")) {
        manage_aliases(sh, spl, tmp);
        free(path);
    }
    free_charss(spl);
}