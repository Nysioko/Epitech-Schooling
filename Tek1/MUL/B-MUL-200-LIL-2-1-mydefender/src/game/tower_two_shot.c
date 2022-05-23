/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** tower_shot
*/

#include "my_defender.h"

void tower_two_shot_two(bag_t *bag, int twr)
{
    if (bag->don.wayn[twr] != 0 &&
    ((bag->vector.posenemy[bag->enemy.step][bag->tower.aim[twr]].x >=
    (bag->vector.vectorgame.ptw[twr].x - 250)
    && bag->vector.posenemy[bag->enemy.step][bag->tower.aim[twr]].x <=
    (bag->vector.vectorgame.ptw[twr].x + 250)) &&
    (bag->vector.posenemy[bag->enemy.step][bag->tower.aim[twr]].y >=
    (bag->vector.vectorgame.ptw[twr].y - 250)
    && bag->vector.posenemy[bag->enemy.step][bag->tower.aim[twr]].y <=
    (bag->vector.vectorgame.ptw[twr].y + 250)))) {
        bag->enemy.pv[bag->enemy.step][bag->tower.aim[twr]] -= 10;
        if (bag->enemy.pv[bag->enemy.step][bag->tower.aim[twr]] <= 0)
            bag->enemy.death[bag->enemy.step][bag->tower.aim[twr]] = 1;
    }
}

void tower_two_shot_one(bag_t *bag, int twr, int j)
{
    if (bag->don.wayn[twr] != 0 &&
    ((bag->vector.posenemy[bag->enemy.step][j].x >=
    (bag->vector.vectorgame.ptw[twr].x - 250)
    && bag->vector.posenemy[bag->enemy.step][j].x <=
    (bag->vector.vectorgame.ptw[twr].x + 250)) &&
    (bag->vector.posenemy[bag->enemy.step][j].y >=
    (bag->vector.vectorgame.ptw[twr].y - 250)
    && bag->vector.posenemy[bag->enemy.step][j].y <=
    (bag->vector.vectorgame.ptw[twr].y + 250)))) {
        bag->tower.aim[twr] = j;
    }
    tower_two_shot_two(bag, twr);
}