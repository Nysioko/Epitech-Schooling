/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** manage_special_char
*/

#include "sh.h"

void manage_buffers(char **tmp, char **buff)
{
    if (!(*tmp))
        exit(84);
    free((*buff));
    (*buff) = (*tmp);
}

void manage_arrows3(char c, int *i, char **buff, char **tmp)
{
    char c2;

    if (c == 67)
        return;
    if (c == 70) {
        for (int a = (*i); a < my_strlen((*buff)) - 1; a++)
            write(0, RIGHT_CURS, 3);
        (*i) == my_strlen((*buff)) ? write(0, LEFT_CURS, 3) : 0;
        (*i) = my_strlen((*buff)) - 1;
        return;
    }
    if (c == 51) {
        c2 = getchar();
        if (c2 == 126)
            return suppr_function(buff, tmp, i);
    }
    (*i)--;
}

void manage_arrows2(int *i, char **buff, char c, char **tmp)
{
    if (c == 67 && (*i) == my_strlen((*buff))) {
        (*i)--;
        write(0, LEFT_CURS, 3);
        return;
    }
    if (c == 68) {
        if ((*i) != 0)
            write(0, LEFT_CURS, 3);
        (*i) = (*i) == 0 ? -1 : (*i) - 2;
        write(0, LEFT_CURS, 3);
        return;
    }
    if (c == 72) {
        for (int a = (*i); a > -1; a--)
            write(0, LEFT_CURS, 3);
        (*i) = -1;
        return;
    }
    manage_arrows3(c, i, buff, tmp);
}

void manage_arrows(int *i, char **buff, char **tmp, sh_t *sh)
{
    char c = getchar();

    if (c == 65 || c == 66)
        return manage_history((int *[2]){(int *)&c, i}, tmp, buff, sh);
    manage_arrows2(i, buff, c, tmp);
}

void manage_special(int *i, char **buff, char **tmp, sh_t *sh)
{
    char c = getchar();

    if (c == 91)
        return manage_arrows(i, buff, tmp, sh);
    (*i)--;
}