/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban
** File description:
** init
*/

#include "../include/my.h"
#include "../include/my_sokoban.h"

void reload_map(soko_t *soko)
{
    char *buff = open_file(soko->avdeun);

    my_freeter(soko->map);
    soko->map = spliter(buff, '\n', 0);
    map_checker(soko);
    free(buff);
}

void manachar(soko_t *soko, int i)
{
    if (i == KEY_UP)
        to_up(soko);
    if (i == KEY_DOWN)
        to_down(soko);
    if (i == KEY_RIGHT)
        to_right(soko);
    if (i == KEY_LEFT)
        to_left(soko);
    if (i == ' ')
        reload_map(soko);
    oprint(soko);
}

int game_loop(soko_t *soko)
{
    int i = 0;

    while (true) {
        i = wgetch(stdscr);
        wclear(stdscr);
        manachar(soko, i);
        print_map(soko);
        wrefresh(stdscr);
        if (losing(soko) == EXIT_SUCCESS)
            return EXIT_FAILURE;
        if (winning(soko) == EXIT_SUCCESS)
            return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}

int init(soko_t *soko)
{
    int a = 0;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    wclear(stdscr);
    curs_set(0);
    print_map(soko);
    wrefresh(stdscr);
    a = game_loop(soko);
    endwin();
    return a;
}