/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** play
*/

#include "rpg.h"

bool moving4(rpg_t *rpg)
{
    if ((rpg->event.key.code == sfKeyZ || rpg->event.key.code == sfKeyQ ||
    rpg->event.key.code == sfKeyS || rpg->event.key.code == sfKeyD ||
    rpg->event.key.code == sfKeyUp || rpg->event.key.code == sfKeyDown ||
    rpg->event.key.code == sfKeyLeft || rpg->event.key.code == sfKeyRight) &&
    rpg->event.type == sfEvtKeyReleased)
        rpg->player.state = stand_;
    if (rpg->event.key.code == sfKeyEscape && rpg->event.type ==
    sfEvtKeyPressed) {
        rpg->bol.pause = true;
        rpg->bol.play = false;
        return false;
    }
    return false;
}

bool moving3(rpg_t *rpg)
{
    if ((rpg->event.key.code == sfKeyLeft || rpg->event.key.code == sfKeyQ) &&
    rpg->event.type == sfEvtKeyPressed) {
        rpg->player.dir = left_;
        rpg->player.state = walk_;
        player_move(rpg);
        return false;
    }
    if ((rpg->event.key.code == sfKeyRight || rpg->event.key.code == sfKeyD) &&
    rpg->event.type == sfEvtKeyPressed) {
        rpg->player.dir = right_;
        rpg->player.state = walk_;
        player_move(rpg);
        return false;
    }
    return moving4(rpg);
}

bool moving2(rpg_t *rpg)
{
    if ((rpg->event.key.code == sfKeyDown || rpg->event.key.code == sfKeyS) &&
    rpg->event.type == sfEvtKeyPressed && rpg->map.time.microseconds >= 1000) {
        rpg->player.dir = down_;
        rpg->player.state = walk_;
        player_move(rpg);
        return false;
    }
    return moving3(rpg);
}

bool moving(rpg_t *rpg)
{
    if ((rpg->event.key.code == sfKeyUp || rpg->event.key.code == sfKeyZ) &&
    rpg->event.type == sfEvtKeyPressed && rpg->map.time.microseconds >= 1000) {
        rpg->player.dir = up_;
        rpg->player.state = walk_;
        player_move(rpg);
        return false;
    }
    return moving2(rpg);
}

bool inputs_play(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyEnter && rpg->event.type == sfEvtKeyPressed
    && talk_cynthia(rpg)) {
        rpg->bol.play = false;
        rpg->bol.dialog = true;
        rpg->cynthia.cursor = 0;
        rpg->cynthia.discuss = false;
        rpg->cynthia.fight = false;
        rpg->cynthia.quest = false;
        rpg->cynthia.heal = false;
        rpg->cynthia.healed = false;
    }
    return moving(rpg);
}