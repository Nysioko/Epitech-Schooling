/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** cd
*/

#include "sh.h"

void cd_cmd2(sh_t *sh, char *dir, char *path)
{
    if (chdir(sh->str) != -1);
    else if (chdir(path) != -1);
    else
        cd_error(sh, dir);
}

char **cd_cmd(sh_t *sh)
{
    char *cd;
    char *path;
    char *path2;
    char *dir = sh->args[1];

    cd = getcwd(NULL, 500);
    if (cd == NULL)
        exit(84);
    path2 = insert_str(cd, "/", my_strlen(cd));
    if (path2 == NULL)
        exit(84);
    path = my_strcat(path2, dir);
    if (path == NULL)
        exit(84);
    cd_cmd2(sh, dir, path);
    free(path);
    free(path2);
    free(cd);
    return (sh->env);
}

char **add_oldpwd(sh_t *sh, char *oldpwd, char *path)
{
    char *cat = my_strcat("OLDPWD ", oldpwd);
    char *cat2;
    char *cat3;
    char *tmp = sh->str;

    if (cat == NULL)
        exit(84);
    cat2 = my_strcat("setenv OLDPWD \"", oldpwd);
    if (cat2 == NULL)
        exit(84);
    cat3 = my_strcat(cat2, "\"");
    if (cat3 == NULL)
        exit(84);
    sh->str = cat3;
    setenv_cmd(sh, path);
    sh->str = tmp;
    free(cat);
    free(cat2);
    free(cat3);
    return sh->env;
}

char **pre_cd2(sh_t *sh, char *home, char *pwd, char *path)
{
    char *newpwd = getcwd(NULL, 500);

    if (newpwd == NULL)
        exit(84);
    if (home != NULL)
        free(home);
    if (!my_alpcmp(newpwd, pwd))
        sh->env = add_oldpwd(sh, pwd, path);
    free(pwd);
    free(newpwd);
    return sh->env;
}

void pre_cd(sh_t *sh, char *path)
{
    char *home = my_getenv("HOME", sh->env);
    char *oldpwd;
    char *pwd = getcwd(NULL, 500);

    if (pwd == NULL)
        exit(84);
    if ((sh->args[1] == NULL || my_alpcmp(sh->args[1], "") ||
    my_alpcmp(sh->args[1], " ") || my_alpcmp(sh->args[1], "~")) && home != NULL)
        chdir(home);
    else if (my_alpcmp(sh->args[1], "-")) {
        oldpwd = my_getenv("OLDPWD", sh->env);
        go_oldpwd(oldpwd, sh);
    } else
        cd_cmd(sh);
    pre_cd2(sh, home, pwd, path);
}