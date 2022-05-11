/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** my_getline
*/

#include "sh.h"

void init_termios(struct termios *old, struct termios *new)
{
    tcgetattr(0, old);
    (*new) = (*old);
    (*new).c_lflag = 35377;
    tcsetattr(0, TCSANOW, new);
}

void reset_termios(struct termios *old)
{
    tcsetattr(0, TCSANOW, old);
}

void display_current_prompt(char *buff, int i)
{
    for (int a = i; a > 0; a--)
        write(0, LEFT_CURS, 3);
    write(0, buff, my_strlen(buff));
    for (int a = my_strlen(buff); a != i; a--)
        write(0, LEFT_CURS, 3);
}

static void iffer(char **tmp, int **ci, char **buff, sh_t *sh)
{
    if (((*ci[0]) >= 32 && (*ci[0]) <= 126)) {
        (*tmp) = insert_str((*buff), (char *)ci[0], (*ci[1]));
        return manage_buffers(tmp, buff);
    }
    if ((*ci[0]) == 27)
        return manage_special(ci[1], buff, tmp, sh);
    if ((*ci[0]) == 127)
        return delete_char(buff, ci[1], tmp);
    if ((*ci[0]) == 9)
        return completion(tmp, ci[1], buff, sh);
    (*ci[1])--;
}

char *my_getline(sh_t *sh)
{
    int c = 0;
    int i;
    char *buff = my_strdup("");
    char *tmp;

    !buff ? exit(84) : buff;
    for (i = 0; (char)c != '\n'; i++, write(0, RIGHT_CURS, 3)) {
        i = i > my_strlen(buff) ? my_strlen(buff) : i;
        display_current_prompt(buff, i);
        c = getchar();
        if (c == 4 || c == -1) {
            free(buff);
            return NULL;
        }
        iffer(&tmp, (int *[2]){&c, &i}, &buff, sh);
    }
    tmp = insert_str(buff, "\n", my_strlen(buff));
    manage_buffers(&tmp, &buff);
    write(0, "\n", 1);
    return buff;
}