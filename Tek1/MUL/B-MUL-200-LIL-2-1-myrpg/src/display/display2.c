/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** display2
*/

#include "rpg.h"

void display_select(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->menu.select_spr, NULL);
}

void display_dialog2(rpg_t *rpg)
{
    if (!rpg->cynthia.fight && !rpg->cynthia.discuss && !rpg->cynthia.quest &&
    !rpg->cynthia.heal)
        sfText_setString(rpg->dialog.txt,
        "What do you want?\n\nDiscuss     Fight     Quest      Heal");
    if (rpg->cynthia.discuss)
        sfText_setString(rpg->dialog.txt, "I don't like to talk much");
    if (rpg->cynthia.quest)
        sfText_setString(rpg->dialog.txt, "Your goal is to beat me");
    if (rpg->cynthia.fight)
        fight(rpg);
    if (rpg->cynthia.heal)
        heal_pok(rpg);
    display_play(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->dialog.spr, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->dialog.txt, NULL);
    if (!rpg->cynthia.discuss && !rpg->cynthia.fight && !rpg->cynthia.quest &&
    !rpg->cynthia.heal)
        sfRenderWindow_drawText(rpg->window, rpg->dialog.cursor, NULL);
}

void display_dialog(rpg_t *rpg)
{
    if (rpg->cynthia.cursor == 0)
        sfText_setPosition(rpg->dialog.cursor, (sfVector2f){650, 930});
    if (rpg->cynthia.cursor == 1)
        sfText_setPosition(rpg->dialog.cursor, (sfVector2f){840, 930});
    if (rpg->cynthia.cursor == 2)
        sfText_setPosition(rpg->dialog.cursor, (sfVector2f){985, 930});
    if (rpg->cynthia.cursor == 3)
        sfText_setPosition(rpg->dialog.cursor, (sfVector2f){1150, 930});
    display_dialog2(rpg);
}