/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** double_left
*/

#include "sh.h"

static char *new_line(char *tmp, char *tmp2)
{
    char *str = NULL;
    size_t len;
    ssize_t size;

    my_printf("? ");
    size = getline(&str, &len, stdin);
    if (size == -1) {
        free(str);
        free(tmp);
        free(tmp2);
        exit(0);
    }
    if (!str)
        exit(84);
    str[my_strlen(str) - 1] = '\0';
    return str;
}

char *cat_left(char *func, char *catted, char *str, int a)
{
    char *new = malloc(sizeof(char) * (my_strlen(catted) +
    my_strlen(str) + 10));

    if (!new)
        exit(84);
    new[0] = '\0';
    my_strcat_clean(new, "echo \"");
    my_strcat_clean(new, catted);
    my_strcat_clean(new, "\" | ");
    my_strcat_clean(new, func);
    my_strcat_clean(new, &str[a]);
    free(catted);
    return new;
}

char *get_double_left(char *func, char *file, char *str, int a)
{
    char *tmp;
    char *catted = my_strdup("");
    char *tmp2;

    !catted ? exit(84) : catted;
    while (true) {
        tmp = new_line(func, file);
        if (my_alpcmp(tmp, file)) {
            free(tmp);
            break;
        }
        tmp[my_strlen(tmp) + 1] = '\0';
        tmp[my_strlen(tmp)] = '\n';
        tmp2 = my_strcat(catted, tmp);
        !tmp2 ? exit(84) : tmp2;
        free(catted);
        catted = tmp2;
        free(tmp);
    }
    return cat_left(func, catted, str, a);
}

char *double_left(char *str, int i)
{
    char *new;
    int b;
    int a;
    char *tmp;
    char *tmp2;

    for (b = i - 1; b > 0 && str[b] == '<'; b--);
    for (a = i; str[a] != '>' && str[a] != '\0' && str[a] != '|'; a++);
    tmp = get_file(str, 0, b);
    tmp2 = get_file(str, i, a);
    new = get_double_left(tmp, tmp2, str, a);
    free(tmp);
    free(tmp2);
    return new;
}