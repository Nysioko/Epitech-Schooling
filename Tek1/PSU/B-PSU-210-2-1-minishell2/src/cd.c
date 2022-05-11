/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** cd
*/

#include "my.h"

void iffer2(char *str, bool see)
{
    struct stat structstat;

    if (stat(&str[3], &structstat) == -1) {
        my_puterror(str);
        my_puterror(": No such file or directory.\n");
    } else if (!(S_ISDIR(structstat.st_mode)) && see) {
        my_puterror(str);
        my_puterror(": Not a directory.\n");
    } else
        chdir(&str[3]);
}

void iffer3(char *str_getenv, char *old_pwd)
{
    if (str_getenv != NULL)
        free(str_getenv);
    if (old_pwd != NULL)
        free(old_pwd);
}

char **iffer(char *str_getenv, char **env, char **tmp, bool see)
{
    char *strrr;

    if (tmp[0] == NULL)
        exit(EXIT_ERROR);
    strrr = malloc(sizeof(char) * (my_strlen(tmp[0]) + 18));
    if (strrr == NULL)
        exit(EXIT_ERROR);
    strrr[0] = '\0';
    my_strcat(strrr, "setenv OLDPWD ");
    my_strcat(strrr, tmp[0]);
    env = create_setenv(env, strrr, see);
    iffer3(str_getenv, tmp[1]);
    free(tmp[0]);
    free(strrr);
    return env;
}

char **cd(char **env, char *str, bool see)
{
    char *str_getenv = my_getenv(env, "HOME");
    char *old_pwd = my_getenv(env, "OLDPWD");
    char *pwd = getcwd(NULL, 19012002);
    char **tmp;

    if (!pwd)
        exit(84);
    tmp = (char *[3]) {pwd, old_pwd, NULL};
    if ((str[2] == '\0' || my_strcmp("cd ~", str) == 0) && str_getenv != NULL)
        chdir(str_getenv);
    else if (my_strcmp("cd -", str) == 0 && old_pwd != NULL)
        chdir(old_pwd);
    else
        iffer2(str, see);
    return iffer(str_getenv, env, tmp, see);
}