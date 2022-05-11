/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** prompt2
*/

#include "sh.h"

char *get_branch3(char *str, struct stat si, int fd)
{
    char *str2;
    int i;

    str = malloc(sizeof(char) * (si.st_size + 2));
    if (!str) {
        close(fd);
        exit(84);
    }
    read(fd, str, si.st_size);
    close(fd);
    str[si.st_size - 1] = '\0';
    for (i = my_strlen(str); str[i] != '/'; i--);
    str2 = my_strdup(&str[i + 1]);
    free(str);
    if (!str2)
        exit(84);
    return str2;
}

char *get_branch2(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat si;
    char *str = NULL;

    if (fd == -1 || stat(path, &si) == -1) {
        str = my_strdup("");
        if (!str)
            exit(84);
        if (fd != -1)
            close(fd);
        return str;
    }
    return get_branch3(str, si, fd);
}

void get_current(char **tmp, char **str)
{
    (*tmp) = my_strdup(".git/HEAD");
    if (!(*tmp))
        exit(84);
    free((*str));
    (*str) = get_branch2((*tmp));
    free((*tmp));
}

static void coding_style(char *str, char **cwd, char **tmp2)
{
    if (!str)
        exit(84);
    (*cwd) = getcwd(NULL, 500);
    if (!(*cwd))
        exit(84);
    (*tmp2) = getcwd(NULL, 500);
    if (!(*tmp2))
        exit(84);
}

char *get_branch(void)
{
    char *str = my_strdup("");
    char *cwd;
    char *tmp;
    char *tmp_cwd;

    coding_style(str, &cwd, &tmp_cwd);
    for (int i = 0; !my_alpcmp(cwd, "/") && my_alpcmp(str, ""); i++) {
        get_current(&tmp, &str);
        if (chdir("../") == -1)
            break;
        free(cwd);
        cwd = getcwd(NULL, 500);
        if (!cwd)
            exit(84);
    }
    free(cwd);
    chdir(tmp_cwd);
    free(tmp_cwd);
    return str;
}