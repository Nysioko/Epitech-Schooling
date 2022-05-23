/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** loadvar
*/

#include "my_defender.h"

void load_clock(bag_t *bag)
{
    bag->clock.wait = sfClock_create();
    bag->clock.gainbank = sfClock_create();
    bag->clock.gain = sfClock_create();
    bag->clock.aim = sfClock_create();
    bag->clock.castle = sfClock_create();
    bag->clock.potion = sfClock_create();
}

int load_text(bag_t *bag)
{
    bag->text.money = sfText_create();
    bag->text.step = sfText_create();
    bag->text.font = sfFont_createFromFile("./ressources/font/font.otf");
    if (bag->text.font == NULL)
        return (84);
    return (0);
}

void load_var_sprite(bag_t *bag)
{
    bag->vector.pos1.x = 100;
    bag->vector.pos1.y = 100;
    bag->vector.pos2.x = 100;
    bag->vector.pos2.y = 450;
    bag->vector.pos3.x = 100;
    bag->vector.pos3.y = 800;
    bag->vector.helptext.x = 300;
    bag->vector.helptext.y = 500;
    bag->vector.scalebcg.x = 2.2;
    bag->vector.scalebcg.y = 2.2;
    bag->vector.scalebtn.x = 0.5;
    bag->vector.scalebtn.y = 0.5;
    bag->sound.popi = 0;
    bag->sound.meti = 0;
    bag->sound.starti = 0;
}

int load_var(bag_t *bag)
{
    if (load_text(bag) == 84)
        return (84);
    load_var_sprite(bag);
    load_clock(bag);
    return (0);
}