/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** path
*/

#include "my.h"

int path2(char **mall, char **path_cmd, int i, char *exec)
{
    struct stat strucstat;

    (*mall) = malloc(sizeof(char) * (my_strlen(path_cmd[i])
    + my_strlen(exec) + 2));
    if (*mall == NULL)
        exit(EXIT_ERROR);
    my_strcpy((*mall), path_cmd[i]);
    my_strcat((*mall), "/");
    my_strcat((*mall), exec);
    if (stat((*mall), &strucstat) != -1)
        return EXIT_FAILURE;
    free((*mall));
    return EXIT_SUCCESS;
}

int path(char **env, char *str, char *exec)
{
    int i = 0;
    char *genv = my_getenv(env, "PATH");
    char *mall;
    char **path_cmd;

    if (genv == NULL)
        return 12;
    path_cmd = spliter(genv, ':' , 0);
    while (path_cmd[i] != NULL) {
        if (path2(&mall, path_cmd, i, exec) == EXIT_FAILURE) {
            perm(env, str, mall, exec);
            free(genv);
            freetab(path_cmd);
            return EXIT_SUCCESS;
        }
        i++;
    }
    freetab(path_cmd);
    free(genv);
    return EXIT_ERROR;
}