/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** text
*/

#include "my_defender.h"

void textstep(sfRenderWindow* window, bag_t *bag)
{
    char *step = malloc(sizeof(char) * 20);
    char *steptwo;
    char *stepthree = malloc(sizeof(char) * 20);
    sfVector2f text = {400, 10};

    steptwo = "Wave: ";
    step[0] = '\0';
    step = my_strcat(step, steptwo);
    stepthree[0] = '\0';
    stepthree = int_to_str(bag->enemy.step, stepthree);
    step = my_strcat(step, stepthree);
    sfText_setColor(bag->text.step, sfBlack);
    sfText_setFont(bag->text.step, bag->text.font);
    sfText_setCharacterSize(bag->text.step, 60);
    sfText_setString(bag->text.step, step);
    sfText_setPosition(bag->text.step, text);
    sfRenderWindow_drawText(window, bag->text.step, NULL);
    sfRenderWindow_drawSprite(window, bag->sprite.coin, NULL);
    free(step);
    free(stepthree);
}

void textmoney(sfRenderWindow* window, bag_t *bag)
{
    char *money = malloc(sizeof(char) * 10);
    sfVector2f text = {100, 350};

    sfText_setColor(bag->text.money, sfBlack);
    sfText_setFont(bag->text.money, bag->text.font);
    sfText_setCharacterSize(bag->text.money, 60);
    if (bag->money >= 850) {
        bag->money = 850;
        sfText_setColor(bag->text.money, sfRed);
    }
    sfText_setString(bag->text.money, int_to_str(bag->money, money));
    sfText_setPosition(bag->text.money, text);
    sfRenderWindow_drawText(window, bag->text.money, NULL);
    sfRenderWindow_drawSprite(window, bag->sprite.coin, NULL);
}