/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-matchstick
** File description:
** player2
*/

#include "../include/matchstick.h"

int function1(matchstick_t *match, int o, int nb)
{
    if (nb > match->j) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(nb);
        my_putstr(" matches per turn\n");
        return player_line(match);
    }
    remove_stick(match, o, nb, 45);
    return EXIT_SUCCESS;
}