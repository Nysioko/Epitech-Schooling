/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** ennemy
*/

#include "my_defender.h"

void setpv(bag_t *bag)
{
    int pv = 2500;

    bag->enemy.pv = malloc(sizeof(int *) * 7);
    for (int i = 0; i <= 4; i++) {
        bag->enemy.pv[i] = malloc(sizeof(int) * 41);
        for (int j = 0; j <= 40; j++)
            bag->enemy.pv[i][j] = pv;
        pv += 2500;
    }
    bag->tower.aim = malloc(sizeof(int) * 13);
    for (int i = 0; i < 12; i++)
        bag->tower.aim[i] = -1;
    bag->enemy.pvcastle = 10000;
}

void enemy_setorigin(bag_t *bag)
{
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 40; j++) {
            sfSprite_setPosition(bag->sprite.enemy[i][j],
            bag->vector.posenemy[i][j]);
        }
    }
    bag->enemy.death = malloc(sizeof(int *) * 7);
    for (int i = 0; i <= 4; i++) {
        bag->enemy.death[i] = malloc(sizeof(int) * 41);
        for (int j = 0; j <= 40; j++)
            bag->enemy.death[i][j] = 0;
    }
    setpv(bag);
    bag->enemy.step = 1;
}

void load_ennemy(bag_t *bag)
{
    bag->enemy.posenemy = malloc(sizeof(int *) * 5);
    for (int i = 0; i <= 4; i++) {
        bag->enemy.posenemy[i] = malloc(sizeof(int) * 41);
        for (int j = 0; j <= 40; j++)
            bag->enemy.posenemy[i][j] = 125 + (rand() % 200);
    }
    bag->vector.posenemy = malloc(sizeof(sfVector2f *) * 5);
    for (int i = 0; i <= 4; i++) {
        bag->vector.posenemy[i] = malloc(sizeof(sfVector2f) * 41);
        for (int j = 0; j <= 40; j++) {
            bag->vector.posenemy[i][j].x = bag->enemy.posenemy[i][j];
            bag->vector.posenemy[i][j].y = 1100 + (rand() % 600);
        }
    }
    enemy_setorigin(bag);
}