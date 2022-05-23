/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** texture
*/

#include "my_defender.h"

int initexturetwo(bag_t *bag)
{
    bag->texture.play =
    sfTexture_createFromFile("./ressources/texture/img/lb/13.png", NULL);
    bag->texture.back =
    sfTexture_createFromFile("./ressources/texture/img/lb/1.png", NULL);
    bag->texture.next =
    sfTexture_createFromFile("./ressources/texture/img/lb/2.png", NULL);
    bag->texture.ctrl =
    sfTexture_createFromFile("./ressources/texture/img/lb/3.png", NULL);
    bag->texture.exit =
    sfTexture_createFromFile("./ressources/texture/img/lb/4.png", NULL);
    bag->texture.menu =
    sfTexture_createFromFile("./ressources/texture/img/lb/6.png", NULL);
    bag->texture.towerchose =
    sfTexture_createFromFile("./ressources/sprites/paterns/towerc.png", NULL);
    bag->texture.map =
    sfTexture_createFromFile("./ressources/texture/img/map.png", NULL);
    bag->texture.sqg =
    sfTexture_createFromFile("./ressources/sprites/paterns/9.png", NULL);
    return 0;
}

int initexture(bag_t *bag)
{
    initexturetwo(bag);
    bag->texture.re =
    sfTexture_createFromFile("./ressources/texture/img/lb/11.png", NULL);
    bag->texture.ng =
    sfTexture_createFromFile("./ressources/texture/img/lb/7.png", NULL);
    bag->texture.bcg =
    sfTexture_createFromFile("./ressources/texture/img/bcg.png", NULL);
    bag->texture.potion =
    sfTexture_createFromFile("./ressources/sprites/potion.png", NULL);
    if (initexturethree(bag) == 84)
        return (84);
    return (0);
}