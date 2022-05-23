/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** mouce
*/

#include "my_defender.h"

/*void generate_cursor(sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sprite_cursor(window, pos);
}*/

void sprite_cursor(bag_t *bag, sfRenderWindow *window)
{
    bag->vector.mouse = sfMouse_getPositionRenderWindow(window);
    bag->vector.mousef.x = bag->vector.mouse.x;
    bag->vector.mousef.y = bag->vector.mouse.y;

    if (bag->don.twronedon == 1 && bag->menu == 4) {
        sfSprite_setPosition(bag->sprite.twr[1][0], bag->vector.mousef);
        sfRenderWindow_drawSprite(window, bag->sprite.twr[1][0], NULL);
    }
    if (bag->don.twrtwodon == 1 && bag->menu == 4) {
        sfSprite_setPosition(bag->sprite.twr[2][0], bag->vector.mousef);
        sfRenderWindow_drawSprite(window, bag->sprite.twr[2][0], NULL);
    }
    if (bag->don.twrthreedon == 1 && bag->menu == 4) {
        sfSprite_setPosition(bag->sprite.twr[3][0], bag->vector.mousef);
        sfRenderWindow_drawSprite(window, bag->sprite.twr[3][0], NULL);
    }
    if (bag->don.twrfourdon == 1 && bag->menu == 4) {
        sfSprite_setPosition(bag->sprite.twr[4][0], bag->vector.mousef);
        sfRenderWindow_drawSprite(window, bag->sprite.twr[4][0], NULL);
    }
}