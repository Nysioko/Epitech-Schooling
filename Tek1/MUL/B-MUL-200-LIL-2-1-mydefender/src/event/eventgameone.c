/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** eventgameone
*/

#include "my_defender.h"

int eventgameone_three(bag_t *bag, int i, int x, int y)
{
    if ((x >= bag->vector.vectorgame.ptw[i].x &&
    (x <= bag->vector.vectorgame.ptw[i].x + 64)) &&
    (y >= bag->vector.vectorgame.ptw[i].y &&
    (y <= bag->vector.vectorgame.ptw[i].y + 64) &&
    bag->event.mouseButton.button == sfMouseRight && bag->event.type ==
    sfEvtMouseButtonPressed)
    && bag->don.wayn[i] != 0) {
        bag->sound.meti = 1;
        bag->don.wayn[i] = 0;
        bag->money += 50;
        return (0);
    }
    return (0);
}

int eventgameone_two(bag_t *bag, int i, int x, int y)
{
    if ((x >= bag->vector.vectorgame.ptw[i].x &&
    (x <= bag->vector.vectorgame.ptw[i].x + 64)) &&
    (y >= bag->vector.vectorgame.ptw[i].y &&
    (y <= bag->vector.vectorgame.ptw[i].y + 64) &&
    bag->event.mouseButton.button == sfMouseLeft && bag->event.type ==
    sfEvtMouseButtonPressed)
    && bag->don.wayn[i] == 0) {
        bag->sound.meti = 1;
        placetower(bag, i);
        return (0);
    }
    return 0;
}

int eventgameone(sfRenderWindow* window, bag_t *bag)
{
    int x;
    int y;

    towerone(window, bag->vector.mouse, bag);
    towertwo(window, bag->vector.mouse, bag);
    towerthree(window, bag->vector.mouse, bag);
    towerfour(window, bag->vector.mouse, bag);
    soundplay(bag);
    bag->vector.mouse = sfMouse_getPositionRenderWindow(window);
    x = bag->vector.mouse.x;
    y = bag->vector.mouse.y;
    for (int i = 0; i < 12; i++) {
        eventgameone_three(bag, i, x, y);
        eventgameone_two(bag, i, x, y);
    }
    return (0);
}