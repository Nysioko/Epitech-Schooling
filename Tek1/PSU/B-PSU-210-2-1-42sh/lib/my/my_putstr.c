/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** displaying string chars
*/

#include "my.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
