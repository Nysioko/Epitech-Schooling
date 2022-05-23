/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** func_useful
*/

#include "rpg.h"

bool same_color(sfColor color1, sfColor color2)
{
    if ((color1.a >= color2.a - 30 && color1.a <= color2.a + 30) &&
    (color1.b >= color2.b - 30 && color1.b <= color2.b + 30) &&
    (color1.r >= color2.r - 30 && color1.r <= color2.r + 30) &&
    (color1.g >= color2.g - 30 && color1.g <= color2.g + 30))
        return true;
    return false;
}

void get_spr_dimensions(sfSprite *spr)
{
    sfFloatRect hello = sfSprite_getGlobalBounds(spr);

    my_printf("height : %d\nleft : %d\ntop : %d\nwidth : %d\n",
    (int)hello.height, (int)hello.left, (int)hello.top, (int)hello.width);
}

bool is_in_confilict(sfSprite *obj, sfVector2f pos_obj,
sfSprite *obs, sfVector2f pos_obs)
{
    sfFloatRect obj_dim = sfSprite_getGlobalBounds(obj);
    sfFloatRect obs_dim = sfSprite_getGlobalBounds(obs);

    if (pos_obj.x <= pos_obs.x + obs_dim.width &&
    pos_obj.x + obj_dim.width >= pos_obs.x &&
    pos_obj.y <= pos_obs.y + obs_dim.height &&
    pos_obj.y + obj_dim.height >= pos_obs.y)
        return true;
    return false;
}

bool talk_cynthia(rpg_t *rpg)
{
    sfFloatRect obj_dim = sfSprite_getGlobalBounds(rpg->player.spr[0]);
    sfFloatRect obs_dim = sfSprite_getGlobalBounds(rpg->cynthia.spr[0]);

    if (rpg->player.pos.x - 20 <= rpg->cynthia.pos.x + obs_dim.width + 20 &&
    rpg->player.pos.x + obj_dim.width + 20 >= rpg->cynthia.pos.x - 20 &&
    rpg->player.pos.y -20 <= rpg->cynthia.pos.y + obs_dim.height + 20 &&
    rpg->player.pos.y + obj_dim.height + 20 >= rpg->cynthia.pos.y - 20)
        return true;
    return false;
}