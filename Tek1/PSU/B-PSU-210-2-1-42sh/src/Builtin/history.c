/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** history
*/

#include "sh.h"

void clear_input(int *c, char **buff)
{
    for (int i = (*c); i < my_strlen((*buff)); i++)
        write(0, RIGHT_CURS, 3);
    for (int i = my_strlen((*buff)); i > 0; i--) {
        write(0, " ", 1);
        write(0, LEFT_CURS, 3);
        write(0, LEFT_CURS, 3);
    }
}

void manage_history2(int **ci, char **tmp, char **buff, sh_t *sh)
{
    if ((char)(*ci[0]) == 66 && sh->history != NULL) {
        if (sh->history_tmp == NULL)
            sh->history_tmp = sh->history->prev;
        else
            sh->history_tmp = sh->history_tmp->next == NULL ?
            sh->history_tmp : sh->history_tmp->next;
        (*tmp) = my_strdup(sh->history_tmp->func);
        if (!(*tmp))
            exit(84);
        clear_input(ci[1], buff);
        for (int i = 0; i + 1 < my_strlen(sh->history_tmp->func); i++)
            write(0, RIGHT_CURS, 3);
        (*ci[1]) = my_strlen(sh->history_tmp->func);
        return manage_buffers(tmp, buff);
    }
    (*ci[1])--;
}

void manage_history(int **ci, char **tmp, char **buff, sh_t *sh)
{
    if ((char)(*ci[0]) == 65 && sh->history != NULL) {
        if (sh->history_tmp == NULL)
            sh->history_tmp = sh->history->prev;
        else
            sh->history_tmp = sh->history_tmp->prev->next == NULL ?
            sh->history_tmp : sh->history_tmp->prev;
        (*tmp) = my_strdup(sh->history_tmp->func);
        if (!(*tmp))
            exit(84);
        clear_input(ci[1], buff);
        for (int i = 0; i + 1 < my_strlen(sh->history_tmp->func); i++)
            write(0, RIGHT_CURS, 3);
        (*ci[1]) = my_strlen(sh->history_tmp->func);
        return manage_buffers(tmp, buff);
    }
    manage_history2(ci, tmp, buff, sh);
}