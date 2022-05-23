/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** fight
*/

#include "rpg.h"

void fight3(rpg_t *rpg, char *str, char *buff)
{
    if (rpg->player.pika.hp <= 0) {
        buff = my_strcat_clean(buff, "You lost, but your "
        "pikachu leveled up, \nhe is now level ");
        buff = my_strcat_clean(buff, str);
        buff = my_strcat_clean(buff, ".\nHere is a berry to heal him !");
        sfText_setString(rpg->dialog.txt, buff);
    } else {
        buff = my_strcat_clean(buff, "You won ! You pikachu leveled up, \nhe is "
        " now level ");
        buff = my_strcat_clean(buff, str);
        buff = my_strcat_clean(buff, ".\nHere is a berry to heal him !\n"
        "Good job beating me.");
    }
    sfText_setString(rpg->dialog.txt, buff);
    free(str);
    free(buff);
}

void fight2(rpg_t *rpg, char *str, char *buff)
{
    for (rpg->cynthia.ronflex.hp = 100; rpg->cynthia.ronflex.hp > 0 &&
    rpg->player.pika.hp > 0; rpg->cynthia.ronflex.hp -= rpg->player.pika.dmg,
    rpg->player.pika.hp -= rpg->cynthia.ronflex.dmg);
    rpg->player.pika.lvl++;
    rpg->player.pika.hp_max += 2;
    rpg->player.pika.dmg = rpg->player.pika.lvl % 10;
    rpg->inventory.berries++;
    buff[0] = '\0';
    int_to_str(rpg->player.pika.lvl, str);
    fight3(rpg, str, buff);
}

void fight(rpg_t *rpg)
{
    char *str = malloc(sizeof(char) * 11);
    char *buff;

    if (!str)
        return;
    buff = malloc(sizeof(char) * 200);
    if (!buff)
        return;
    if (rpg->cynthia.ronflex.hp != 100) {
        free(buff);
        free(str);
        return;
    }
    if (rpg->player.pika.hp <= 0) {
        free(buff);
        free(str);
        sfText_setString(rpg->dialog.txt, "You pokemon has no HP left !");
        return;
    }
    fight2(rpg, str, buff);
}

void heal_pok(rpg_t *rpg)
{
    if (rpg->inventory.berries == 0 && !rpg->cynthia.healed)
        sfText_setString(rpg->dialog.txt, "You don't have enough berries");
    else if (!rpg->cynthia.healed) {
        rpg->inventory.berries--;
        rpg->player.pika.hp = rpg->player.pika.hp_max;
        sfText_setString(rpg->dialog.txt, "Pokemon healed !");
        rpg->cynthia.healed = true;
    }
}