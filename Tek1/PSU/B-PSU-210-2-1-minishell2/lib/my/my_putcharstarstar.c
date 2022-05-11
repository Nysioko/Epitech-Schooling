/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-matchstick
** File description:
** my_putcharstarstar
*/

#include "my.h"

void my_putcharstarstar(char **tablo)
{
    for (int i = 0; tablo[i] != NULL; i++) {
        write(1, tablo[i], my_strlen(tablo[i]));
        write(1, "\n", 1);
    }
}