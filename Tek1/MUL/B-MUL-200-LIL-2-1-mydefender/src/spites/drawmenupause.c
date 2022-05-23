/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** drawmenupause
*/

#include "my_defender.h"

void placebtnpause(bag_t *bag)
{
    sfSprite_setPosition(bag->sprite.re, bag->vector.pos1);
    sfSprite_setPosition(bag->sprite.ng, bag->vector.pos2);
    sfSprite_setPosition(bag->sprite.exit, bag->vector.pos3);

}

void scalepause(bag_t *bag)
{
    sfSprite_setScale(bag->sprite.bcg, bag->vector.scalebcg);
    sfSprite_setScale(bag->sprite.re, bag->vector.scalebtn);
    sfSprite_setScale(bag->sprite.ng, bag->vector.scalebtn);
    sfSprite_setScale(bag->sprite.exit, bag->vector.scalebtn);
}

void drawmenupause(sfRenderWindow* window, bag_t *bag)
{
    drawgame(window, bag);
    scalepause(bag);
    placebtnpause(bag);
    sfRenderWindow_drawSprite(window, bag->sprite.re, NULL);
    sfRenderWindow_drawSprite(window, bag->sprite.ng, NULL);
    sfRenderWindow_drawSprite(window, bag->sprite.exit, NULL);
}