/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** my_freeter
*/

#include "../include/matchstick.h"

void my_freeter(char **spliter)
{
    int i = 0;

    while (spliter[i] != NULL) {
        free(spliter[i]);
        i++;
    }
    free(spliter[i]);
    free(spliter);
}