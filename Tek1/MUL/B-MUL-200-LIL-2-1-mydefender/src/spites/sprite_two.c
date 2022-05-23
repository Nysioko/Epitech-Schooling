/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** sprite_two
*/

#include "my_defender.h"

void setexsprite_two(bag_t *bag)
{
    for (int j = 1; j <= 4 ; j++) {
        for (int i = 0; i < 12; i++) {
            sfSprite_setTexture(bag->sprite.twr[j][i],
            bag->texture.twr[j], sfTrue);
        }
    }
    for (int j = 1; j <= 4 ; j++) {
        for (int i = 0; i < 40; i++) {
            sfSprite_setTexture(bag->sprite.enemy[j][i],
            bag->texture.enemy[j], sfTrue);
        }
    }
}

void setextsprite(bag_t *bag)
{
    sfSprite_setTexture(bag->sprite.bcg, bag->texture.bcg, sfTrue);
    sfSprite_setTexture(bag->sprite.bcghelp, bag->texture.bcghelp, sfTrue);
    sfSprite_setTexture(bag->sprite.map, bag->texture.map, sfTrue);
    sfSprite_setTexture(bag->sprite.play, bag->texture.play, sfTrue);
    sfSprite_setTexture(bag->sprite.back, bag->texture.back, sfTrue);
    sfSprite_setTexture(bag->sprite.next, bag->texture.next, sfTrue);
    sfSprite_setTexture(bag->sprite.ctrl, bag->texture.ctrl, sfTrue);
    sfSprite_setTexture(bag->sprite.exit, bag->texture.exit, sfTrue);
    sfSprite_setTexture(bag->sprite.menu, bag->texture.menu, sfTrue);
    sfSprite_setTexture(bag->sprite.re, bag->texture.re, sfTrue);
    sfSprite_setTexture(bag->sprite.sqgc, bag->texture.sqgc, sfTrue);
    sfSprite_setTexture(bag->sprite.sqgx, bag->texture.sqgx, sfTrue);
    sfSprite_setTexture(bag->sprite.ng, bag->texture.ng, sfTrue);
    sfSprite_setTexture(bag->sprite.towerchose,
                        bag->texture.towerchose, sfTrue);
    sfSprite_setTexture(bag->sprite.potion, bag->texture.potion, sfTrue);
    setexsprite_two(bag);
}
