/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** player
*/

#include "rpg.h"

void manage_anim_player(rpg_t *rpg, int i)
{
    if (rpg->player.i >= i * 3 && rpg->player.i <= (i * 3) + 2 &&
    rpg->player.time.microseconds >= 200000) {
        if (rpg->player.state == walk_ && rpg->player.i == i * 3)
            rpg->player.i++;
        else if (rpg->player.state == walk_)
            rpg->player.i = rpg->player.i == i * 3 + 1 ? i * 3 + 2 : i * 3 + 1;
        else
            rpg->player.i = i * 3;
        sfClock_restart(rpg->player.clock);
    } else if (rpg->player.i < i * 3 || rpg->player.i > (i * 3) + 2)
        rpg->player.i = i * 3;
}

void display_player(rpg_t *rpg)
{
    int dir[4] = {down_, up_, left_, right_};
    sfVector2f pos = sfSprite_getPosition(rpg->map.spr);

    if (rpg->player.pos.y <= 509 && rpg->player.pos.y >= 491)
        rpg->player.pos.y = 500;
    if (pos.y >= 1 && pos.y <= 9)
        sfSprite_setPosition(rpg->map.spr, (sfVector2f){pos.x, (float)0});
    if (pos.y <= -1061 && pos.y >= -1069)
        sfSprite_setPosition(rpg->map.spr, (sfVector2f){pos.x, (float)-1070});
    for (int i = 0; i < 4; i++) {
        if (rpg->player.dir == dir[i])
            manage_anim_player(rpg, i);
    }
    for (int i = 0; i != 12; i++)
        sfSprite_setPosition(rpg->player.spr[i], rpg->player.pos);
    sfRenderWindow_drawSprite(rpg->window,
    rpg->player.spr[rpg->player.i], NULL);
}

void manage_hitbox_cynthia(rpg_t *rpg, sfVector2f map)
{
    if (rpg->cynthia.dir == right_) {
        rpg->cynthia.pos.x += 5;
        if (is_in_confilict(rpg->player.spr[0], rpg->player.pos,
        rpg->cynthia.spr[0], rpg->cynthia.pos)) {
            rpg->cynthia.pos.y -= 60;
            sfSprite_setPosition(rpg->map.spr, (sfVector2f){map.x, map.y - 60});
        }
    } else if (rpg->cynthia.dir == left_) {
        rpg->cynthia.pos.x -= 5;
        if (is_in_confilict(rpg->player.spr[0], rpg->player.pos,
        rpg->cynthia.spr[0], rpg->cynthia.pos)) {
            rpg->cynthia.pos.y -= 60;
            sfSprite_setPosition(rpg->map.spr, (sfVector2f){map.x, map.y - 60});
        }
    }
}

void manage_pos_cynthia(rpg_t *rpg)
{
    if (rpg->cynthia.pos.x <= 830) {
        rpg->cynthia.dir = right_;
        rpg->cynthia.i = 6;
    } else if (rpg->cynthia.pos.x >= 970) {
        rpg->cynthia.dir = left_;
        rpg->cynthia.i = 3;
    }
    manage_hitbox_cynthia(rpg, sfSprite_getPosition(rpg->map.spr));
}

void display_cynthia(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->cynthia.spr[rpg->cynthia.i], rpg->cynthia.pos);
    sfRenderWindow_drawSprite(rpg->window,
    rpg->cynthia.spr[rpg->cynthia.i], NULL);
    if (rpg->cynthia.time.microseconds < 200000 || !rpg->bol.play)
        return;
    sfClock_restart(rpg->cynthia.clock);
    if (rpg->cynthia.dir == left_) {
        if (rpg->cynthia.i == 4)
            rpg->cynthia.i = 3;
        else
            rpg->cynthia.i++;
    } else if (rpg->cynthia.dir == right_) {
        if (rpg->cynthia.i == 7)
            rpg->cynthia.i = 6;
        else
            rpg->cynthia.i++;
    }
    manage_pos_cynthia(rpg);
}