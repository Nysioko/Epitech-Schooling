/*
** EPITECH PROJECT, 2020
** my_strswap
** File description:
** my_swap for a string
*/

void my_strswap(char **s1, char **s2)
{
    char *swap;

    swap = *s1;
    *s1 = *s2;
    *s2 = swap;
}