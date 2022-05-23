/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** freecage_enemy
*/

#include "my_defender.h"

void freecage_game(bag_t *bag)
{
    for (int i = 0; i <= 4; i++)
        free(bag->enemy.posenemy[i]);
    free(bag->enemy.posenemy);
    for (int i = 0; i <= 4; i++)
        free(bag->vector.posenemy[i]);
    free(bag->vector.posenemy);
    for (int i = 0; i <= 4; i++)
        free(bag->enemy.death[i]);
    free(bag->enemy.death);
    free(bag->don.wayn);
    free(bag->vector.vectorgame.ptw);
}