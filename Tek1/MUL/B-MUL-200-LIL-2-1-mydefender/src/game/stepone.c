/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** stepone
*/

#include "my_defender.h"

void stepone_iffer4(bag_t *bag, int i)
{
    if (bag->vector.posenemy[1][i].y >= 680 &&
    bag->vector.posenemy[1][i].y <= 875 &&
    bag->vector.posenemy[1][i].x <= 1700 &&
    bag->vector.posenemy[1][i].x > 1060) {
        bag->vector.posenemy[1][i].x += rand() % 5;
        if (bag->vector.posenemy[1][i].y <= 845)
            bag->vector.posenemy[1][i].y += rand() % 2;
        sfSprite_setPosition(bag->sprite.enemy[1][i],
        bag->vector.posenemy[1][i]);
    }
    if (bag->vector.posenemy[1][i].y > 200 &&
    bag->vector.posenemy[1][i].x < 1710 &&
    bag->vector.posenemy[1][i].x >= 1475) {
        bag->vector.posenemy[1][i].y -= rand() % 5;
        sfSprite_setPosition(bag->sprite.enemy[1][i],
        bag->vector.posenemy[1][i]);
    }
}

void stepone_iffer3(bag_t *bag, int i)
{
    if (bag->vector.posenemy[1][i].y >= 420 &&
    bag->vector.posenemy[1][i].y <= 800 &&
    bag->vector.posenemy[1][i].x <= 1275 &&
    bag->vector.posenemy[1][i].x > 775) {
        bag->vector.posenemy[1][i].x += rand() % 5;
        sfSprite_setPosition(bag->sprite.enemy[1][i],
        bag->vector.posenemy[1][i]);
    }
    if (bag->vector.posenemy[1][i].y < 845 &&
    bag->vector.posenemy[1][i].x < 1275 &&
    bag->vector.posenemy[1][i].x >= 1075) {
        bag->vector.posenemy[1][i].y += rand() % 5;
        sfSprite_setPosition(bag->sprite.enemy[1][i],
        bag->vector.posenemy[1][i]);
    }
    stepone_iffer4(bag, i);
}

void stepone_iffer2(bag_t *bag, int i)
{
    if (bag->vector.posenemy[1][i].y >= 120 &&
    bag->vector.posenemy[1][i].y <= 350 &&
    bag->vector.posenemy[1][i].x <= 1000 &&
    bag->vector.posenemy[1][i].x > 550) {
        bag->vector.posenemy[1][i].x += rand() % 5;
        sfSprite_setPosition(bag->sprite.enemy[1][i],
        bag->vector.posenemy[1][i]);
    }
    if (bag->vector.posenemy[1][i].y < 600 &&
    bag->vector.posenemy[1][i].x < 1100 &&
    bag->vector.posenemy[1][i].x >= 800) {
        bag->vector.posenemy[1][i].y += rand() % 5;
        sfSprite_setPosition(bag->sprite.enemy[1][i],
        bag->vector.posenemy[1][i]);
    }
    stepone_iffer3(bag, i);
}

void stepone_iffer(bag_t *bag, int i)
{
    if (bag->vector.posenemy[1][i].y > 420 &&
    bag->vector.posenemy[1][i].x < 340) {
        bag->vector.posenemy[1][i].y -= rand() % 5;
        sfSprite_setPosition(bag->sprite.enemy[1][i],
        bag->vector.posenemy[1][i]);
    }
    if (bag->vector.posenemy[1][i].y < 600 &&
    bag->vector.posenemy[1][i].x < 600) {
        bag->vector.posenemy[1][i].x += rand() % 5;
        sfSprite_setPosition(bag->sprite.enemy[1][i],
        bag->vector.posenemy[1][i]);
    }
    if (bag->vector.posenemy[1][i].y > 125 &&
    bag->vector.posenemy[1][i].x <= 700 &&
    bag->vector.posenemy[1][i].x > 425) {
        bag->vector.posenemy[1][i].y -= rand() % 5;
        sfSprite_setPosition(bag->sprite.enemy[1][i],
        bag->vector.posenemy[1][i]);
    }
    stepone_iffer2(bag, i);
}

void stepone(sfRenderWindow* window, bag_t *bag)
{
    sfTime time = sfClock_getElapsedTime(bag->clock.mvmt);

    if (time.microseconds <= 500)
        return;
    sfClock_restart(bag->clock.mvmt);
    for (int i = 0; i < 40; i++) {
        if (verif_step(bag, 1) == -1) {
            bag->enemy.step = 2;
            return;
        }
        stepone_iffer(bag, i);
        if (bag->enemy.pv[1][i] <= 0 || bag->enemy.death[1][i] == 1) {
            bag->vector.posenemy[1][i].x = 1931;
            sfSprite_setPosition(bag->sprite.enemy[1][i],
            bag->vector.posenemy[1][i]);
        }
        sfRenderWindow_drawSprite(window, bag->sprite.enemy[1][i], NULL);
    }
}