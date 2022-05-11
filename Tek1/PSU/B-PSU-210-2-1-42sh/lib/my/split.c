/*
** EPITECH PROJECT, 2021
** split.c
** File description:
** .split in java, more or less
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

static void coding_style(char **split, int *count, int *a)
{
    split[(*count)][(*a)] = '\0';
    (*a) = 0;
    (*count)++;
}

static void coding_style2(char **split, int **a, char *str)
{
    split[(*a[3])][(*a[0])] = str[(*a[2])];
    if (str[(*a[2])] == '\0')
        (*a[2])--;
}

void fill_split(char **split, char *str, char *to, int nb)
{
    int count = 0;
    int a = 0;
    bool quote = false;

    for (int i = 0, c = 0, tmp = 0, b = 0, t2 = 0; str[i] != '\0'; i++, a++) {
        if (str[i] == '\"')
            quote = quote ? false : true;
        for (c = 0, tmp = i; str[tmp] == to[c] && !quote; tmp++, c++);
        for (t2 = a != 0 ? i + 1 : i, b = 0;
        str[t2] == to[b] && !quote; t2++, b++);
        if (c == my_strlen(to) && b != my_strlen(to) && count < nb - 1) {
            i = tmp;
            coding_style(split, &count, &a);
        }
        coding_style2(split, (int *[4]){&a, &b, &i, &count}, str);
    }
    split[count][a] = '\0';
    split[count + 1] = NULL;
}

int check_split(char *str, char *to)
{
    int nb = 1;
    bool quote = false;
    int a = 0;
    int b = 0;
    int tmp = 0;
    int t2 = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\"')
            quote = quote ? false : true;
        for (a = 0, tmp = i; str[tmp] == to[a] && !quote; tmp++, a++);
        for (t2 = a != 0 ? i + 1 : i, b = 0;
        str[t2] == to[b] && !quote; t2++, b++);
        if (a == my_strlen(to) && b != my_strlen(to))
            nb++;
    }
    return (nb);
}

char **split(char *str, char *to, int nb)
{
    char **split;

    if (str == NULL)
        return NULL;
    if (nb <= 0)
        nb = check_split(str, to);
    else if (check_split(str, to) < nb)
        nb = check_split(str, to);
    else
        nb++;
    split = malloc(sizeof(char *) * (nb + 1));
    if (split == NULL)
        return (NULL);
    for (int i = 0; i != nb; i++) {
        split[i] = malloc(sizeof(char) * (my_strlen(str) + 2));
        if (split[i] == NULL)
            return (NULL);
    }
    fill_split(split, str, to, nb);
    return (split);
}