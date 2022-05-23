/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** dialog
*/

#include "rpg.h"

bool inputs_dialog2(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyEnter &&
    rpg->event.type == sfEvtKeyPressed && (rpg->cynthia.discuss ||
    rpg->cynthia.quest || rpg->cynthia.fight || rpg->cynthia.heal)) {
        rpg->cynthia.discuss = false;
        rpg->cynthia.quest = false;
        rpg->cynthia.heal = false;
        rpg->cynthia.fight = false;
        rpg->cynthia.healed = false;
        rpg->cynthia.ronflex.hp = 100;
        return false;
    }
    if (rpg->event.key.code == sfKeyEnter &&
    rpg->event.type == sfEvtKeyPressed) {
        rpg->cynthia.discuss = rpg->cynthia.cursor == 0 ? true : false;
        rpg->cynthia.fight = rpg->cynthia.cursor == 1 ? true : false;
        rpg->cynthia.quest = rpg->cynthia.cursor == 2 ? true : false;
        rpg->cynthia.heal = rpg->cynthia.cursor == 3 ? true : false;
    }
    return false;
}

bool inputs_dialog(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyRight && rpg->event.type == sfEvtKeyPressed)
        rpg->cynthia.cursor = rpg->cynthia.cursor == 3 ? 0 :
        rpg->cynthia.cursor + 1;
    if (rpg->event.key.code == sfKeyLeft && rpg->event.type == sfEvtKeyPressed)
        rpg->cynthia.cursor = rpg->cynthia.cursor == 0 ? 3 :
        rpg->cynthia.cursor - 1;
    if (rpg->event.key.code == sfKeyEscape &&
    rpg->event.type == sfEvtKeyPressed) {
        rpg->bol.dialog = false;
        rpg->bol.play = true;
    }
    return inputs_dialog2(rpg);
}