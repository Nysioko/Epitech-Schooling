/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** draw
*/

#include "my_defender.h"

void potionforrequire(sfRenderWindow* window, bag_t *bag)
{
    sfTime time = sfClock_getElapsedTime(bag->clock.potion);

    if (time.microseconds >= 50000) {
        bag->vector.potion.width = 100;
        bag->vector.potion.height = 118;
        bag->vector.potion.top = 0;
        if (bag->vector.potion.left >= 500)
            bag->vector.potion.left = 0;
        else
            bag->vector.potion.left += 100;
        sfSprite_setTextureRect(bag->sprite.potion, bag->vector.potion);
        sfClock_restart(bag->clock.potion);
    }
    sfRenderWindow_drawSprite(window, bag->sprite.potion, NULL);
}

void placeobjgame(bag_t *bag)
{
    for (int i = 0; i < 12; i++)
        sfSprite_setPosition(bag->sprite.sqg[i], bag->vector.vectorgame.ptw[i]);
    sfSprite_setPosition(bag->sprite.potion, (sfVector2f){750, 750});
}

void scaleobjgame(bag_t *bag)
{
    sfSprite_setScale(bag->sprite.map, bag->vector.vectorgame.scalemap);
}

void drawgame_iffer(sfRenderWindow* window, bag_t *bag)
{
    if (bag->enemy.pvcastle <= 10000 && bag->enemy.pvcastle > 5000)
        sfRenderWindow_drawSprite(window, bag->sprite.castle[0], NULL);
    if (bag->enemy.pvcastle <= 5000 && bag->enemy.pvcastle > 1000)
        sfRenderWindow_drawSprite(window, bag->sprite.castle[1], NULL);
    if (bag->enemy.pvcastle <= 1000 && bag->enemy.pvcastle > 0)
        sfRenderWindow_drawSprite(window, bag->sprite.castle[2], NULL);
}

void drawgame(sfRenderWindow* window, bag_t *bag)
{
    placeobjgame(bag);
    scaleobjgame(bag);
    sfRenderWindow_drawSprite(window, bag->sprite.map, NULL);
    drawgame_iffer(window, bag);
    for (int k = 0; k < 12; k++)
        sfRenderWindow_drawSprite(window, bag->sprite.sqg[k], NULL);
    sfRenderWindow_drawSprite(window, bag->sprite.towerchose, NULL);
    for (int i = 0; i <= 11; i++) {
        if (bag->don.wayn[i] != 0) {
            sfSprite_setPosition(bag->sprite.twr[bag->don.wayn[i]][i],
            bag->vector.vectorgame.ptw[i]);
            sfRenderWindow_drawSprite(window,
            bag->sprite.twr[bag->don.wayn[i]][i], NULL);
        }
    }
    textstep(window, bag);
    textmoney(window, bag);
    potionforrequire(window, bag);
}