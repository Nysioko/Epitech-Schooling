/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** menustart
*/

#include "my_defender.h"

void menustart_event(sfRenderWindow* window, bag_t *bag)
{
    sfRenderWindow_clear(window, sfBlack);
    drawmenustart(window, bag);
    sfRenderWindow_display(window);
    eventstart(window, bag);
    while (sfRenderWindow_pollEvent(window, &bag->event)) {
        if (bag->event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            bag->menu = -1;
        }
    }
}

void menustart(sfRenderWindow* window, bag_t *bag)
{
    sfMusic *menustart;
    sfTime time = sfClock_getElapsedTime(bag->clock.wait);
    sfVector2i mouse = {960, 540};

    menustart = sfMusic_createFromFile("./ressources/songs/themes/mt.ogg");
    sfMusic_play(menustart);
    sfMusic_setLoop(menustart, sfTrue);
    while (bag->menu == 0)
        menustart_event(window, bag);
    sfClock_restart(bag->clock.wait);
    time = sfClock_getElapsedTime(bag->clock.wait);
    while (time.microseconds <= 200000)
        time = sfClock_getElapsedTime(bag->clock.wait);
    sfMouse_setPositionRenderWindow(mouse, window);
    sfMusic_destroy(menustart);
    sfRenderWindow_clear(window, sfBlack);
}
