/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** eventhelp
*/

#include "my_defender.h"

void eventhelp(sfRenderWindow* window, bag_t *bag)
{
    bag->vector.mouse = sfMouse_getPositionRenderWindow(window);
    if ((bag->vector.mouse.x >= 100 && bag->vector.mouse.x <= 400) &&
        (bag->vector.mouse.y >= 100 && bag->vector.mouse.y <= 200) &&
        bag->event.mouseButton.button == sfMouseLeft && bag->event.type ==
        sfEvtMouseButtonPressed)
        bag->menu = 0;
}