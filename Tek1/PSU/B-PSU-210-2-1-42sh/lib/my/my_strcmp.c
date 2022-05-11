/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** nothing
*/

#include "my.h"
#include <stdlib.h>

char *othan_nb(char *str1)
{
    char *s1 = malloc(sizeof(char) * (my_strlen(str1) + 5));
    int x = 0;

    !s1 ? exit(84) : s1;
    for (int i = 0; str1[i] != '\0'; i++) {
        if ((str1[i] >= '0' && str1[i] <= '9') || str1[i] == '-') {
            s1[x] = str1[i];
            x++;
        }
    }
    s1[x] = '\0';
    free(str1);
    return (s1);
}

int free_cmp(char *s1, char *s2, int i)
{
    free(s1);
    free(s2);
    return (i);
}

int mini(char *s1, char *s2)
{
    int i = 0;
    int x = 0;

    if (s1[0] == '-' && s2[0] != '-')
        return (free_cmp(s1, s2, 0));
    if (s1[0] != '-' && s2[0] == '-')
        return (free_cmp(s1, s2, 1));
    for (i = 0; s1[i] != '\0' || s2[x] != '\0'; i++) {
        if (s1[i] > s2[x])
            return (free_cmp(s1, s2, 0));
        else if (s1[i] < s2[x])
            return (free_cmp(s1, s2, 1));
        else
            x++;
    }
    return (free_cmp(s1, s2, 2));
}

int compare(char *s1, char *s2)
{
    int i = 0;
    int x = 0;

    if (s1[0] == '-' || s2[0] == '-')
        return (mini(s1, s2));
    for (i = 0; s1[i] != '\0' || s2[x] != '\0'; i++) {
        if (s1[i] < s2[x])
            return (free_cmp(s1, s2, 0));
        else if (s1[i] > s2[x])
            return (free_cmp(s1, s2, 1));
        else
            x++;
    }
    return (free_cmp(s1, s2, 2));
}

int my_strcmp(char const *str1, char const *str2)
{
    char *s1;
    char *s2;

    if (str1 == NULL || str2 == NULL)
        return (84);
    s1 = my_strdup(str1);
    s2 = my_strdup(str2);
    s1 = othan_nb(s1);
    s2 = othan_nb(s2);
    if (((my_strlen(s1) < my_strlen(s2)) && (s1[0] != '-' && s2[0] != '-')) ||
    ((my_strlen(s1) > my_strlen(s2)) && (s1[0] == '-' && s2[0] == '-')))
        return (free_cmp(s1, s2, 0));
    else if (((my_strlen(s1) > my_strlen(s2)) && (s1[0] != '-' && s2[0] !='-'))
    || ((my_strlen(s1) < my_strlen(s2)) && (s1[0] == '-' && s2[0] == '-')))
        return (free_cmp(s1, s2, 1));
    return (compare(s1, s2));
}
