/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** load
*/

#include "rpg.h"

rpg_t error(rpg_t rpg)
{
    rpg.window = NULL;
    return rpg;
}

rpg_t set_loading(rpg_t rpg)
{
    rpg.load.spr = sfSprite_create();
    if (!rpg.load.spr)
        return error(rpg);
    rpg.load.text = sfTexture_createFromFile("all/extras/loading_screen.jpg",
    NULL);
    if (!rpg.load.text)
        return error(rpg);
    sfSprite_setTexture(rpg.load.spr, rpg.load.text, sfTrue);
    rpg.load.load_spr = sfSprite_create();
    if (!rpg.load.load_spr)
        return error(rpg);
    rpg.load.load_text = sfTexture_createFromFile("all/extras/loading.png",
    NULL);
    if (!rpg.load.load_text)
        return error(rpg);
    sfSprite_setTexture(rpg.load.load_spr, rpg.load.load_text, sfTrue);
    sfSprite_setPosition(rpg.load.load_spr, (sfVector2f){650, 800});
    return rpg;
}