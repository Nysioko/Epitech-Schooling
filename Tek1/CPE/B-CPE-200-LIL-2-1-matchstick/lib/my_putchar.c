/*
** EPITECH PROJECT, 2021
** libmy 2.0
** File description:
** my_putchar
*/

#include "../include/matchstick.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}