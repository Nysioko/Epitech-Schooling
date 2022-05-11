/*
** EPITECH PROJECT, 2020
** strcmp
** File description:
** task6
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
    if (my_strlen(s1) > my_strlen(s2))
        return EXIT_FAILURE;
    else if (my_strlen(s1) < my_strlen(s2))
        return -1;
    for (int count = 0; count < my_strlen(s1); count++)
        if (s1[count] != s2[count])
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
