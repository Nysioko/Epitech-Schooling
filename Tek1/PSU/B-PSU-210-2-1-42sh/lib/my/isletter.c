/*
** EPITECH PROJECT, 2021
** isletter
** File description:
** for minishell
*/

#include "my.h"

bool isletter(char letter)
{
    if ((letter < 'a' && letter > 'Z') || letter > 'z' || letter < 'A')
        return false;
    return true;
}