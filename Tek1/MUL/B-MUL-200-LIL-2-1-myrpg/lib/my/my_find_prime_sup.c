/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** superior prime number
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = nb;
    if (nb == 0)
        return (0);
    if (nb == 1)
        return (1);
    while (my_is_prime(i) == 0)
        i++;
    return (i);
}
