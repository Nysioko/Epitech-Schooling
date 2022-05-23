/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban
** File description:
** not help anymore
*/

#include "my.h"
#include "my_sokoban.h"

int losing3(soko_t *soko, int i, int j)
{
    if ((soko->map[i][j + 1] == '#' || soko->map[i][j + 1] == 'X') ||
    (soko->map[i][j - 1] == '#' || soko->map[i][j - 1] == 'X')) {
        if ((soko->map[i + 1][j] == '#' || soko->map[i + 1][j] == 'X') ||
        (soko->map[i - 1][j] == '#' || soko->map[i - 1][j] == 'X')) {
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

int losing2(soko_t *soko, int i)
{
    int j = 0;
    int end = 0;

    while (soko->map[i][j] != '\0') {
        if (soko->map[i][j] == 'X')
            end = losing3(soko, i, j);
        if (end != 0)
            return EXIT_FAILURE;
        j++;
    }
    return EXIT_SUCCESS;
}

int losing(soko_t *soko)
{
    int i = 0;

    while (soko->map[i] != NULL) {
        if (losing2(soko, i) == EXIT_FAILURE)
            return EXIT_FAILURE;
        i++;
    }
    return EXIT_SUCCESS;
}

int winning(soko_t *soko)
{
    int i = 0;

    while (i != soko->end) {
        if (soko->map[soko->i[i]][soko->j[i]] != 'X')
            return EXIT_FAILURE;
        i++;
    }
    return EXIT_SUCCESS;
}