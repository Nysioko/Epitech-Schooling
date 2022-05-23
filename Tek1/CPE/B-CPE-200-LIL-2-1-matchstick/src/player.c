/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-matchstick
** File description:
** player
*/

#include "../include/matchstick.h"

int matches_checker(matchstick_t *match, int egalamygetnbrdetonstr, char *str)
{
    int c = my_getnbr(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            free(str);
            return player_line(match);
        }
    }
    if (c == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return player_line(match);
    }
    if (c > map_reader(match, egalamygetnbrdetonstr)) {
        my_putstr("Error: not enough matches on this line\n");
        return player_line(match);
    }
    return function1(match, egalamygetnbrdetonstr, c);
}

int player_match(matchstick_t *match, int egalamygetnbrdetonstr)
{
    char *str = NULL;
    size_t size;
    ssize_t ssize;

    my_putstr("Matches: ");
    ssize = getline(&str, &size, stdin);
    if (ssize == -1) {
        free(str);
        return EXIT_ERROR;
    }
    str[my_strlen(str) - 1] = '\0';
    return (matches_checker(match, egalamygetnbrdetonstr, str));
}

int player_checker(matchstick_t *match, char *str)
{
    int egalamygetnbrdetonstr = my_getnbr(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            free(str);
            return player_line(match);
        }
    }
    if (egalamygetnbrdetonstr == 0 || egalamygetnbrdetonstr > match->i) {
        my_putstr("Error: this line is out of range\n");
        free(str);
        return player_line(match);
    }
    free(str);
    return player_match(match, egalamygetnbrdetonstr);
}

int player_line(matchstick_t *match)
{
    char *str = NULL;
    size_t size;
    ssize_t ssize;

    my_putstr("Line: ");
    ssize = getline(&str, &size, stdin);
    if (ssize == -1) {
        free(str);
        return EXIT_ERROR;
    }
    str[my_strlen(str) - 1] = '\0';
    return (player_checker(match, str));
}

int player_move(matchstick_t *match)
{
    my_putstr("\nYour turn:\n");
    if (player_line(match) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}