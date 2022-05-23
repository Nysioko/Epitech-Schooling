/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** init
*/

#include "my_defender.h"

void init1(bag_t *bag)
{
    bag->texture.coin = sfTexture_createFromFile
    ("ressources/sprites/coin.png", NULL);
    bag->sprite.coin = sfSprite_create();
    sfSprite_setTexture(bag->sprite.coin, bag->texture.coin, sfTrue);
    sfSprite_setPosition(bag->sprite.coin, (sfVector2f){25, 360});
    sfSprite_setScale(bag->sprite.coin, (sfVector2f){0.15, 0.15});
}

void coding_stylecastle(bag_t *bag)
{
    for (int i = 0; i <= 2; i++) {
        bag->sprite.castle[i] = sfSprite_create();
        sfSprite_setTexture(bag->sprite.castle[i],
        bag->texture.castle[i], sfTrue);
        sfSprite_setPosition(bag->sprite.castle[i], (sfVector2f){1750, 145});
        sfSprite_setScale(bag->sprite.castle[i], (sfVector2f){0.6, 0.6});
    }
}

void initcastle(bag_t *bag)
{
    bag->texture.castle = malloc(sizeof(sfTexture *) * 4);
    bag->texture.castle[0] = sfTexture_createFromFile
    ("ressources/sprites/paterns/castle.png", NULL);
    bag->texture.castle[1] = sfTexture_createFromFile
    ("ressources/sprites/paterns/castlem.png", NULL);
    bag->texture.castle[2] = sfTexture_createFromFile
    ("ressources/sprites/paterns/castleb.png", NULL);
    bag->sprite.castle = malloc(sizeof(sfSprite *) * 4);
    coding_stylecastle(bag);
}

void rotation(bag_t *bag, int i, int j)
{
    bag->tower.rotate[0] = 90;
    bag->tower.rotate[1] = 30;
    bag->tower.rotate[2] = 180;
    bag->tower.rotate[3] = 50;
    bag->tower.rotate[4] = 90;
    bag->tower.rotate[5] = 70;
    bag->tower.rotate[6] = 250;
    bag->tower.rotate[7] = 20;
    bag->tower.rotate[8] = 0;
    bag->tower.rotate[9] = 110;
    bag->tower.rotate[10] = 220;
    bag->tower.rotate[11] = 290;
    bag->tower.rotate[12] = 175;

    sfFloatRect size = sfSprite_getGlobalBounds(bag->sprite.twr[i][j]);
    sfSprite_setOrigin(bag->sprite.twr[i][j],
    (sfVector2f){size.width / 2, size.height / 2});
    sfSprite_rotate(bag->sprite.twr[i][j], bag->tower.rotate[i]);
    sfSprite_setOrigin(bag->sprite.twr[i][j], (sfVector2f){0, 0});
}