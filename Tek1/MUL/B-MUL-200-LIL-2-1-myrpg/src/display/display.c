/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** display
*/

#include "rpg.h"

void display_htp(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->menu.htp_spr, NULL);
}

void display_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->menu.menu_spr, NULL);
}

void display_play(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->map.spr, NULL);
    for (int i = 0; i < 12; i++)
        sfSprite_setPosition(rpg->player.spr[i], rpg->player.pos);
    display_player(rpg);
    display_cynthia(rpg);
    sfSprite_setPosition(rpg->map.poto_spr, sfSprite_getPosition(rpg->map.spr));
    sfRenderWindow_drawSprite(rpg->window, rpg->map.poto_spr, NULL);
}

void display_pause(rpg_t *rpg)
{
    display_play(rpg);
    int_to_str(rpg->inventory.berries, rpg->inventory.berries_str);
    sfText_setString(rpg->inventory.berry, rpg->inventory.berries_str);
    sfRenderWindow_drawSprite(rpg->window, rpg->pause.pause_spr, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->inventory.berry, NULL);
}

void manage_display(rpg_t *rpg)
{
    if (rpg->bol.menu)
        display_menu(rpg);
    if (rpg->bol.play)
        display_play(rpg);
    if (rpg->bol.pause)
        display_pause(rpg);
    if (rpg->bol.htp)
        display_htp(rpg);
    if (rpg->bol.select)
        display_select(rpg);
    if (rpg->bol.dialog)
        display_dialog(rpg);
    sfRenderWindow_display(rpg->window);
    return;
}