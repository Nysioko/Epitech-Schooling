/*
** EPITECH PROJECT, 2021
** 42SH
** File description:
** check_if_separators
*/

#include "sh.h"

void or_cmd(sh_t *sh, char *str, bool *skip, int *status)
{
    char **spl = split(str, "||", 0);

    if (!spl)
        exit(84);
    for (int i = 0; spl[i] != NULL; i++) {
        if (!(*skip)) {
            main_loop3(sh, spl[i]);
            (*status) = sh->status;
        }
        (*skip) = (*status) == 0 ? true : false;
    }
    free_charss(spl);
    if (*skip)
        (*status) = 1;
}

bool check_if_separators(sh_t *sh, char *str)
{
    char **spl = split(str, "&&", 0);
    bool skip = false;
    int status;

    if (!spl)
        exit(84);
    for (int i = 0; spl[i] != NULL; i++) {
        if (contains(spl[i], "||") && !skip)
            or_cmd(sh, spl[i], &skip, &status);
        else if (!skip) {
            main_loop3(sh, spl[i]);
            status = sh->status;
        }
        skip = status == 0 ? false : true;
    }
    free_charss(spl);
    return true;
}