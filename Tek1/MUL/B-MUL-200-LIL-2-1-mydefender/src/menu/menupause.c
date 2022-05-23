/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** menupause
*/

#include "my_defender.h"

void menupause_event(sfRenderWindow* window, bag_t *bag)
{
    while (sfRenderWindow_pollEvent(window, &bag->event)) {
        if (bag->event.type == sfEvtClosed)
            bag->menu = -1;
        if (bag->event.key.code == sfKeyEscape && bag->event.type ==
        sfEvtKeyPressed)
            bag->menu = 4;
    }

}

void menupause(sfRenderWindow* window, bag_t *bag)
{
    sfTime time = sfClock_getElapsedTime(bag->clock.wait);
    sfVector2i mouse = {960, 540};

    while (bag->menu == 2) {
        menupause_event(window, bag);
        sfRenderWindow_clear(window, sfBlack);
        drawmenupause(window, bag);
        sfRenderWindow_display(window);
        eventpause(window, bag);
    }
    sfClock_restart(bag->clock.wait);
    time = sfClock_getElapsedTime(bag->clock.wait);
    while (time.microseconds <= 100000) {
        time = sfClock_getElapsedTime(bag->clock.wait);
    }
    sfMouse_setPositionRenderWindow(mouse, window);
}