/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_

#include "my.h"

// Struct
typedef struct sfvector2i_s {
    int i;
    int j;
}sfvector2i_t;

typedef struct soko_s {
    char **map;
    char *avdeun;
    int *i;
    int *j;
    int px;
    int py;
    int end;
}soko_t;

// Sokoban Functions /src/
int help(int ac, char **av);
char *open_file2(struct stat stat_buff, char *buff, int fr, int fd);
void print_map(soko_t *soko);
char *open_file(char const *filepath);
int map_checker(soko_t *soko);
int init(soko_t *soko);
int check_cooplay(soko_t *soko);
void to_up(soko_t *soko);
void to_left(soko_t *soko);
void to_right(soko_t *soko);
void to_down(soko_t *soko);
void print_map(soko_t *soko);
void move_player(soko_t *soko, int i, int j);
int move_checker(soko_t *soko, int i, int j);
void oprint(soko_t *soko);
void automalloc(soko_t *soko, int k);
int map_looper(soko_t *soko);
int winning(soko_t *soko);
int losing(soko_t *soko);

#endif /* !MY_SOKOBAN_H_ */
