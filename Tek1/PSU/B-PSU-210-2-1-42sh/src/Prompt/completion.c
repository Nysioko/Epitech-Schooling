/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** completion
*/

#include "sh.h"

int get_max_equal(char **files)
{
    int max = my_strlen(files[0]);
    int max_tmp;
    char *tmp = NULL;

    for (int i = 1; files[i] != NULL; i++) {
        tmp = files[i - 1];
        for (max_tmp = 0; tmp[max_tmp] == files[i - 1][max_tmp] &&
        tmp[max_tmp] != '\0'; max_tmp++);
        max = max_tmp < max ? max_tmp : max;
    }
    return max;
}

int get_equal_to(char *str, int i)
{
    int a;
    int tmp = i;

    for (a = -1; tmp > 0 && str[tmp] != '/' && str[tmp] != ' '; a++, tmp--);
    return tmp == 0 ? a + 1 : a;
}

void put_completion(char ***tmp_buff, char **files, int status, int *i)
{
    int max = get_max_equal(files);
    char *tmp = extract_str(files[0], 0, max, '\0');

    if (!tmp)
        exit(84);
    (*tmp_buff[0]) = my_strdup((*tmp_buff[1]));
    if (!(*tmp_buff[0]))
        exit(84);
    write(1, "\n", 1);
    for (int a = 0; files[a] != NULL; a++)
        my_printf("%s ", files[a]);
    write(1, "\n", 1);
    display_prompt(status);
    for (int a = 0; a < (*i); a++)
        write(0, RIGHT_CURS, 3);
    free(tmp);
    if ((*i) == 0)
        write(0, LEFT_CURS, 3);
}

char *get_folder(char *str, int i, char **path)
{
    int a;
    int b;
    char *new;

    for (a = i; str[a] != ' ' && a > 0; a--);
    for (b = i; str[b] != ' ' && str[b] != '\0'; b++);
    a = a == 0 ? 0 : a + 1;
    if (a == 0)
        (*path) = my_strdup(".");
    else
        (*path) = my_strdup(".");
    if (!(*path))
        exit(84);
    new = extract_str(str, a, b, '\0');
    return new;
}

void completion(char **tmp, int *i, char **buff, sh_t *sh)
{
    char *path = NULL;
    char *str = get_folder((*buff), (*i), &path);
    char **files = finder(str, path);

    if (my_charsslen(files) == 1) {
        (*tmp) = files[0][0] != '\0' ? insert_str((*buff), &files[0]
        [get_equal_to((*buff), (*i))], (*i)) : my_strdup((*buff));
        if (!(*tmp))
            exit(84);
        (*i) = my_strlen((*tmp));
    } else
        put_completion((char **[2]){tmp, buff}, files, sh->status, i);
    clear_input(i, buff);
    for (int a = 0; a + 1 < my_strlen((*tmp)); a++)
        write(0, RIGHT_CURS, 3);
    manage_buffers(tmp, buff);
    free(path);
    free(str);
}