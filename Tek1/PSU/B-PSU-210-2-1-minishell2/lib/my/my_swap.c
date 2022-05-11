/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_swap
*/

void my_swap(int *x, int *y)
{
    int z;

    z = *x;
    *x = *y;
    *y = z;
}