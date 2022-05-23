/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-matchstick
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_
#define EXIT_ERROR 84

// Include
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Structure

typedef struct matchstick_s {
    int i;
    int j;
    char **map;
} matchstick_t;

// Lib
void my_putstr(char *str);
void my_putchar(char c);
void my_puterror(char  *str);
int my_getnbr(char const *str);
int my_getnbr2(char const *str, int i);
int my_strlen(char *str);
void my_freeter(char **spliter);
void my_putcharstarstar(char **tablo);
int my_putnbr(int nbr);

// Functions
int errors(int ac, char **av);
void map_space_filler(char **av, matchstick_t *match);
int player_line(matchstick_t *match);
int youlose(matchstick_t *match);
int map_reader(matchstick_t *match, int o);
void remove_stick(matchstick_t *match, int o, int nb, int bool);
int function1(matchstick_t *match, int o, int nb);
int player_move(matchstick_t *match);
void iaecoplusdevparuntek1(matchstick_t *match);

#endif /* !MATCHSTICK_H_ */
