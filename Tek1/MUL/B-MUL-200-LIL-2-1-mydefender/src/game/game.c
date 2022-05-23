/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** game
*/

#include "my_defender.h"

void play_game_two(sfRenderWindow* window, bag_t *bag)
{
    sfRenderWindow_clear(window, sfBlack);
    drawgame(window, bag);
    sprite_cursor(bag, window);
    bank(bag);
    enemy(window, bag);
    sfRenderWindow_display(window);
    eventgameone(window, bag);
    while (sfRenderWindow_pollEvent(window, &bag->event)) {
        if (bag->event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            bag->menu = -1;
        }
        if (bag->event.key.code == sfKeyEscape && bag->event.type ==
        sfEvtKeyPressed)
            bag->menu = 2;
    }
}

void playgame(sfRenderWindow* window, bag_t *bag)
{
    sfMusic *game;
    sfTime time = sfClock_getElapsedTime(bag->clock.wait);

    game = sfMusic_createFromFile("./ressources/songs/themes/game.ogg");
    sfMusic_play(game);
    sfMusic_setLoop(game, sfTrue);
    while (bag->menu == 4) {
        time = sfClock_getElapsedTime(bag->clock.gain);
        if (time.microseconds >= 900000) {
            bag->money += 10;
            sfClock_restart(bag->clock.gain);
        }
        play_game_two(window, bag);
    }
    sfMusic_destroy(game);
    sfRenderWindow_clear(window, sfBlack);
}