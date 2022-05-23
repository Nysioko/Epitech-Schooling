/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban
** File description:
** move
*/

#include "../include/my.h"
#include "../include/my_sokoban.h"

int check_cooplay(soko_t *soko)
{
    int i = 0;
    int j = 0;

    while (soko->map[i] != NULL) {
        j = 0;
        while (soko->map[i][j] != '\0') {
            soko->map[i][j] == 'P' ? soko->py = i : soko->map[i][j];
            soko->map[i][j] == 'P' ? soko->px = j : soko->map[i][j];
            j++;
        }
        i++;
    }
    return EXIT_SUCCESS;
}

void to_up(soko_t *soko)
{
    check_cooplay(soko);
    if (move_checker(soko, -1, 0) == EXIT_SUCCESS)
        move_player(soko, -1, 0);
}

void to_down(soko_t *soko)
{
    check_cooplay(soko);
    if (move_checker(soko, 1, 0) == EXIT_SUCCESS)
        move_player(soko, 1, 0);
}

void to_left(soko_t *soko)
{
    check_cooplay(soko);
    if (move_checker(soko, 0, -1) == EXIT_SUCCESS)
        move_player(soko, 0, -1);
}

void to_right(soko_t *soko)
{
    check_cooplay(soko);
    if (move_checker(soko, 0, 1) == EXIT_SUCCESS)
        move_player(soko, 0, 1);
}