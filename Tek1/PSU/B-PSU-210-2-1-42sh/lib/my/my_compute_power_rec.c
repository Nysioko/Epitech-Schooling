/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** reclusive power
*/

int my_compute_power_rec(int nb, int p)
{
    int a = nb;
    if (p < 0)
        return (0);
    if (p == 1)
        return (a);
    if (p == 0)
        return (1);
    a = a * my_compute_power_rec(a, p - 1);
    return (a);
}
