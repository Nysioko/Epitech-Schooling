/*
** EPITECH PROJECT, 2021
** extract_str
** File description:
** extract a string inside a string
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *extract_str(char *str, int side1, int side2, char end)
{
    char *newstr;
    int i;

    if (!(str))
        return (NULL);
    newstr = malloc(sizeof(char) * (my_strlen(str) + 2));
    if (newstr == NULL)
        return (NULL);
    if (side1 < 0)
        side1 = 0;
    if (side2 < 0 || side2 > my_strlen(str))
        side2 = my_strlen(str);
    for (i = 0; side1 != side2 && str[side1] != end; i++) {
        newstr[i] = str[side1];
        side1++;
    }
    newstr[i] = '\0';
    return (newstr);
}