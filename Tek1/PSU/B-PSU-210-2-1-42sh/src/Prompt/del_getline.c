/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_getline3
*/

#include "sh.h"

void delete_char(char **buff, int *i, char **tmp)
{
    if ((*i) <= 0) {
        (*i)--;
        write(0, LEFT_CURS, 3);
        return;
    }
    for (int a = (*i); (*buff)[a] != '\0'; a++)
        write(0, RIGHT_CURS, 3);
    write(0, LEFT_CURS, 3);
    write(0, " ", 1);
    write(0, LEFT_CURS, 3);
    for (int a = my_strlen((*buff)); a >= (*i); a--)
        write(0, LEFT_CURS, 3);
    (*tmp) = remove_char((*buff), (*i) - 1);
    if (!(*tmp))
        exit(84);
    (*i) -= 2;
    manage_buffers(tmp, buff);
}

void suppr_function(char **buff, char **tmp, int *i)
{
    if ((*i) >= my_strlen((*buff))) {
        (*i)--;
        write(0, LEFT_CURS, 3);
        return;
    }
    for (int a = (*i); (*buff)[a] != '\0'; a++)
        write(0, RIGHT_CURS, 3);
    write(0, LEFT_CURS, 3);
    write(0, " ", 1);
    for (int a = my_strlen((*buff)); a >= (*i); a--)
        write(0, LEFT_CURS, 3);
    (*tmp) = remove_char((*buff), (*i));
    if (!(*tmp))
        exit(84);
    (*i)--;
    manage_buffers(tmp, buff);
}