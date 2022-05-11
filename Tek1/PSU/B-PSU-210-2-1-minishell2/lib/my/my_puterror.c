/*
** EPITECH PROJECT, 2021
** my_puterror.c
** File description:
** BOOTSTRAP - BQS
*/

#include "my.h"

void my_puterror(char *str)
{
    int i = my_strlen(str);
    write(2, str, i);
}