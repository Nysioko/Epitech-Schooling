/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** filer_str
*/

#include "sh.h"

char *filer_str2(char *str2, int j)
{
    char *str3;

    str2[j] = '\0';
    str3 = my_strdup(str2);
    free(str2);
    if (str3 == NULL)
        return NULL;
    return str3;
}

char *filter_str(char *str)
{
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));
    int x;
    int a;
    int j = 0;

    if (str2 == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        for (; j == 0 && (str[i] == ' ' || str[i] == '\t'); i++);
        for (x = 0, a = i; str[a] == ' ' || str[a] == '\t'; x++)
            a++;
        if (x > 0) {
            x = 0;
            str2[j] = str[a] == '\0' ? '\0' : ' ';
            i = a - 1;
        } else
            str2[j] = str[i];
        j++;
    }
    return filer_str2(str2, j);
}