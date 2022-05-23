/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** eventpause
*/

#include "my_defender.h"

void iffer_eventpause(bag_t *bag)
{
    if ((bag->vector.mouse.x >= 100 && bag->vector.mouse.x <= 400) &&
        (bag->vector.mouse.y >= 800 && bag->vector.mouse.y <= 900) &&
        bag->event.mouseButton.button == sfMouseLeft && bag->event.type ==
        sfEvtMouseButtonPressed) {
        bag->menu = -1;
        bag->sound.popi = 1;
        }
}

void eventpause(sfRenderWindow* window, bag_t *bag)
{
    bag->vector.mouse = sfMouse_getPositionRenderWindow(window);
    if ((bag->vector.mouse.x >= 100 && bag->vector.mouse.x <= 400) &&
        (bag->vector.mouse.y >= 100 && bag->vector.mouse.y <= 200) &&
        bag->event.mouseButton.button == sfMouseLeft && bag->event.type ==
        sfEvtMouseButtonPressed) {
        bag->menu = 4;
        bag->sound.starti = 1;
        }
    if ((bag->vector.mouse.x >= 100 && bag->vector.mouse.x <= 400) &&
        (bag->vector.mouse.y >= 450 && bag->vector.mouse.y <= 550) &&
        bag->event.mouseButton.button == sfMouseLeft && bag->event.type ==
        sfEvtMouseButtonPressed) {
        bag->menu = 5;
        bag->sound.popi = 1;
        }
    iffer_eventpause(bag);
    soundplay(bag);
}