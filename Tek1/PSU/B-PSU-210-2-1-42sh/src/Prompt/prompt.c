/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** prompt
*/

#include "sh.h"

void display_prompt2(int status, char *str, char *str2, int i)
{
    bool git = !my_alpcmp(str2, "") ? true : false;

    if (status == 0)
        my_printf(CGRN"➜  ");
    else
        my_printf(CRED"➜  ");
    my_printf(CCYN);
    my_printf(&str[i + 1]);
    if (git) {
        my_printf(" "CBLU"git:("CRED);
        my_printf(str2);
        my_printf(CBLU")");
    }
    my_printf(CYEL" ✗ "CDEF);
    free(str2);
    free(str);
}

void display_prompt(int status)
{
    int i;
    char *str2 = get_branch();
    char *str = getcwd(NULL, 500);

    if (!str)
        exit(84);
    for (i = my_strlen(str); str[i] != '/'; i--);
    my_printf(CBLD);
    display_prompt2(status, str, str2, i);
}