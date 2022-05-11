/*
** EPITECH PROJECT, 2020
** my_alphcmp
** File description:
** supposed to be my_strcmp
*/

#include "my.h"
#include <stdlib.h>

bool my_alpcmp(char *s1, char *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++);
    if (s1[i] == s2[i])
        return true;
    return false;
}