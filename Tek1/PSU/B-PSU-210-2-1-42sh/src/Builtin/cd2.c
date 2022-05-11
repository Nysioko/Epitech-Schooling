/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** cd2
*/

#include "sh.h"

void go_oldpwd(char *oldpwd, sh_t *sh)
{
    if (oldpwd != NULL) {
        if (oldpwd[0] == '\"')
            remove_char_wmalloc(oldpwd, 0);
        if (oldpwd[my_strlen(oldpwd) - 1] == '\"')
            remove_char_wmalloc(oldpwd, my_strlen(oldpwd) - 1);
        chdir(oldpwd);
        free(oldpwd);
    } else if (sh->display) {
        sh->display ?
        write(2, ": No such file or directory.\n", 29) : sh->display;
        sh->status = 84;
    }
}

void cd_error(sh_t *sh, char *dir)
{
    struct stat si;

    if (contains(sh->str, " ") && sh->display) {
        write(2, "cd: Too many arguments.\n", 24);
        sh->status = 84;
        return;
    }
    if (stat(dir, &si) == -1 && sh->display) {
        write(2, dir, my_strlen(dir));
        write(2, ": No such file or directory.\n", 29);
        sh->status = 84;
        return;
    }
    if (!(S_ISDIR(si.st_mode)) && sh->display) {
        write(2, dir, my_strlen(dir));
        write(2, ": Not a directory.\n", 19);
        sh->status = 84;
        return;
    }
}