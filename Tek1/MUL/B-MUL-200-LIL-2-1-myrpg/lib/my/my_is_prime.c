/*
** EPITECH PROJECT, 2020
** my_is_prime.c
** File description:
** reference to JJBA part 6, father pucci
*/

int my_is_prime(int nb)
{
    int i;

    if (nb == 0)
        return (0);
    for (i = 2; i != nb - 1; i++)
    {
        if (nb %i == 0)
            return (0);
    }
    return (1);
}
