/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** drawmenuhelp
*/

#include "my_defender.h"

void placebtnhelp(bag_t *bag)
{
    sfSprite_setPosition(bag->sprite.back, (sfVector2f){100, 100});
}

void scalehelp(bag_t *bag)
{
    sfSprite_setScale(bag->sprite.back, bag->vector.scalebtn);
}

void drawmenuhelp(sfRenderWindow* window, bag_t *bag)
{
    scalehelp(bag);
    placebtnhelp(bag);
    sfRenderWindow_drawSprite(window, bag->sprite.bcghelp, NULL);
    sfRenderWindow_drawSprite(window, bag->sprite.back, NULL);
}