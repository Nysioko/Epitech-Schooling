/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** clean_str
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char *clean_str(char *str, char to_remove)
{
    char *newstr = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i;
    int a = 0;

    if (newstr == NULL)
        return NULL;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != to_remove) {
            newstr[a] = str[i];
            a++;
        }
    }
    newstr[a] = '\0';
    return (newstr);
}