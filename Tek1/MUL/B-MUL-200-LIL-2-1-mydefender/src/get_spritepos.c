/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** get_spritepos
*/

#include "my_defender.h"

sfFloatRect get_spritepos(bag_t *bag, sfSprite *sprite)
{
    sfFloatRect coord = sfSprite_getGlobalBounds(sprite);

    return (coord);
}