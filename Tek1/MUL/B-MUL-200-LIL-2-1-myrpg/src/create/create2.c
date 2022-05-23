/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** create2
*/

#include "rpg.h"

int c_nine(rpg_t *rpg)
{
    sfText_setPosition(rpg->inventory.berry, (sfVector2f){1020, 965});
    rpg->dialog.cursor = sfText_copy(rpg->dialog.txt);
    if (!rpg->dialog.cursor)
        return 84;
    sfText_setString(rpg->dialog.cursor, "->");
    sfText_setCharacterSize(rpg->dialog.cursor, 40);
    rpg->player.pika.dmg = 1;
    rpg->player.pika.hp = 50;
    rpg->player.pika.lvl = 1;
    rpg->cynthia.ronflex.dmg = 2;
    rpg->cynthia.ronflex.hp = 100;
    rpg->cynthia.ronflex.lvl = 1;
    rpg->player.pika.hp_max = rpg->player.pika.hp;
    rpg->cynthia.heal = false;
    rpg->cynthia.healed = false;
    return 0;
}

int c_eight(rpg_t *rpg)
{
    rpg->inventory.berries_str = malloc(sizeof(char) * 11);
    if (!rpg->inventory.berries_str)
        return 84;
    rpg->inventory.pok.lvl = 1;
    rpg->inventory.berries = 0;
    rpg->inventory.berry = sfText_copy(rpg->dialog.txt);
    if (!rpg->inventory.berry)
        return 84;
    sfText_setCharacterSize(rpg->inventory.berry, 100);
    int_to_str(rpg->inventory.berries, rpg->inventory.berries_str);
    rpg->bol.muted = false;
    rpg->pause.muted = sfTexture_createFromFile("all/sprites/title/mute.png",
    NULL);
    if (!rpg->pause.muted)
        return 84;
    if (load_save(rpg) == 84)
        return 84;
    if (rpg->bol.muted)
        mute_musics(rpg, true);
    return 0;
}

int c_seven(rpg_t *rpg)
{
    rpg->map.poto_text = sfTexture_createFromFile("all/poto.png", NULL);
    if (!rpg->map.poto_text)
        return 84;
    sfSprite_setTexture(rpg->map.poto_spr, rpg->map.poto_text, sfTrue);
    rpg->dialog.font = sfFont_createFromFile("all/font.ttf");
    if (!rpg->dialog.font)
        return 84;
    rpg->dialog.txt = sfText_create();
    if (!rpg->dialog.txt)
        return 84;
    sfText_setFont(rpg->dialog.txt, rpg->dialog.font);
    sfText_setColor(rpg->dialog.txt, sfBlack);
    sfText_setPosition(rpg->dialog.txt, (sfVector2f){700, 850});
    rpg->dialog.state = ended_;
    if (create_cynthia(rpg) == 84)
        return 84;
    return 0;
}

int c_six(rpg_t *rpg)
{
    rpg->map.img = sfImage_createFromFile("all/map_walk.jpg");
    if (!rpg->map.img)
        return 84;
    rpg->player.dir = down_;
    rpg->player.state = stand_;
    rpg->player.pos = (sfVector2f){500, 600};
    rpg->dialog.spr = sfSprite_create();
    if (!rpg->dialog.spr)
        return 84;
    rpg->dialog.text = sfTexture_createFromFile
    ("all/extras/dialog_box.png", NULL);
    if (!rpg->dialog.text)
        return 84;
    sfSprite_setTexture(rpg->dialog.spr, rpg->dialog.text, sfTrue);
    sfSprite_setPosition(rpg->dialog.spr, (sfVector2f){550, 800});
    rpg->map.poto_spr = sfSprite_create();
    if (!rpg->map.poto_spr)
        return 84;
    return 0;
}