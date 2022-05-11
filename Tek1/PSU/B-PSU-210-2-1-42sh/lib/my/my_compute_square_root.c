/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** utiliser, modulo, boucle si find smth
*/

int my_compute_square_root(int nb)
{
    int i;

    for (i = 0; i * i != nb; i++) {
        if (i > nb)
            return (0);
    }
    return (i);
}
