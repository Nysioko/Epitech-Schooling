/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** main
*/

#include "my_defender.h"

int second(sfRenderWindow* window, bag_t *bag)
{
    if (bag->menu == 0)
        menustart(window, bag);
    if (bag->menu == 1)
        menuhelp(window, bag);
    if (bag->menu == 2)
        menupause(window, bag);
    if (bag->menu == 3)
        menuend(window, bag, 1);
    if (bag->menu == 6) {
        bag->menu = 3;
        menuend(window, bag, 2);
    }
    if (bag->menu == 4)
        playgame(window, bag);
    if (bag->menu == 5) {
        load_vargame(bag);
        bag->menu = 0;
    }
    return (0);
}

void initial2(bag_t *bag, sfRenderWindow* window)
{
    spritedestroy(bag);
    texturedestroy(bag);
    freecage_game(bag);
    sfRenderWindow_destroy(window);
    soundestroy(bag);
}

int initial(bag_t *bag)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;

    if (load_var(bag) == 84 || initexture(bag) == 84 || initsprite(bag) == 84)
        return (84);
    bag->menu = 5;
    window = sfRenderWindow_create(mode, "My_defender", sfResize | sfClose,
    NULL);
    if (!window)
        return (84);
    sfRenderWindow_setFramerateLimit(window, 30);
    soundcreate(bag);
    while (sfRenderWindow_isOpen(window) && bag->menu != -1) {
        second(window, bag);
    }
    initial2(bag, window);
    return (0);
}

int main(void)
{
    bag_t bag;

    return (initial(&bag));
}