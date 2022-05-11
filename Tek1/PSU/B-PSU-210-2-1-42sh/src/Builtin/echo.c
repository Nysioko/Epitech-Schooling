/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** echo
*/

#include "sh.h"

void verif_malloc(char *tmp, char **tmp2, char **tmp3, char *str)
{
    if (!tmp)
        exit(84);
    (*tmp2) = malloc(sizeof(char));
    if (!(*tmp2))
        exit(84);
    (*tmp3) = my_strdup(str);
    if (!(*tmp3))
        exit(84);
}

static void replace(char **tmp3, int i, char *str, char *status)
{
    char *tmp = extract_str(str, 0, i - 1, '\0');
    char *tmp2;

    if (!tmp)
        exit(84);
    free((*tmp3));
    tmp2 = my_strcat(tmp, status);
    if (!tmp2)
        exit(84);
    (*tmp3) = my_strcat(tmp2, &str[i + 1]);
    if (!(*tmp3))
        exit(84);
    free(tmp2);
    free(tmp);
}

char *manage_echo(char *str, int status)
{
    char *stat = malloc(sizeof(char) * 11);
    char *tmp2 = NULL;
    char *tmp3 = NULL;

    verif_malloc(stat, &tmp2, &tmp3, str);
    int_to_str(status, stat);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '$' && str[i + 1] == '?') {
            i++;
            replace(&tmp3, i, str, stat);
        }
    }
    free(tmp2);
    str = my_strdup(tmp3);
    if (!str)
        exit(84);
    free(tmp3);
    free(stat);
    return str;
}

char *echo_cmd(char *str, int status)
{
    char **spl = split(str, " ", 0);

    if (!spl)
        exit(84);
    for (int i = 0; spl[i] != NULL; i++) {
        if (contains(spl[i], "$?")) {
            str = manage_echo(str, status);
            break;
        }
    }
    free_charss(spl);
    return str;
}