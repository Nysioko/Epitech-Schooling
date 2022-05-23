/*
** EPITECH PROJECT, 2020
** screensaver
** File description:
** animation for screen
*/

#include "my_defender.h"

void soundcreate(bag_t *bag)
{
    bag->sound.start =
    sfMusic_createFromFile("./ressources/songs/effects/start.wav");
    bag->sound.met =
    sfMusic_createFromFile("./ressources/songs/effects/met.ogg");
    bag->sound.pop =
    sfMusic_createFromFile("./ressources/songs/effects/pop.ogg");
}

void soundplay(bag_t *bag)
{
    if (bag->sound.popi == 1) {
        sfMusic_stop(bag->sound.pop);
        sfMusic_play(bag->sound.pop);
        bag->sound.popi = 0;
    }
    if (bag->sound.meti == 1) {
        sfMusic_stop(bag->sound.met);
        sfMusic_play(bag->sound.met);
        bag->sound.meti = 0;
    }
    if (bag->sound.starti == 1) {
        sfMusic_stop(bag->sound.start);
        sfMusic_play(bag->sound.start);
        bag->sound.starti = 0;
    }
}

void soundestroy(bag_t *bag)
{
    sfMusic_destroy(bag->sound.pop);
    sfMusic_destroy(bag->sound.met);
    sfMusic_destroy(bag->sound.start);
}