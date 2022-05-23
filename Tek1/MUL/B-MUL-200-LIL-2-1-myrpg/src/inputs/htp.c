/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** htp
*/

#include "rpg.h"

bool inputs_htp(rpg_t *rpg, sfVector2i mouse)
{
    if ((rpg->event.mouseButton.button == sfMouseLeft && rpg->event.type ==
    sfEvtMouseButtonPressed && mouse.x >= 90 && mouse.x <= 184 &&
    mouse.y >= 925 && mouse.y <= 1012) || (rpg->event.key.code == sfKeyEscape
    && rpg->event.type == sfEvtKeyPressed)) {
        rpg->bol.menu = true;
        rpg->bol.htp = false;
        sfMusic_stop(rpg->musics.htp);
        sfMusic_play(rpg->musics.menu);
    }
    return false;
}