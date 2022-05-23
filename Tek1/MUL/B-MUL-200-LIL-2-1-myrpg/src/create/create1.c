/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** create1
*/

#include "rpg.h"

int c_five(rpg_t *rpg)
{
    rpg->pause.pause_spr = sfSprite_create();
    if (!rpg->pause.pause_spr)
        return 84;
    rpg->pause.pause_text = sfTexture_createFromFile
    ("all/sprites/title/pause.png", NULL);
    if (!rpg->pause.pause_text)
        return 84;
    sfSprite_setTexture(rpg->pause.pause_spr, rpg->pause.pause_text, sfTrue);
    rpg->menu.select_spr = sfSprite_create();
    if (!rpg->menu.select_spr)
        return 84;
    rpg->menu.select_text = sfTexture_createFromFile
    ("all/sprites/title/choose_plyr.jpg", NULL);
    if (!rpg->menu.select_text)
        return 84;
    sfSprite_setTexture(rpg->menu.select_spr, rpg->menu.select_text, sfTrue);
    return 0;
}

int c_four(rpg_t *rpg)
{
    rpg->menu.menu_spr = sfSprite_create();
    if (!rpg->menu.menu_spr)
        return 84;
    rpg->menu.menu_text = sfTexture_createFromFile
    ("all/sprites/title/back.png", NULL);
    if (!rpg->menu.menu_text)
        return 84;
    sfSprite_setTexture(rpg->menu.menu_spr, rpg->menu.menu_text, sfTrue);
    rpg->menu.htp_spr = sfSprite_create();
    if (!rpg->menu.htp_spr)
        return 84;
    rpg->menu.htp_text = sfTexture_createFromFile
    ("all/sprites/title/htp_menu.jpg", NULL);
    if (!rpg->menu.htp_text)
        return 84;
    sfSprite_setTexture(rpg->menu.htp_spr, rpg->menu.htp_text, sfTrue);
    return 0;
}

int c_three(rpg_t *rpg)
{
    rpg->musics.select = sfMusic_createFromFile("all/sounds/curc/curc.ogg");
    if (!rpg->musics.select)
        return 84;
    rpg->musics.menu = sfMusic_createFromFile("all/sounds/title/theme.ogg");
    if (!rpg->musics.menu)
        return 84;
    rpg->musics.htp = sfMusic_createFromFile("all/sounds/title/logo.ogg");
    if (!rpg->musics.htp)
        return 84;
    rpg->musics.theme = sfMusic_createFromFile("all/sounds/ingame/ig.ogg");
    if (!rpg->musics.theme)
        return 84;
    sfMusic_setLoop(rpg->musics.theme, sfTrue);
    sfMusic_setLoop(rpg->musics.menu, sfTrue);
    sfMusic_setLoop(rpg->musics.select, sfTrue);
    sfMusic_setLoop(rpg->musics.htp, sfTrue);
    return 0;
}

int c_two(rpg_t *rpg)
{
    rpg->map.spr = sfSprite_create();
    if (!rpg->map.spr)
        return 84;
    rpg->map.text = sfTexture_createFromFile("all/map.png", NULL);
    if (!rpg->map.text)
        return 84;
    sfSprite_setTexture(rpg->map.spr, rpg->map.text, sfTrue);
    rpg->map.clock = sfClock_create();
    if (!rpg->map.clock)
        return 84;
    rpg->player.clock = sfClock_create();
    if (!rpg->player.clock)
        return 84;
    rpg->player.i = 0;
    sfSprite_setPosition(rpg->map.spr, (sfVector2f){-960, -1070});
    return 0;
}

rpg_t create_one(sfVideoMode mode)
{
    rpg_t rpg;

    rpg.window = sfRenderWindow_create(mode, "My_rpg",
    sfFullscreen, NULL);
    if (!rpg.window)
        return rpg;
    rpg.bol.load = 0;
    rpg.bol.loading = true;
    rpg.bol.menu = false;
    rpg.bol.pause = false;
    rpg.bol.map = true;
    rpg.bol.play = false;
    rpg.bol.htp = false;
    rpg.bol.intro = false;
    rpg.bol.select = false;
    rpg.bol.player = false;
    rpg.bol.dialog = false;
    return set_loading(rpg);
}
