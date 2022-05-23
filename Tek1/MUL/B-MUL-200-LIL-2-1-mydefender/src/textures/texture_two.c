/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** texture_two
*/

#include "my_defender.h"

int veriftexture(bag_t *bag)
{
    if (!bag->texture.play || !bag->texture.bcg || !bag->texture.back ||
    !bag->texture.bcghelp || !bag->texture.ctrl || !bag->texture.exit ||
    !bag->texture.menu || !bag->texture.next || !bag->texture.re ||
    !bag->texture.sqg || !bag->texture.sqgc || !bag->texture.sqgx ||
    !bag->texture.towerchose || !bag->texture.twr[1] ||
    !bag->texture.twr[2] || !bag->texture.twr[3] || !bag->texture.twr[4]
    || !bag->texture.enemy[1] || !bag->texture.enemy[2] ||
    !bag->texture.enemy[3] || !bag->texture.enemy[4] || !bag->texture.ng
    || !bag->texture.potion)
        return (84);
    return (0);
}

int initexturefour(bag_t *bag)
{
    bag->texture.sqgsable =
    sfTexture_createFromFile("./ressources/sprites/paterns/33.png", NULL);
    bag->texture.sqgc =
    sfTexture_createFromFile("./ressources/sprites/paterns/10.png", NULL);
    bag->texture.sqgx =
    sfTexture_createFromFile("./ressources/sprites/paterns/11.png", NULL);
    bag->texture.enemy = malloc(sizeof(sfTexture *) * 5);
    if (bag->texture.enemy == NULL)
        return (84);
    bag->texture.enemy[1] =
    sfTexture_createFromFile("./ressources/sprites/paterns/53.png", NULL);
    bag->texture.enemy[2] =
    sfTexture_createFromFile("./ressources/sprites/paterns/54.png", NULL);
    bag->texture.enemy[3] =
    sfTexture_createFromFile("./ressources/sprites/paterns/55.png", NULL);
    bag->texture.enemy[4] =
    sfTexture_createFromFile("./ressources/sprites/paterns/56.png", NULL);

    return (0);
}

int initexturethree(bag_t *bag)
{
    bag->texture.twr = malloc(sizeof(sfTexture *) * 5);
    if (bag->texture.twr == NULL)
        return (84);
    bag->texture.twr[1] =
    sfTexture_createFromFile("./ressources/sprites/paterns/pig.png", NULL);
    bag->texture.twr[2] =
    sfTexture_createFromFile("./ressources/sprites/paterns/57.png", NULL);
    bag->texture.twr[3] =
    sfTexture_createFromFile("./ressources/sprites/paterns/91.png", NULL);
    bag->texture.twr[4] =
    sfTexture_createFromFile("./ressources/sprites/paterns/64.png", NULL);
    bag->texture.bcghelp =
    sfTexture_createFromFile("./ressources/howtoplay.png", NULL);
    initexturefour(bag);
    return (veriftexture(bag));
}