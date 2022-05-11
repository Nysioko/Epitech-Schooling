/*
** EPITECH PROJECT, 2020
** my_putcc
** File description:
** displaying a char **
*/

#include "my.h"
#include <stdlib.h>

void my_putcharss(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        my_printf("%s\n", tab[i]);
}