/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban
** File description:
** main
*/

#include "my.h"
#include "my_sokoban.h"

int help(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("     ./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("     map file representing../include/ the warehouse map, ");
        my_putstr("containing ‘#’ for walls, \n");
        my_putstr("         ‘P’ for the player, ‘X’ for boxes");
        my_putstr(" and ‘O’ for storage locations.\n");
        exit(EXIT_SUCCESS);
    }
    if (ac != 2) {
        my_puterror("Invalid number arguments\n");
        exit(EXIT_ERROR);
    }
    return EXIT_SUCCESS;
}

int mainecoplus(char *buff, soko_t *soko)
{
    soko->map = spliter(buff, '\n', 0);
    int a = 0;

    map_checker(soko);
    a = init(soko);
    free(buff);
    free(soko->avdeun);
    free(soko->i);
    free(soko->j);
    my_freeter(soko->map);
    return a;
}

void sig_handler(int signum)
{
    if (signum == SIGINT) {
        endwin();
        exit (0);
    }
}

int main(int ac, char **av)
{
    char *buff;
    soko_t soko;

    help(ac, av);
    signal(SIGINT, sig_handler);
    buff = open_file(av[1]);
    soko.avdeun = my_strdup(av[1]);
    if (buff == NULL)
        return EXIT_ERROR;
    return mainecoplus(buff, &soko);
}