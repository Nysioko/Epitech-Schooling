/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-matchstick
** File description:
** iaecoplusdevparuntek1
*/

#include "../include/matchstick.h"

void iaecoplusdevparuntek1_2(matchstick_t *match, int line)
{
    int nb;

    if (match->i >= map_reader(match, line))
        nb = random() % map_reader(match, line) + 1;
    else
        nb = random() % match->i + 1;
    remove_stick(match, line, nb, 42);
}

void iaecoplusdevparuntek1(matchstick_t *match)
{
    int line = random() % match->i + 1;

    my_putstr("\nAI's turn...\n");
    if (map_reader(match, line) != 0)
        return iaecoplusdevparuntek1_2(match, line);
    for (int line = 1; match->map[line] != NULL; line++) {
        if (map_reader(match, line) != 0)
            return iaecoplusdevparuntek1_2(match, line);
    }
}