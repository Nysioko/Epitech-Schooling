/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** pause
*/

#include "rpg.h"

void mute_musics(rpg_t *rpg, bool mute)
{
    if (mute) {
        sfMusic_setVolume(rpg->musics.htp, 0);
        sfMusic_setVolume(rpg->musics.menu, 0);
        sfMusic_setVolume(rpg->musics.select, 0);
        sfMusic_setVolume(rpg->musics.theme, 0);
        sfSprite_setTexture(rpg->pause.pause_spr, rpg->pause.muted, sfTrue);
        rpg->bol.muted = true;
    } else {
        sfMusic_setVolume(rpg->musics.htp, 100);
        sfMusic_setVolume(rpg->musics.menu, 100);
        sfMusic_setVolume(rpg->musics.select, 100);
        sfMusic_setVolume(rpg->musics.theme, 100);
        sfSprite_setTexture(rpg->pause.pause_spr,
        rpg->pause.pause_text, sfTrue);
        rpg->bol.muted = false;
    }
}

bool inputs_pause2(rpg_t *rpg, sfVector2i mouse)
{
    if ((rpg->event.mouseButton.button == sfMouseLeft && rpg->event.type ==
    sfEvtMouseButtonPressed && mouse.x >= 26 && mouse.x <= 118 &&
    mouse.y >= 979 && mouse.y <= 1069)) {
        sfMusic_stop(rpg->musics.theme);
        sfRenderWindow_close(rpg->window);
        return true;
    }
    if ((rpg->event.mouseButton.button == sfMouseLeft && rpg->event.type ==
    sfEvtMouseButtonPressed && mouse.x >= 1810 && mouse.x <= 1890 &&
    mouse.y >= 15 && mouse.y <= 90)) {
        save_game(rpg);
        return false;
    }
    if ((rpg->event.mouseButton.button == sfMouseLeft && rpg->event.type ==
    sfEvtMouseButtonPressed && mouse.x >= 1800 && mouse.x <= 1900 &&
    mouse.y >= 980 && mouse.y <= 1070)) {
        mute_musics(rpg, !rpg->bol.muted);
        return false;
    }
    return false;
}

bool inputs_pause(rpg_t *rpg, sfVector2i mouse)
{
    if ((rpg->event.mouseButton.button == sfMouseLeft && rpg->event.type ==
    sfEvtMouseButtonPressed && mouse.x >= 20 && mouse.x <= 112 &&
    mouse.y >= 12 && mouse.y <= 97) || (rpg->event.key.code == sfKeyEscape
    && rpg->event.type == sfEvtKeyPressed)) {
        rpg->bol.pause = false;
        rpg->bol.play = true;
    }
    if ((rpg->event.mouseButton.button == sfMouseLeft && rpg->event.type ==
    sfEvtMouseButtonPressed && mouse.x >= 130 && mouse.x <= 219 &&
    mouse.y >= 14 && mouse.y <= 101)) {
        rpg->bol.pause = false;
        rpg->bol.menu = true;
        sfMusic_stop(rpg->musics.theme);
        sfMusic_play(rpg->musics.menu);
    }
    return inputs_pause2(rpg, mouse);
}