/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** alnum
*/

#include "my.h"

bool is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_')
        return true;
    return false;
}

bool check_inibit(char *str, int *i)
{
    if (str[(*i) - 1] == '\\' && is_alphanum(str[(*i)]))
        return true;
    else if (str[(*i) - 1] == '\\')
        return false;
    return true;
}