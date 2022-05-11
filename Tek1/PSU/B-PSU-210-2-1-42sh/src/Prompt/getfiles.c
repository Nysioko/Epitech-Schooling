/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** getfiles
*/

#include "sh.h"

static char **ifferbelike(char *str)
{
    char **tab = split(str, "\n", 0);
    return tab;
}

static void iffer(char **str, char *dname)
{
    char *new = malloc(sizeof(char) *
    (my_strlen((*str)) + my_strlen(dname) + 2));

    strcpy(new, (*str));
    if (strcmp((*str), "") != 0)
        strcat(new, "\n");
    strcat(new, dname);
    free((*str));
    (*str) = new;
}

bool save_or_not(char *str, char *str2)
{
    int i = 0;

    for (; (str[i] == str2[i] || str[i] + 32 == str2[i] ||
    str[i] - 32 == str2[i]) && str2[i] != '\0'; i++);
    if (str[i] == '\0')
        return true;
    return false;
}

char **finder(char *arg, char *path)
{
    DIR *directory;
    struct dirent *dir;
    char *str = malloc(sizeof(char) * 1);

    str[0] = '\0';
    directory = opendir(path);
    if (directory) {
        while ((dir = readdir(directory)) != NULL) {
            if (save_or_not(arg, dir->d_name))
                iffer(&str, strdup(dir->d_name));
        }
        closedir(directory);
    }
    return ifferbelike(str);
}