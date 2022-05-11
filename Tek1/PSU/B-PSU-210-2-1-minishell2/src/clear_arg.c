/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** clear_arg
*/

#include "my.h"

char *clear_arg(char *str)
{
    int j = 0;
    int i = 0;
    int o = 0;
    char *clear_argument = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (clear_argument == NULL)
        return NULL;
    for (; str[i] == ' ' || str[i] == '\t'; i++);
    for (; str[i] != 0; i++, o++) {
        for (j = 0; str[i] == ' ' || str[i] == '\t'; i++, j++);
        if (str[i] == '\0')
            break;
        if (j != 0) {
            clear_argument[o] = ' ';
            o += 1;
        }
        clear_argument[o] = str[i];
    }
    clear_argument[o] = '\0';
    return clear_argument;
}