/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** play2
*/

#include "rpg.h"

void player_move_stairs2(rpg_t *rpg, int i, int *values)
{
    sfVector2f map_pos = sfSprite_getPosition(rpg->map.spr);

    if ((map_pos.y < 0 && rpg->player.pos.y == 500 &&
    rpg->player.state == walk_ && rpg->player.dir == up_) ||
    (map_pos.y > -1070 && rpg->player.pos.y == 500 &&
    rpg->player.state == walk_ && rpg->player.dir == down_)) {
        sfClock_restart(rpg->map.clock);
        sfSprite_setPosition(rpg->map.spr, (sfVector2f)
        {map_pos.x, map_pos.y - values[i * 2] / 4});
        rpg->cynthia.pos.y -= values[i * 2] / 4;
    } else if (((int)map_pos.y == 0 || (int)map_pos.y == -1070) ||
    (rpg->player.dir == right_ || rpg->player.dir == left_)) {
        rpg->player.pos.x += values[i * 2 + 1] / 4;
        rpg->player.pos.y += values[i * 2] / 4;
    }
}

void player_move_stairs(rpg_t *rpg, int i, int *values, sfVector2i tmp)
{
    if (same_color(sfImage_getPixel(rpg->map.img, tmp.x + rpg->player.pos.x +
    values[i * 2 + 1], tmp.y + rpg->player.pos.y + values[i * 2]), sfRed)) {
        if (rpg->player.dir == left_ || rpg->player.dir == right_) {
            rpg->player.pos.x += values[i * 2 + 1] / 4;
            rpg->player.pos.y += (values[i * 2 + 1] / 4) * -1;
        }
    } else if (same_color(sfImage_getPixel(rpg->map.img, tmp.x +
    rpg->player.pos.x + values[i * 2 + 1], tmp.y + rpg->player.pos.y +
    values[i * 2]), sfBlue))
        player_move_stairs2(rpg, i, values);
}

void player_move_ground(rpg_t *rpg, int i, int *values)
{
    sfVector2f map_pos = sfSprite_getPosition(rpg->map.spr);

    if ((map_pos.y < 0 && rpg->player.pos.y == 500 &&
    rpg->player.state == walk_ && rpg->player.dir == up_) ||
    (map_pos.y > -1070 && rpg->player.pos.y == 500 &&
    rpg->player.state == walk_ && rpg->player.dir == down_)) {
        sfClock_restart(rpg->map.clock);
        sfSprite_setPosition(rpg->map.spr, (sfVector2f)
        {map_pos.x, map_pos.y - values[i * 2]});
        rpg->cynthia.pos.y -= values[i * 2];
    } else if (((int)map_pos.y == 0 || (int)map_pos.y == -1070) ||
    (rpg->player.dir == right_ || rpg->player.dir == left_)) {
        rpg->player.pos.x += values[i * 2 + 1];
        rpg->player.pos.y += values[i * 2];
    }
}

void player_move(rpg_t *rpg)
{
    int dir[4] = {down_, up_, left_, right_};
    int values[8] = {10, 0, -10, 0, 0, -10, 0, 10};
    sfVector2f pos = sfSprite_getPosition(rpg->map.spr);
    int tmp_x = pos.x * -1;
    int tmp_y = (pos.y * -1) + 40;

    for (int i = 0; i < 4; i++) {
        if (rpg->player.dir == dir[i] && same_color(sfImage_getPixel(
            rpg->map.img, tmp_x + rpg->player.pos.x + values[i * 2 + 1],
            tmp_y + rpg->player.pos.y + values[i * 2]), sfWhite)) {
            player_move_ground(rpg, i, values);
            return;
        }
        if (rpg->player.dir == dir[i]) {
            player_move_stairs(rpg, i, values, (sfVector2i){tmp_x, tmp_y});
            return;
        }
    }
    rpg->player.state = stand_;
}