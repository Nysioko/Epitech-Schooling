/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** eventgametwo
*/

#include "my_defender.h"

int towerfour(sfRenderWindow* window, sfVector2i mouse, bag_t *bag)
{
    bag->vector.mouse = sfMouse_getPositionRenderWindow(window);
    if ((mouse.x >= 172 && mouse.x <= 345) &&
    (mouse.y >= 172 && mouse.y <= 345) && bag->event.mouseButton.button ==
    sfMouseLeft && bag->event.type == sfEvtMouseButtonPressed &&
    (bag->don.twronedon != 1 && bag->don.twrtwodon != 1 &&
    bag->don.twrthreedon != 1 && bag->don.twrfourdon != 1) &&
    bag->money >= 400) {
        bag->money -= 400;
        bag->don.twrthreedon = 1;
        bag->sound.popi = 1;
        return (1);
    }
    return (0);
}

int towerthree(sfRenderWindow* window, sfVector2i mouse, bag_t *bag)
{
    bag->vector.mouse = sfMouse_getPositionRenderWindow(window);
    if ((mouse.x >= 0 && mouse.x <= 172) &&
    (mouse.y >= 172 && mouse.y <= 345) && bag->event.mouseButton.button ==
    sfMouseLeft && bag->event.type == sfEvtMouseButtonPressed &&
    (bag->don.twronedon != 1 && bag->don.twrtwodon != 1 &&
    bag->don.twrthreedon != 1 && bag->don.twrfourdon != 1) &&
    bag->money >= 500) {
        bag->money -= 500;
        bag->don.twrfourdon = 1;
        bag->sound.popi = 1;
        return (1);
    }
    return (0);
}

int towertwo(sfRenderWindow* window, sfVector2i mouse, bag_t *bag)
{
    bag->vector.mouse = sfMouse_getPositionRenderWindow(window);
    if ((mouse.x >= 172 && mouse.x <= 345) &&
    (mouse.y >= 0 && mouse.y <= 172) && bag->event.mouseButton.button ==
    sfMouseLeft && bag->event.type == sfEvtMouseButtonPressed &&
    (bag->don.twronedon != 1 && bag->don.twrtwodon != 1 &&
    bag->don.twrthreedon != 1 && bag->don.twrfourdon != 1) &&
    bag->money >= 100) {
        bag->money -= 100;
        bag->don.twrtwodon = 1;
        bag->sound.popi = 1;
        return (1);
    }
    return (0);
}

int towerone(sfRenderWindow* window, sfVector2i mouse, bag_t *bag)
{
    bag->vector.mouse = sfMouse_getPositionRenderWindow(window);
    if ((mouse.x >= 0 && mouse.x <= 172) &&
    (mouse.y >= 0 && mouse.y <= 172) && bag->event.mouseButton.button ==
    sfMouseLeft && bag->event.type == sfEvtMouseButtonPressed &&
    (bag->don.twronedon != 1 && bag->don.twrtwodon != 1 &&
    bag->don.twrthreedon != 1 && bag->don.twrfourdon != 1)
    && bag->money >= 250) {
        bag->don.twronedon = 1;
        bag->money -= 250;
        bag->sound.popi = 1;
        return (1);
    }
    return (0);
}