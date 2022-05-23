/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** menuend
*/

#include "my_defender.h"

void menuend_event(sfRenderWindow* window, bag_t *bag)
{
    while (sfRenderWindow_pollEvent(window, &bag->event)) {
        if (bag->event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            bag->menu = -1;
        }
    }
}

void menuend(sfRenderWindow* window, bag_t *bag, int i)
{
    sfClock *end = sfClock_create();
    sfTime time = sfClock_getElapsedTime(end);

    while (bag->menu == 3 && time.microseconds < 5000000) {
        menuend_event(window, bag);
        textend(window, bag, i);
        time = sfClock_getElapsedTime(end);
    }
    bag->menu = 5;
}