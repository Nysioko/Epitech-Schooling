/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-matchstick
** File description:
** sticks
*/

#include "../include/matchstick.h"

void iffer(int o, int nb, int bool)
{
    if (bool == 45) {
        my_putstr("Player removed ");
        my_putnbr(nb);
        my_putstr(" match(es) from line ");
        my_putnbr(o);
        my_putchar('\n');
    } else {
        my_putstr("AI removed ");
        my_putnbr(nb);
        my_putstr(" match(es) from line ");
        my_putnbr(o);
        my_putchar('\n');
    }
}

void remove_stick(matchstick_t *match, int o, int nb, int bool)
{
    int x = nb;

    for (int k = my_strlen(match->map[o]); x != 0; k--) {
        if (match->map[o][k] == '|') {
            match->map[o][k] = ' ';
            x--;
        }
    }
    iffer(o, nb, bool);
}

int map_reader(matchstick_t *match, int o)
{
    int count = 0;

    for (int i = 0; match->map[o][i] != '\0'; i++) {
        if (match->map[o][i] == '|')
            count++;
    }
    return count;
}

int youlose(matchstick_t *match)
{
    int lose = 0;

    for (int i = 0; match->map[i] != NULL; i++) {
        for (int j = 0; match->map[i][j] != '\0'; j++)
            match->map[i][j] == '|' ? lose = 1 : lose;
        if (lose == 1)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}