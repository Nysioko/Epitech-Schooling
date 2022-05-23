/*
** EPITECH PROJECT, 2020
** my_alphcmp
** File description:
** supposed to be my_strcmp
*/

#include "my.h"
#include <stdlib.h>

int my_alpcmp(char *s1, char *s2, int rec)
{
    char *str1 = s1;
    char *str2 = s2;

    if (str1 == NULL || str2 == NULL)
        return (84);
    if ((int)str1[rec] < (int)str2[rec])
        return (0);
    if ((int)str1[rec] > (int)str2[rec])
        return (1);
    if (((int)str1[rec] == (int)str2[rec]) && str1[rec] != '\0')
        return my_alpcmp(s1, s2, rec + 1);
    return (2);
}