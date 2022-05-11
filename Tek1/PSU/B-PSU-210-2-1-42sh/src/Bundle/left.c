/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** left
*/

#include "sh.h"

char *simple_left(char *str, int i)
{
    int a;
    int b;
    char *tmp;
    char *tmp2;
    char *new = malloc(sizeof(char) * (my_strlen(str) + 10));

    !new ? exit(84) : new;
    new[0] = '\0';
    for (b = i - 1; b > 0 && str[b] == '<'; b--);
    for (a = i; str[a] != '>' && str[a] != '\0' && str[a] != '|'; a++);
    tmp = get_file(str, 0, b);
    tmp2 = get_file(str, i, a);
    my_strcat_clean(new, "cat ");
    my_strcat_clean(new, tmp2);
    my_strcat_clean(new, " | ");
    my_strcat_clean(new, tmp);
    my_strcat_clean(new, &str[a]);
    free(tmp);
    free(tmp2);
    return new;
}

char *choose_left(char *str, int a, int i)
{
    char *new;

    if (a == 0) {
        new = my_strdup(str);
        if (!new)
            exit(84);
    } else if (a == 1)
        new = simple_left(str, i);
    else
        new = double_left(str, i);
    return new;
}

char *left(char *str, sh_t *sh)
{
    int a = 0;
    int x = 0;

    for (int i = 0, b = 0; str[i] != '\0'; i++) {
        for (b = 0; str[i] == '<'; i++, a++, b++, x = i);
        if (b > 2) {
            write(2, "Missing name for redirect.\n", 27);
            sh->status = 84;
            sh->quit = true;
            return NULL;
        }
        i = str[i] == '\0' ? i - 1 : i;
    }
    if (a > 2 || sh->quit) {
        write(2, "Ambiguous input redirect.\n", 26);
        sh->status = 84;
        sh->quit = true;
        return NULL;
    }
    return choose_left(str, a, x);
}