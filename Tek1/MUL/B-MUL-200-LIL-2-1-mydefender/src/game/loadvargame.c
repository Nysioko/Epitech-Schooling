/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** loadvar
*/

#include "my_defender.h"

void load_tower_aim(bag_t *bag)
{
    bag->tower.aim = malloc(sizeof(int) * 13);
    for (int i = 0; i < 12; i++)
        bag->tower.aim[i] = 0;
    bag->clock.gainbank = sfClock_create();
}

void load_var_spriteg_two(bag_t *bag)
{
    bag->vector.vectorgame.ptw[9].y = 910;
    bag->vector.vectorgame.ptw[10].x = 1700;
    bag->vector.vectorgame.ptw[10].y = 60;
    bag->vector.vectorgame.ptw[11].x = 1800;
    bag->vector.vectorgame.ptw[11].y = 400;
    bag->vector.vectorgame.ptw[12].x = -1;
    bag->vector.vectorgame.ptw[12].y = -1;
    bag->vector.vectorgame.scalemap.x = 2;
    bag->vector.vectorgame.scalemap.y = 1.9;
    bag->don.twronedon = 0;
    bag->don.twrtwodon = 0;
    bag->don.twrthreedon = 0;
    bag->don.twrfourdon = 0;
    bag->money = 150;
    bag->don.wayn = malloc(sizeof(int) * 13);
    for (int i = 0; i <= 12; i++)
        bag->don.wayn[i] = 0;
    load_ennemy(bag);
}

void load_var_spriteg(bag_t *bag)
{
    bag->vector.vectorgame.ptw[0].x = 35;
    bag->vector.vectorgame.ptw[0].y = 800;
    bag->vector.vectorgame.ptw[1].x = 35;
    bag->vector.vectorgame.ptw[1].y = 500;
    bag->vector.vectorgame.ptw[2].x = 375;
    bag->vector.vectorgame.ptw[2].y = 350;
    bag->vector.vectorgame.ptw[3].x = 725;
    bag->vector.vectorgame.ptw[3].y = 550;
    bag->vector.vectorgame.ptw[4].x = 725;
    bag->vector.vectorgame.ptw[4].y = 400;
    bag->vector.vectorgame.ptw[6].x = 1100;
    bag->vector.vectorgame.ptw[6].y = 350;
    bag->vector.vectorgame.ptw[5].x = 1300;
    bag->vector.vectorgame.ptw[5].y = 910;
    bag->vector.vectorgame.ptw[7].x = 1400;
    bag->vector.vectorgame.ptw[7].y = 600;
    bag->vector.vectorgame.ptw[8].x = 1450;
    bag->vector.vectorgame.ptw[8].y = 300;
    bag->vector.vectorgame.ptw[9].x = 1600;
    load_var_spriteg_two(bag);
}

int load_vargame(bag_t *bag)
{
    bag->vector.vectorgame.ptw = malloc(sizeof(sfVector2f) * 15);
    load_var_spriteg(bag);
    return (0);
}