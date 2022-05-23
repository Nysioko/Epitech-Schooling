/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban
** File description:
** map_checker
*/

#include "my_sokoban.h"
#include "my.h"

void oprint(soko_t *soko)
{
    int i = 0;

    while (i != soko->end) {
        if (soko->map[soko->i[i]][soko->j[i]] != 'P' &&
        soko->map[soko->i[i]][soko->j[i]] != 'O' &&
        soko->map[soko->i[i]][soko->j[i]] != 'X')
            soko->map[soko->i[i]][soko->j[i]] = 'O';
        i++;
    }
}

void automalloc(soko_t *soko, int k)
{
    int loop = 0;
    int loop2 = 0;
    int c = 0;
    soko->i = malloc(sizeof(int) * k);
    soko->j = malloc(sizeof(int) * k);

    while (soko->map[loop] != NULL) {
        loop2 = 0;
        while (soko->map[loop][loop2] != '\0') {
            soko->map[loop][loop2] == 'O' ? soko->j[c] = loop2 :
            soko->map[loop][loop2];
            soko->map[loop][loop2] == 'O' ? soko->i[c] = loop :
            soko->map[loop][loop2];
            soko->map[loop][loop2] == 'O' ? c++ : soko->map[loop][loop2];
            loop2 += 1;
        }
        loop++;
    }
    soko->end = c;
}

int map_looper(soko_t *soko)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (soko->map[i] != NULL) {
        j = 0;
        while (soko->map[i][j] != '\0') {
            soko->map[i][j] == 'O' ? k++ : soko->map[i][j];
            j++;
        }
        i++;
    }
    automalloc(soko, k);
    return EXIT_SUCCESS;
}

int map_checker(soko_t *soko)
{
    int x = 0;
    int y = 0;
    int z = 0;

    for (int i = 0; soko->map[i] != NULL; i++) {
        for (int j = 0; soko->map[i][j] != '\0'; j++) {
            soko->map[i][j] != 'P'
            && soko->map[i][j] != 'X' && soko->map[i][j] != 'O'
            && soko->map[i][j] != '#' &&
            soko->map[i][j] != ' ' ? exit(84) : soko->map[i][j];
            soko->map[i][j] == 'P' ? x++ : x;
            soko->map[i][j] == 'X' ? y++ : y;
            soko->map[i][j] == 'O' ? z++ : z;
        }
    }
    if (x != 1 || y != z || y == 0) {
        my_puterror("Error");
        exit(84);
    }
    return map_looper(soko);
}