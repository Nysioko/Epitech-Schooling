/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban
** File description:
** map_center
*/

#include "my_sokoban.h"
#include "my.h"

int my_strcharlen(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i] != NULL) {
        if (my_strlen(map[i]) > j)
            j = my_strlen(map[i]);
        i++;
    }
    return j;
}

int my_charlen(char **map)
{
    int i = 0;

    while (map[i] != NULL)
        i++;
    return i;
}

void print_map(soko_t *soko)
{
    int i = 0;
    int x = 0;
    int y = 0;

    getmaxyx(stdscr, y, x);
    while (soko->map[i] != NULL) {
        wmove(stdscr, (y - my_charlen(soko->map)) / 2 + i,
        (x - my_strcharlen(soko->map)) / 2);
        wprintw(stdscr, "%s", soko->map[i]);
        i++;
    }
    if (my_charlen(soko->map) > y || my_strcharlen(soko->map) > x) {
        clear();
        wmove(stdscr, y / 2, (x - 11) / 2);
        wprintw(stdscr, "The shell is too small");
    }
}