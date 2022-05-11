/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** get nbr
*/

#include <stdlib.h>
#include "my.h"

int ifneg2(char const *str, int n)
{
    if (str[n] == '-')
        return (-1);
    return (1);
}

char *ifnumber2(char const *str, int n, int minus)
{
    char *s1 = malloc(sizeof(char) * my_strlen(str));
    int counter = 0;

    !s1 ? exit(84) : s1;
    if (minus == -1) {
        s1[counter] = '-';
        counter++;
    }
    for (; str[n] >= '0' && str[n] <= '9'; counter++) {
        s1[counter] = str[n];
        n++;
    }
    return (s1);
}

char *my_strgetnbr(char const *str, int n)
{
    int minus = 1;

    if (str[n] == '(')
        return (my_strgetnbr(str, n + 1));
    for (; str[n] != '\0'; n++) {
        minus = minus * (ifneg2(str, n));
        if (str[n] >= '0' && str[n] <= '9')
            return (ifnumber2(str, n, minus));
    }
    return (NULL);
}