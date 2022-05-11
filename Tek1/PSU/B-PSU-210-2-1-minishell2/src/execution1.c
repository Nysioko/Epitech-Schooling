/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** execution1
*/

#include "../include/my.h"

void execution(char **env, char *str, char *exec)
{
    char **cmdstore = spliter(str, ' ', 0);
    pid_t pad = getpid();
    pad = fork();

    execution_ext(pad, env, cmdstore, exec);
    freetab(cmdstore);
}

int perm(char **env, char *str, char *path, char *exec)
{
    struct stat permstruct;

    if (stat(path, &permstruct) == -1 || access(path, X_OK) != 0 ||
    S_ISDIR(permstruct.st_mode)) {
        my_puterror(exec);
        my_puterror(": Permission denied.\n");
        return EXIT_SUCCESS;
    } else
        execution(env, str, path);
    return EXIT_SUCCESS;
}

void init2(char **argcmd, char *pwdsave, char **env, char *str)
{
    char *mall = malloc(sizeof(char) * (my_strlen(argcmd[0]) +
    my_strlen(pwdsave) + 2));

    if (mall == NULL)
        exit(EXIT_ERROR);
    my_strcpy(mall, pwdsave);
    my_strcat(mall, "/");
    my_strcat(mall, argcmd[0]);
    perm(env, str, mall, argcmd[0]);
    free(mall);
}

void init(char **env, char *str)
{
    char **argcmd = spliter(str, ' ', 0);
    char *pwdsave;
    struct stat structstat;

    if (!argcmd)
        exit(EXIT_ERROR);
    pwdsave = getcwd(NULL, 4096);
    if (!pwdsave)
        exit(EXIT_ERROR);
    if (stat(argcmd[0], &structstat) != -1)
        init2(argcmd, pwdsave, env, str);
    else {
        if (path(env, str, argcmd[0]) == EXIT_ERROR) {
            my_puterror(argcmd[0]);
            my_puterror( ": Command not found.\n");
        }
    }
    free(pwdsave);
    freetab(argcmd);
}