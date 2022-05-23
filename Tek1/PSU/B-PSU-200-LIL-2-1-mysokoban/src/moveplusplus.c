/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban
** File description:
** moveplusplus
*/

#include "my_sokoban.h"
#include "my.h"

int is_it_moveable(soko_t *soko, int i, int j)
{
    if (i == 0) {
        if ((soko->px + j == 0 && j == -1) ||
        soko->map[soko->py][soko->px + j * 2] == '#' ||
        soko->map[soko->py][soko->px + j * 2] == '\0')
            return EXIT_FAILURE;
        else if (soko->map[soko->py][soko->px + j * 2] == 'X')
            return EXIT_FAILURE;
    } else {
        if ((soko->py + i == 0 && i == -1)
        || soko->map[soko->py + i * 2] == NULL
        || soko->map[soko->py + i * 2][soko->px] == '#'
        || soko->map[soko->py + i * 2][soko->px] == '\0')
            return EXIT_FAILURE;
        else if (soko->map[soko->py + i * 2][soko->px] == 'X')
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int move_checker(soko_t *soko, int i, int j)
{
    if (i == 0) {
        if ((soko->px == 0 && j == -1) || soko->map[soko->py][soko->px + j]
        == '#' || soko->map[soko->py][soko->px + j] == '\0')
            return EXIT_FAILURE;
        else if (soko->map[soko->py][soko->px + j] == 'X')
            return is_it_moveable(soko, i, j);
    } else {
        if ((soko->py == 0 && i == -1)
        || soko->map[soko->py + i] == NULL
        || soko->map[soko->py + i][soko->px] == '#'
        || soko->map[soko->py + i][soko->px] == '\0')
            return EXIT_FAILURE;
        else if (soko->map[soko->py + i][soko->px] == 'X')
            return is_it_moveable(soko, i, j);
    }
    return EXIT_SUCCESS;
}

void move_player(soko_t *soko, int i, int j)
{
    soko->map[soko->py][soko->px] = ' ';
    if (soko->map[soko->py + i][soko->px + j] == 'X')
        soko->map[soko->py + i * 2][soko->px + j * 2] = 'X';
    soko->map[soko->py + i][soko->px + j] = 'P';
}