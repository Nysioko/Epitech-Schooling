/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-matchstick
** File description:
** main
*/

#include "../include/matchstick.h"

int gameloop(matchstick_t *match)
{
    if (player_move(match) == EXIT_ERROR)
        return EXIT_SUCCESS;
    my_putcharstarstar(match->map);
    if (youlose(match) == EXIT_SUCCESS)
        return 2;
    iaecoplusdevparuntek1(match);
    my_putcharstarstar(match->map);
    if (youlose(match) == EXIT_SUCCESS)
        return EXIT_FAILURE;
    return gameloop(match);
}

int ninite(matchstick_t *match)
{
    int tnul;
    my_putcharstarstar(match->map);
    tnul = gameloop(match);
    if (tnul == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    else if (tnul == 2)
        my_putstr("You lost, too bad...\n");
    my_freeter(match->map);
    return tnul;
}

int main(int ac, char **av)
{
    matchstick_t match;
    if (errors(ac, av) == EXIT_ERROR)
        return EXIT_ERROR;
    match.i = my_getnbr(av[1]);
    match.j = my_getnbr(av[2]);
    map_space_filler(av, &match);
    return ninite(&match);
}