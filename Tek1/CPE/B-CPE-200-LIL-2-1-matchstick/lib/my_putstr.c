/*
** EPITECH PROJECT, 2020
** Libmy
** File description:
** my_putstr
*/

#include "../include/matchstick.h"

void my_putstr(char *str)
{
    int i = my_strlen(str);
    write(1, str, i);
}
