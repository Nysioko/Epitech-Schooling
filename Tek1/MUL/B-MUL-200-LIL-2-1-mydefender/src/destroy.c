/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** destroy
*/

#include "my_defender.h"

void texturedestroy_two(bag_t *bag)
{
    sfTexture_destroy(bag->texture.ng);
    sfTexture_destroy(bag->texture.sqg);
    sfTexture_destroy(bag->texture.sqgc);
    sfTexture_destroy(bag->texture.sqgx);
    sfTexture_destroy(bag->texture.sqgsable);
    sfTexture_destroy(bag->texture.towerchose);
    sfTexture_destroy(bag->texture.coin);
    sfTexture_destroy(bag->texture.potion);
    for (int i = 1; i < 5; i++)
        sfTexture_destroy(bag->texture.twr[i]);
    free(bag->texture.twr);
    for (int i = 1; i < 3; i++)
        sfTexture_destroy(bag->texture.castle[i]);
    free(bag->texture.castle);
}

void texturedestroy(bag_t *bag)
{
    sfTexture_destroy(bag->texture.bcg);
    sfTexture_destroy(bag->texture.bcghelp);
    sfTexture_destroy(bag->texture.map);
    sfTexture_destroy(bag->texture.play);
    sfTexture_destroy(bag->texture.next);
    sfTexture_destroy(bag->texture.back);
    sfTexture_destroy(bag->texture.ctrl);
    sfTexture_destroy(bag->texture.exit);
    sfTexture_destroy(bag->texture.menu);
    sfTexture_destroy(bag->texture.re);
    texturedestroy_two(bag);
}

void spritedestroy_two(bag_t *bag)
{
    sfSprite_destroy(bag->sprite.menu);
    sfSprite_destroy(bag->sprite.re);
    sfSprite_destroy(bag->sprite.ng);
    sfSprite_destroy(bag->sprite.sqgc);
    sfSprite_destroy(bag->sprite.sqgx);
    sfSprite_destroy(bag->sprite.towerchose);
    sfSprite_destroy(bag->sprite.coin);
    for (int j = 0; j <= 4; j++) {
        for (int i = 0; i <= 12; i++)
            sfSprite_destroy(bag->sprite.twr[j][i]);
        free(bag->sprite.twr[j]);
    }
    free(bag->sprite.twr);
    for (int j = 0; j <= 4; j++) {
        for (int i = 0; i < 41; i++)
            sfSprite_destroy(bag->sprite.enemy[j][i]);
        free(bag->sprite.enemy[j]);
    }
    free(bag->sprite.enemy);
}

void spritedestroy(bag_t *bag)
{
    sfSprite_destroy(bag->sprite.bcg);
    sfSprite_destroy(bag->sprite.bcghelp);
    sfSprite_destroy(bag->sprite.map);
    sfSprite_destroy(bag->sprite.play);
    sfSprite_destroy(bag->sprite.next);
    sfSprite_destroy(bag->sprite.back);
    sfSprite_destroy(bag->sprite.ctrl);
    sfSprite_destroy(bag->sprite.exit);
    for (int i = 0; i < 4; i++)
        sfSprite_destroy(bag->sprite.sqg[i]);
    free(bag->sprite.sqg);
    spritedestroy_two(bag);
    for (int i = 1; i < 3; i++)
        sfSprite_destroy(bag->sprite.castle[i]);
    free(bag->sprite.castle);
    sfSprite_destroy(bag->sprite.potion);
}

void textdestroy(bag_t *bag)
{
    sfText_destroy(bag->text.money);
}