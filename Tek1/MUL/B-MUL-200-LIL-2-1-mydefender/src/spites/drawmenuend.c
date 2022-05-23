/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender
** File description:
** drawmenuend
*/

#include "my_defender.h"

void textend(sfRenderWindow* window, bag_t *bag, int i)
{
    char *end = malloc(sizeof(char) * 10);
    sfText *winlose = sfText_create();
    sfVector2f place = {900, 450};

    sfText_setColor(winlose, sfWhite);
    sfText_setFont(winlose, bag->text.font);
    sfText_setCharacterSize(winlose, 60);
    if (i == 1)
        sfText_setString(winlose, "You Won!");
    else
        sfText_setString(winlose, "You Lose!");
    sfText_setPosition(winlose, place);
    sfRenderWindow_drawText(window, winlose, NULL);
    sfRenderWindow_display(window);
    free(end);
    sfText_destroy(winlose);
}