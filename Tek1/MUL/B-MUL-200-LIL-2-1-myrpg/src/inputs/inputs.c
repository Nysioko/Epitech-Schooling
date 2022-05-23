/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** inputs
*/

#include "rpg.h"

bool manage_inputs(rpg_t *rpg, sfVector2i mouse)
{
    if (rpg->bol.play)
        return inputs_play(rpg);
    if (rpg->bol.menu)
        return inputs_menu(rpg, mouse);
    if (rpg->bol.htp)
        return inputs_htp(rpg, mouse);
    if (rpg->bol.pause)
        return inputs_pause(rpg, mouse);
    if (rpg->bol.select)
        return inputs_select(rpg, mouse);
    if (rpg->bol.dialog)
        return inputs_dialog(rpg);
    return false;
}

bool key_pressed(rpg_t *rpg)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)rpg->window);

    if (rpg->bol.loading)
        return false;
    if (rpg->event.type == sfEvtClosed || (rpg->event.mouseButton.button ==
    sfMouseLeft && rpg->event.type == sfEvtMouseButtonPressed && mouse.x >= 844
    && mouse.x <= 1072 && mouse.y >= 826 && mouse.y <= 941 && rpg->bol.menu)) {
        sfRenderWindow_close(rpg->window);
        return true;
    }
    if (rpg->event.key.code == sfKeyA && rpg->event.type == sfEvtKeyPressed)
        my_printf("x : %d\ny : %d\n", mouse.x, mouse.y);
    manage_inputs(rpg, mouse);
    return false;
}