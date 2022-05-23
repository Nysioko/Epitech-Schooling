/*
** EPITECH PROJECT, 2021
** Graphical Programming
** File description:
** main
*/

#include "rpg.h"

int manage_loading(rpg_t *rpg)
{
    int (*tablo[8]) (rpg_t *) = {c_two, c_three, c_four, c_five, c_six,
    c_seven, c_eight, c_nine};

    if ((*tablo[rpg->bol.load]) (rpg) == 84)
        return 84;
    rpg->bol.load++;
    if (rpg->bol.load == 8) {
        sfMusic_play(rpg->musics.menu);
        rpg->bol.menu = true;
        rpg->bol.loading = false;
    }
    return 0;
}

void get_elapsed_time(rpg_t *rpg)
{
    rpg->map.time = sfClock_getElapsedTime(rpg->map.clock);
    rpg->player.time = sfClock_getElapsedTime(rpg->player.clock);
    rpg->cynthia.time = sfClock_getElapsedTime(rpg->cynthia.clock);
}

int window_2(rpg_t *rpg)
{
    bool a = false;
    int b = 0;

    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            a = key_pressed(rpg);
        if (a)
            return destroy(rpg);
        if (rpg->bol.load < 8 && rpg->bol.loading)
            b = manage_loading(rpg);
        else if (!rpg->bol.loading) {
            manage_display(rpg);
            get_elapsed_time(rpg);
            sfRenderWindow_clear(rpg->window, sfBlack);
        }
        if (b == 84)
            return 84;
    }
    return destroy(rpg);
}

int main_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    rpg_t rpg = create_one(mode);

    if (rpg.window == NULL)
        return 84;
    sfRenderWindow_drawSprite(rpg.window, rpg.load.spr, NULL);
    sfRenderWindow_drawSprite(rpg.window, rpg.load.load_spr, NULL);
    sfRenderWindow_setFramerateLimit(rpg.window, 60);
    return window_2(&rpg);
}

int main(int ac, char **av)
{
    if (ac != 1) {
        my_printf("%s: bad arguments: %d given but 0 required\n",
        av[0], ac);
        return 84;
    }
    return main_window();
}