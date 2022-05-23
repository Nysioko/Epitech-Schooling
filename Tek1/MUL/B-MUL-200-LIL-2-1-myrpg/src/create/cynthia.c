/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** cynthia
*/

#include "rpg.h"

int create_cynthia2(rpg_t *rpg, int i)
{
    char *str;
    char *str2;

    str2 = malloc(sizeof(char) * 11);
    int_to_str(i + 1, str2);
    str = insert_str("all/sprites/npc/cynthia/cynthia.png", str2, 31);
    rpg->cynthia.spr[i] = sfSprite_create();
    if (rpg->cynthia.spr[i] == NULL)
        return 84;
    rpg->cynthia.text[i] = sfTexture_createFromFile(str, NULL);
    if (rpg->cynthia.text[i] == NULL)
        return 84;
    sfSprite_setTexture(rpg->cynthia.spr[i], rpg->cynthia.text[i], sfTrue);
    free(str);
    free(str2);
    rpg->cynthia.cursor = 0;
    return 0;
}

int create_cynthia(rpg_t *rpg)
{
    rpg->cynthia.spr = malloc(sizeof(sfSprite *) * 8);
    if (rpg->cynthia.spr == NULL)
        return 84;
    rpg->cynthia.text = malloc(sizeof(sfTexture *) * 8);
    if (rpg->cynthia.text == NULL)
        return 84;
    rpg->cynthia.pos = (sfVector2f){830, -70};
    rpg->cynthia.i = 0;
    rpg->cynthia.dir = right_;
    rpg->cynthia.discuss = false;
    rpg->cynthia.fight = false;
    rpg->cynthia.quest = false;
    for (int i = 0; i < 8; i++) {
        if (create_cynthia2(rpg, i) == 84)
            return 84;
    }
    rpg->cynthia.clock = sfClock_create();
    if (!rpg->cynthia.clock)
        return 84;
    return 0;
}