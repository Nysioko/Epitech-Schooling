/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** clean_str
*/

#include "my.h"

char *clean_str(char *src, char del)
{
    int count = 0;
    int count2 = 0;
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        exit(EXIT_ERROR);
    while (src[count] != '\0') {
        if (src[count] != del) {
            dest[count2] = src[count];
            count2 += 1;
        }
        count++;
    }
    dest[count] = '\0';
    return (dest);
}
