/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** enemy
*/

#include "my_defender.h"

void castle_state_two(bag_t *bag, int i)
{
    for (int j = 0; j < 40; j++) {
        if (bag->vector.posenemy[i][j].y < 450 &&
        bag->vector.posenemy[i][j].x >= 1610 &&
        bag->vector.posenemy[i][j].x < 1920)
            bag->enemy.pvcastle -= 2;
    }
    sfClock_restart(bag->clock.castle);
}

void castle_state(bag_t *bag, int i)
{
    sfTime time = sfClock_getElapsedTime(bag->clock.castle);

    if (time.microseconds >= 5000)
        castle_state_two(bag, i);
    if (bag->enemy.pvcastle <= 0)
        bag->menu = 6;
}

int verif_step(bag_t *bag, int i)
{
    tower_shot(bag);
    castle_state(bag, i);
    for (int j = 0; j < 40; j++) {
        if (bag->enemy.pv[i][j] <= 0 || bag->enemy.death[i][j] == 1) {
            bag->enemy.death[i][j] = 1;
            bag->vector.posenemy[i][j].x = 1931;
        }
        if (bag->vector.posenemy[i][j].x < 1925)
            return (0);
    }
    return (-1);
}

void enemy(sfRenderWindow* window, bag_t *bag)
{
    if (bag->enemy.step == 1)
        stepone(window, bag);
    if (bag->enemy.step == 2)
        steptwo(window, bag);
    if (bag->enemy.step == 3)
        stepthree(window, bag);
    if (bag->enemy.step == 4)
        stepfour(window, bag);
}