/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** menu
*/

#include "rpg.h"

bool inputs_menu2(rpg_t *rpg, sfVector2i mouse)
{
    if (rpg->event.mouseButton.button == sfMouseLeft && rpg->event.type ==
    sfEvtMouseButtonPressed && mouse.x >= 648 && mouse.x <= 1265 &&
    mouse.y >= 635 && mouse.y <= 796) {
        rpg->bol.menu = false;
        rpg->bol.htp = true;
        sfMusic_stop(rpg->musics.menu);
        sfMusic_play(rpg->musics.htp);
    }
    return false;
}

bool inputs_menu(rpg_t *rpg, sfVector2i mouse)
{
    if (rpg->event.mouseButton.button == sfMouseLeft && rpg->event.type ==
    sfEvtMouseButtonPressed && mouse.x >= 851 && mouse.x <= 1064 &&
    mouse.y >= 474 && mouse.y <= 613) {
        rpg->bol.menu = false;
        sfMusic_stop(rpg->musics.menu);
        if (rpg->bol.player) {
            rpg->bol.play = true;
            sfMusic_play(rpg->musics.theme);
        } else {
            rpg->bol.select = true;
            sfMusic_play(rpg->musics.select);
        }
    }
    return inputs_menu2(rpg, mouse);
}