/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** destroy
*/

#include "rpg.h"

int destroy4(rpg_t *rpg)
{
    sfSprite_destroy(rpg->load.load_spr);
    sfSprite_destroy(rpg->load.spr);
    sfTexture_destroy(rpg->load.load_text);
    sfTexture_destroy(rpg->load.text);
    return 0;
}

int destroy3(rpg_t *rpg)
{
    sfFont_destroy(rpg->dialog.font);
    sfText_destroy(rpg->dialog.txt);
    sfTexture_destroy(rpg->dialog.text);
    sfSprite_destroy(rpg->dialog.spr);
    sfSprite_destroy(rpg->map.poto_spr);
    sfTexture_destroy(rpg->map.poto_text);
    for (int i = 0; i < 8; i++) {
        sfSprite_destroy(rpg->cynthia.spr[i]);
        sfTexture_destroy(rpg->cynthia.text[i]);
    }
    free(rpg->cynthia.spr);
    free(rpg->cynthia.text);
    sfClock_destroy(rpg->cynthia.clock);
    free(rpg->inventory.berries_str);
    sfText_destroy(rpg->inventory.berry);
    return destroy4(rpg);
}

int destroy2(rpg_t *rpg)
{
    if (rpg->bol.player) {
        for (int i = 0; i < 12; i++) {
            sfSprite_destroy(rpg->player.spr[i]);
            sfTexture_destroy(rpg->player.text[i]);
        }
        free(rpg->player.spr);
        free(rpg->player.text);
    }
    sfMusic_destroy(rpg->musics.htp);
    sfMusic_destroy(rpg->musics.menu);
    sfMusic_destroy(rpg->musics.select);
    sfMusic_destroy(rpg->musics.theme);
    sfImage_destroy(rpg->map.img);
    return destroy3(rpg);
}

int destroy(rpg_t *rpg)
{
    sfRenderWindow_destroy(rpg->window);
    sfSprite_destroy(rpg->map.spr);
    sfTexture_destroy(rpg->map.text);
    sfClock_destroy(rpg->map.clock);
    sfClock_destroy(rpg->player.clock);
    sfSprite_destroy(rpg->menu.menu_spr);
    sfTexture_destroy(rpg->menu.menu_text);
    sfSprite_destroy(rpg->menu.htp_spr);
    sfTexture_destroy(rpg->menu.htp_text);
    sfSprite_destroy(rpg->pause.pause_spr);
    sfTexture_destroy(rpg->pause.pause_text);
    sfSprite_destroy(rpg->menu.select_spr);
    sfTexture_destroy(rpg->menu.select_text);
    return destroy2(rpg);
}