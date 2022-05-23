/*
** EPITECH PROJECT, 2020
** my_charswap
** File description:
** my_swap for characters
*/

void my_charswap(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}