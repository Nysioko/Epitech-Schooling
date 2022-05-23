/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** sprite_three
*/

#include "my_defender.h"

int initsprite_twobelike(bag_t *bag)
{
    bag->sprite.enemy = malloc(sizeof(sfSprite **) * 5);
    if (bag->sprite.enemy == NULL)
        return (84);
    for (int j = 0; j <= 4; j++) {
        bag->sprite.enemy[j] = malloc(sizeof(sfSprite *) * 42);
        if (bag->sprite.enemy[j] == NULL)
            return (84);
        for (int i = 0; i <= 40; i++) {
            bag->sprite.enemy[j][i] = sfSprite_create();
        }
    }
    return (0);
}