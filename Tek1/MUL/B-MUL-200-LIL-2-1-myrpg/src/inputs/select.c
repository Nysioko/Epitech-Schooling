/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** select
*/

#include "rpg.h"

int create_boy2(rpg_t *rpg, int i)
{
    char *tab[5] = {"front", "back", "left", "right", NULL};
    char *str;
    char *str2;
    char *str3;

    str2 = malloc(sizeof(char) * 11);
    int_to_str((i % 3) + 1, str2);
    str = insert_str("all/sprites/player/lucas//.png", tab[i / 3], 25);
    str3 = insert_str(str, str2, my_strlen(str) - 4);
    rpg->player.spr[i] = sfSprite_create();
    if (rpg->player.spr[i] == NULL)
        return 84;
    rpg->player.text[i] = sfTexture_createFromFile(str3, NULL);
    if (rpg->player.text[i] == NULL)
        return 84;
    sfSprite_setTexture(rpg->player.spr[i], rpg->player.text[i], sfTrue);
    free(str);
    free(str2);
    free(str3);
    return 0;
}

int create_boy(rpg_t *rpg)
{
    rpg->player.spr = malloc(sizeof(sfSprite *) * 12);
    rpg->bol.boy = true;
    if (rpg->player.spr == NULL)
        return 84;
    rpg->player.text = malloc(sizeof(sfTexture *) * 12);
    if (rpg->player.text == NULL)
        return 84;
    for (int i = 0; i < 12; i++) {
        if (create_boy2(rpg, i) == 84)
            return 84;
        sfSprite_setScale(rpg->player.spr[i], (sfVector2f){1.3, 1.3});
    }
    return 0;
}

int create_girl2(rpg_t *rpg, int i)
{
    char *tab[5] = {"front", "back", "left", "right", NULL};
    char *str;
    char *str2;
    char *str3;

    str2 = malloc(sizeof(char) * 11);
    int_to_str((i % 3) + 1, str2);
    str = insert_str("all/sprites/player/dawn//.png", tab[i / 3], 24);
    str3 = insert_str(str, str2, my_strlen(str) - 4);
    rpg->player.spr[i] = sfSprite_create();
    if (rpg->player.spr[i] == NULL)
        return 84;
    rpg->player.text[i] = sfTexture_createFromFile(str3, NULL);
    if (rpg->player.text[i] == NULL)
        return 84;
    sfSprite_setTexture(rpg->player.spr[i], rpg->player.text[i], sfTrue);
    free(str);
    free(str2);
    free(str3);
    return 0;
}

int create_girl(rpg_t *rpg)
{
    rpg->player.spr = malloc(sizeof(sfSprite *) * 12);
    rpg->bol.boy = false;
    if (rpg->player.spr == NULL)
        return 84;
    rpg->player.text = malloc(sizeof(sfTexture *) * 12);
    if (rpg->player.text == NULL)
        return 84;
    for (int i = 0; i < 12; i++) {
        if (create_girl2(rpg, i) == 84)
            return 84;
        sfSprite_setScale(rpg->player.spr[i], (sfVector2f){1.3, 1.3});
    }
    return 0;
}

bool inputs_select(rpg_t *rpg, sfVector2i mouse)
{
    if ((rpg->event.mouseButton.button ==
    sfMouseLeft && rpg->event.type == sfEvtMouseButtonPressed && mouse.x >= 416
    && mouse.x <= 728 && mouse.y >= 254 && mouse.y <= 907)) {
        rpg->bol.select = false;
        rpg->bol.play = true;
        rpg->bol.player = true;
        sfMusic_stop(rpg->musics.select);
        sfMusic_play(rpg->musics.theme);
        create_boy(rpg);
    } else if ((rpg->event.mouseButton.button ==
    sfMouseLeft && rpg->event.type == sfEvtMouseButtonPressed && mouse.x >= 1160
    && mouse.x <= 1472 && mouse.y >= 256 && mouse.y <= 908)) {
        rpg->bol.select = false;
        rpg->bol.play = true;
        rpg->bol.player = true;
        sfMusic_stop(rpg->musics.select);
        sfMusic_play(rpg->musics.theme);
        create_girl(rpg);
    }
    return false;
}