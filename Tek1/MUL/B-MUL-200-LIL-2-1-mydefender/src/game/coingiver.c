/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** coingiver
*/

#include "my_defender.h"

void iffer_bank(bag_t *bag)
{
    for (int twr = 0; twr < 12; twr++)
        if (bag->don.wayn[twr] == 1) {
            bag->money += 10;
            sfClock_restart(bag->clock.gainbank);
        }
}

void bank(bag_t *bag)
{
    sfTime bankclock = sfClock_getElapsedTime(bag->clock.gainbank);

    if (bankclock.microseconds >= 2000000)
        iffer_bank(bag);
}