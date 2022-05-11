/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** aliases
*/

#include "sh.h"

char *replace_aliase4(char *tmp_str, char *tmp_str2,
char *tmp_str3, linked_t *tmp)
{
    tmp_str = malloc(sizeof(char) * (my_strlen(tmp_str2) + my_strlen(tmp_str3) +
    my_strlen(tmp->func) + 2));
    if (!tmp_str)
        exit(84);
    tmp_str[0] = '\0';
    my_strcat_clean(tmp_str, tmp_str2);
    my_strcat_clean(tmp_str, tmp->func);
    my_strcat_clean(tmp_str, tmp_str3);
    free(tmp_str2);
    free(tmp_str3);
    return tmp_str;
}

char *replace_aliases3(char *tmp_str, linked_t *tmp, int a)
{
    char *tmp_str2 = extract_str(tmp_str, 0, a, '\0');
    char *tmp_str3;

    if (!tmp_str2)
        exit(84);
    tmp_str3 = extract_str(tmp_str, a + my_strlen(tmp->alias),
    my_strlen(tmp_str), '\0');
    if (!tmp_str3)
        exit(84);
    free(tmp_str);
    return replace_aliase4(tmp_str, tmp_str2, tmp_str3, tmp);
}

char *replace_aliases2(char *tmp_str, linked_t *tmp)
{
    int tmp_int = 0;
    int a = 0;

    for (int i = 0; tmp_str[i] != '\0'; i++) {
        for (tmp_int = i, a = 0; tmp_str[i] == tmp->alias[a] &&
        tmp_str[i] != '\0'; i++, a++);
        if (a == my_strlen(tmp->alias))
            tmp_str = replace_aliases3(tmp_str, tmp, tmp_int);
        if (i >= my_strlen(tmp_str))
            i = my_strlen(tmp_str) - 1;
    }
    return tmp_str;
}

char *replace_aliases(char *str, sh_t *sh)
{
    char *tmp_str = my_strdup(str);

    if (!tmp_str)
        exit(84);
    for (linked_t *tmp = sh->alias; tmp != NULL; tmp = tmp->next) {
        if (is_the_alias(str, tmp->alias) && !contains(str, "alias"))
            tmp_str = replace_aliases2(tmp_str, tmp);
    }
    return tmp_str;
}

bool is_the_alias(char *str, char *str2)
{
    int a;

    for (int i = 0; str[i] != '\0'; i++) {
        for (a = 0; str[i] == str2[a] && str[i] != '\0'; a++, i++);
        if (a == my_strlen(str2) && (str[i] == ' ' || str[i] == '\0'))
            return true;
        if (str[i] == '\0')
            i--;
    }
    return false;
}