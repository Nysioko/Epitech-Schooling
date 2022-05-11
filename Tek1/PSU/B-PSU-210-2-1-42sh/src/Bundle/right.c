/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** right
*/

#include "sh.h"

char *get_file(char *str, int i, int j)
{
    char *extracted = extract_str(str, i, j, '\0');
    char *formatted;

    if (!extracted)
        exit(84);
    formatted = filter_str(extracted);
    if (!formatted)
        exit(84);
    free(extracted);
    return formatted;
}

void redir_right(sh_t *sh, char *func, char *file, int flag)
{
    int fd = open(file, O_CREAT | O_RDWR | flag, 0664);
    char *tmp = my_strdup(sh->str);
    int tmp_stdin;

    if (!tmp)
        exit(84);
    free(sh->str);
    free_charss(sh->args);
    sh->args = split(func, " ", 0);
    tmp_stdin = dup(1);
    dup2(fd, 1);
    sh->str = func;
    if (!sh->args)
        exit(84);
    cmd_handler(sh);
    free(file);
    sh->str = tmp;
    dup2(tmp_stdin, 1);
    close(fd);
}

void simple_right(sh_t *sh, int i)
{
    int a;
    int b;
    int j;
    char *formatted;
    char *file;

    for (b = i - 1; b > 0 && sh->str[b] == '>'; b--);
    for (a = b; a >= 0 && sh->str[a] != '|' && sh->str[a] != '<'; a--);
    formatted = get_file(sh->str, a, b);
    for (j = i; sh->str[j] != '|' && sh->str[j] != '<' &&
    sh->str[j] != '>' && sh->str[j] != '\0'; j++);
    file = get_file(sh->str, i, j);
    if (formatted[0] == '\0' || file[0] == '\0') {
        free(formatted);
        free(file);
        write(2, "Missing name for redirect.\n", 27);
        sh->status = 84;
        return;
    }
    redir_right(sh, formatted, file, O_TRUNC);
}

void double_right(sh_t *sh, int i)
{
    int a;
    int b;
    int j;
    char *formatted;
    char *file;

    for (b = i - 1; b > 0 && sh->str[b] == '>'; b--);
    for (a = b; a >= 0 && sh->str[a] != '|' && sh->str[a] != '<'; a--);
    formatted = get_file(sh->str, a, b);
    for (j = i; sh->str[j] != '|' && sh->str[j] != '<' &&
    sh->str[j] != '>' && sh->str[j] != '\0'; j++);
    file = get_file(sh->str, i, j);
    if (formatted[0] == '\0' || file[0] == '\0') {
        free(formatted);
        free(file);
        write(2, "Missing name for redirect.\n", 27);
        sh->status = 84;
        return;
    }
    redir_right(sh, formatted, file, O_APPEND);
}

int manage_redirection_right(sh_t *sh, char *str)
{
    int i = 0;
    int a;

    for (i = 0; str[i] != '\0'; i++) {
        for (a = 0; str[i] == '>'; i++, a++);
        if (a == 1) {
            sh->str = str;
            simple_right(sh, i);
            return sh->status;
        } else if (a == 2) {
            sh->str = str;
            double_right(sh, i);
            return sh->status;
        }
        if (a > 2) {
            write(2, "Missing name for redirect.\n", 27);
            sh->status = 84;
            return sh->status;
        }
    }
    return sh->status;
}