/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** sprite
*/

#include "my_defender.h"

int verifsprite(bag_t *bag)
{
    if (!bag->sprite.play)
        return (84);
    return (0);
}

int sqg(bag_t *bag)
{
    bag->sprite.sqg = malloc(sizeof(sfSprite *) * 13);
    if (bag->sprite.sqg == NULL)
        return (84);
    for (int i = 0; i != 12; i++)
        bag->sprite.sqg[i] = sfSprite_create();
    for (int i = 0; i <= 4; i++)
        sfSprite_setTexture(bag->sprite.sqg[i], bag->texture.sqg, sfTrue);
    sfSprite_setTexture(bag->sprite.sqg[5], bag->texture.sqgsable, sfTrue);
    sfSprite_setTexture(bag->sprite.sqg[6], bag->texture.sqg, sfTrue);
    sfSprite_setTexture(bag->sprite.sqg[7], bag->texture.sqgsable, sfTrue);
    sfSprite_setTexture(bag->sprite.sqg[8], bag->texture.sqgsable, sfTrue);
    sfSprite_setTexture(bag->sprite.sqg[9], bag->texture.sqgsable, sfTrue);
    sfSprite_setTexture(bag->sprite.sqg[10], bag->texture.sqgsable, sfTrue);
    sfSprite_setTexture(bag->sprite.sqg[11], bag->texture.sqgsable, sfTrue);
    return (0);
}

int initsprite_two(bag_t *bag)
{
    bag->clock.mvmt = sfClock_create();
    bag->sprite.twr = malloc(sizeof(sfSprite **) * 5);
    if (bag->sprite.twr == NULL)
        return (84);
    for (int j = 0; j <= 4; j++) {
        bag->sprite.twr[j] = malloc(sizeof(sfSprite *) * 14);
        if (bag->sprite.twr[j] == NULL)
            return (84);
        for (int i = 0; i <= 12; i++) {
            bag->sprite.twr[j][i] = sfSprite_create();
        }
    }
    initsprite_twobelike(bag);
    return 0;
}

void initsprite2(bag_t *bag)
{
    bag->sprite.bcg = sfSprite_create();
    bag->sprite.bcghelp = sfSprite_create();
    bag->sprite.map = sfSprite_create();
    bag->sprite.play = sfSprite_create();
    bag->sprite.back = sfSprite_create();
    bag->sprite.next = sfSprite_create();
    bag->sprite.ctrl = sfSprite_create();
    bag->sprite.exit = sfSprite_create();
    init1(bag);
    initcastle(bag);
}

int initsprite(bag_t *bag)
{
    initsprite2(bag);
    bag->sprite.menu = sfSprite_create();
    bag->sprite.re = sfSprite_create();
    bag->sprite.ng = sfSprite_create();
    bag->sprite.towerchose = sfSprite_create();
    sqg(bag);
    bag->sprite.sqgc = sfSprite_create();
    bag->sprite.sqgo = sfSprite_create();
    bag->sprite.sqgx = sfSprite_create();
    bag->sprite.potion = sfSprite_create();
    initsprite_two(bag);
    if (verifsprite(bag) == 84)
        return (84);
    setextsprite(bag);
    return (0);
}
