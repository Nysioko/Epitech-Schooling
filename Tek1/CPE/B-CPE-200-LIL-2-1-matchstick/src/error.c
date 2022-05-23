/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-matchstick
** File description:
** error
*/

#include "../include/matchstick.h"

int errors2(char **av)
{
    if (my_getnbr(av[1]) >= 100 || my_getnbr(av[1]) <= 1) {
        my_puterror("{Error 84.}: The first argument must "
        "be between 1 and 100.\n");
        return EXIT_ERROR;
    }
    if (my_getnbr(av[2]) < 1) {
        my_puterror("{Error 84.}: The second argument"
        " must be greater than 0.\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int errors(int ac, char **av)
{
    if (ac != 3) {
        my_puterror("{Error 84.}: The number of arguments must be equal "
        "to 3\n");
        return EXIT_ERROR;
    }
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] < '0' || av[1][i] > '9') {
            my_puterror("{Error 84.}: The first argument given are not numbers"
            ", or it's negative\n");
            return EXIT_ERROR;
        }
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] < '0' || av[2][i] > '9') {
            my_puterror("{Error 84.}: The second argument given is not a "
            "number, or it's negative\n");
            return EXIT_ERROR;
        }
    }
    return errors2(av);
}