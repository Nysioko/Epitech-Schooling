/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** menuhelp
*/

#include "my_defender.h"

void menuhelp_event(sfRenderWindow* window, bag_t *bag)
{
    eventhelp(window, bag);
    sfRenderWindow_clear(window, sfBlack);
    drawmenuhelp(window, bag);
    sfRenderWindow_display(window);
    while (sfRenderWindow_pollEvent(window, &bag->event)) {
        if (bag->event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            bag->menu = -1;
        }
    }
}

void menuhelp(sfRenderWindow* window, bag_t *bag)
{
    sfMusic *menuhelp;
    sfTime time = sfClock_getElapsedTime(bag->clock.wait);
    sfVector2i mouse = {960, 540};

    menuhelp = sfMusic_createFromFile("./ressources/songs/themes/help.ogg");
    sfMusic_play(menuhelp);
    sfMusic_setLoop(menuhelp, sfTrue);
    while (bag->menu == 1)
        menuhelp_event(window, bag);
    sfClock_restart(bag->clock.wait);
    time = sfClock_getElapsedTime(bag->clock.wait);
    while (time.microseconds <= 100000)
        time = sfClock_getElapsedTime(bag->clock.wait);
    sfMouse_setPositionRenderWindow(mouse, window);
    sfMusic_destroy(menuhelp);
    sfRenderWindow_clear(window, sfBlack);
}