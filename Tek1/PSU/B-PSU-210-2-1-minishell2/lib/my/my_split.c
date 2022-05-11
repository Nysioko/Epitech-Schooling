/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** my_split
*/

#include "my.h"

int check_spliter(char *str, char split)
{
    int i = 0;
    int j = 1;

    while (str[i] != '\0') {
        if (str[i] == split && str[i + 1] != split)
            j++;
        i++;
    }
    return j;
}

char **str_filler(char **spliter, char *str, char split, int i)
{
    int a = 0;
    int s = 0;
    int z = 0;

    while (str[a] != '\0') {
        while (str[a] == split && str[a + 1] == split && s < i)
            a++;
        if (str[a] == split && s < i - 1) {
            spliter[s][z] = '\0';
            z = 0;
            s++;
        } else {
            spliter[s][z] = str[a];
            z++;
        }
        a++;
    }
    spliter[s][z] = '\0';
    spliter[s + 1] = NULL;
    return spliter;
}

char **spliter(char *str, char split, int i)
{
    char **spliter;
    int k = 0;

    if (i > check_spliter(str, split) || i <= 0)
        i = check_spliter(str, split);
    else
        i++;
    spliter = malloc(sizeof(char *) * (i + 1));
    if (spliter == NULL)
        exit(EXIT_ERROR);
    while (k != i + 1) {
        spliter[k] = malloc(sizeof(char *) * (my_strlen(str) + 4));
        if (spliter[k] == NULL)
            exit(EXIT_ERROR);
        k++;
    }
    return str_filler(spliter, str, split, i);
}