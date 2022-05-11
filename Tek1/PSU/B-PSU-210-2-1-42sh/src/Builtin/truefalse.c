/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** truefalse
*/

#include "my.h"
#include "sh.h"

void ftc_true(sh_t *sh, char *path)
{
    path[my_strlen(path)] = '\0';
    sh->status = 0;
}

void ftc_false(sh_t *sh, char *path)
{
    path[my_strlen(path)] = '\0';
    sh->status = 1;
}