/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** drawmenustart
*/

#include "my_defender.h"

void placebtnstart(bag_t *bag)
{
    sfSprite_setPosition(bag->sprite.play, bag->vector.pos1);
    sfSprite_setPosition(bag->sprite.ctrl, bag->vector.pos2);
    sfSprite_setPosition(bag->sprite.exit, bag->vector.pos3);

}

void scalestart(bag_t *bag)
{
    sfSprite_setScale(bag->sprite.bcg, bag->vector.scalebcg);
    sfSprite_setScale(bag->sprite.play, bag->vector.scalebtn);
    sfSprite_setScale(bag->sprite.ctrl, bag->vector.scalebtn);
    sfSprite_setScale(bag->sprite.exit, bag->vector.scalebtn);
}

void drawmenustart(sfRenderWindow* window, bag_t *bag)
{
    scalestart(bag);
    placebtnstart(bag);
    sfRenderWindow_drawSprite(window, bag->sprite.bcg, NULL);
    sfRenderWindow_drawSprite(window, bag->sprite.play, NULL);
    sfRenderWindow_drawSprite(window, bag->sprite.ctrl, NULL);
    sfRenderWindow_drawSprite(window, bag->sprite.exit, NULL);
}