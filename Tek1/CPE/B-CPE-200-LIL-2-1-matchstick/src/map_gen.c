/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-matchstick
** File description:
** map_gen
*/

#include "../include/matchstick.h"

void stick_gen2(matchstick_t *match, int o, int count)
{
    for (int kiwi = 0; match->map[o][kiwi] != '\0'; kiwi++) {
        if (kiwi >= ((my_strlen(match->map[o]) - 1) / 2) - count
        && kiwi <= ((my_strlen(match->map[o]) - 1) / 2) + count)
            match->map[o][kiwi] = '|';
    }
}

void stick_gen(matchstick_t *match)
{
    for (int o = 1; match->map[o + 1] != NULL; o++) {
        stick_gen2(match, o, o - 1);
    }
}

void map_star_gen(matchstick_t *match)
{
    for (int i = 0; match->map[0][i] != '\0'; i++) {
        match->map[0][i] = '*';
        match->map[match->i + 1][i] = '*';
    }
    for (int x = 0; match->map[x] != NULL; x++) {
        match->map[x][0] = '*';
        match->map[x][my_strlen(match->map[x]) - 1] = '*';
    }
    stick_gen(match);
}

void map_space_filler(char **av, matchstick_t *match)
{
    int i = 0;
    int j;
    match->map = malloc(sizeof(char *) * (my_getnbr(av[1]) + 3));

    for (; i != (my_getnbr(av[1]) + 2); i++) {
        match->map[i] = malloc(sizeof(char) * ((my_getnbr(av[1]) * 2) + 2));
        for (j = 0; j != (my_getnbr(av[1]) * 2) + 1; j++) {
            match->map[i][j] = ' ';
        }
        match->map[i][j] = '\0';
    }
    match->map[i] = NULL;
    return (map_star_gen(match));
}
