/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** tower_shot
*/

#include "my_defender.h"

void tower_shot_two(bag_t *bag, int twr)
{
    if (bag->don.wayn[twr] == 2)
        for (int j = 0; j < 40; j++)
            tower_one_shot_one(bag, twr, j);
    if (bag->don.wayn[twr] == 3)
        for (int j = 0; j < 40; j++)
            tower_two_shot_one(bag, twr, j);
}

void tower_shot(bag_t *bag)
{
    sfTime time = sfClock_getElapsedTime(bag->clock.aim);

    if (time.microseconds >= 10000) {
        for (int twr = 0; twr < 12; twr++)
            tower_shot_two(bag, twr);
        sfClock_restart(bag->clock.aim);
    }
}