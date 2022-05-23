/*
** EPITECH PROJECT, 2021
** split.c
** File description:
** .split in java, more or less
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void fill_split(char **split, char *str, char to_split, int nb)
{
    int count = 0;
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        for (; str[i] == to_split && str[i + 1] == to_split &&
        count < nb; i++);
        split[count][a] = str[i];
        a++;
        if (str[i] == to_split && count != nb - 1) {
            split[count][a - 1] = '\0';
            a = 0;
            count++;
        }
    }
    split[count][a] = '\0';
    split[nb] = NULL;
}

int check_split(char *str, char to_split)
{
    int nb = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_split && str[i + 1] != to_split)
            nb++;
    }
    return (nb);
}

char **split(char *str, char to_split, int nb)
{
    char **split;

    if (nb <= 0)
        nb = check_split(str, to_split);
    else if (check_split(str, to_split) < nb)
        nb = check_split(str, to_split);
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
    fill_split(split, str, to_split, nb);
    return (split);
}