/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** setenv
*/

#include "my.h"

char **iffer_add_var(char **envsplit, char **env, int i, char **new_env)
{
    if (envsplit[2] != NULL) {
        new_env[i] = malloc(sizeof(char) * (my_strlen(envsplit[1]) + 2 +
        my_strlen(envsplit[2])));
        if (new_env[i] == NULL)
            exit(84);
    } else {
        new_env[i] = malloc(sizeof(char) * (my_strlen(envsplit[1]) + 2));
        if (new_env[i] == NULL)
            exit(84);
    }
    new_env[i][0] = '\0';
    my_strcat(new_env[i], envsplit[1]);
    my_strcat(new_env[i], "=");
    if (envsplit[2] != NULL)
        my_strcat(new_env[i], envsplit[2]);
    new_env[i + 1] = NULL;
    freetab(env);
    return new_env;
}

char **add_var(char **env, char **envsplit)
{
    char **new_env = malloc(sizeof(char *) * (my_tablen(env) + 2));
    int j = 0;
    int i = 0;

    if (new_env == NULL)
        exit(EXIT_ERROR);
    for (i = 0; env[i] != NULL; i++) {
        new_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 2));
        if (new_env[i] == NULL)
            exit(84);
        for (j = 0; env[i][j] != '\0'; j++)
            new_env[i][j] = env[i][j];
        new_env[i][j] = '\0';
    }
    return iffer_add_var(envsplit, env, i, new_env);
}

char **change_env_var(char **env, char **envsplit, bool see)
{
    if ((envsplit[1][0] >= 'A' && envsplit[1][0] <= 'Z') ||
    (envsplit[1][0] >= 'a' && envsplit[1][0] <= 'z'));
    else {
        see ? my_puterror("setenv: Variable name must begin with a letter\n")
        : see;
        return env;
    }
    return add_var(env, envsplit);
}

char **env_changer(char **env, char **envsplit, bool see)
{
    char *isvarexist = my_getenv(env, envsplit[1]);
    int j = 0;

    if (isvarexist == NULL) {
        free(isvarexist);
        return change_env_var(env, envsplit, see);
    }
    for (int i = 0; env[i] != NULL; i++) {
        for (j = 0; envsplit[1][j] == env[i][j]; j++);
        if (env[i][j] == '=' && envsplit[1][j] == '\0') {
            modif_env(env, envsplit, i);
            break;
        }
    }
    free(isvarexist);
    return env;
}

char **create_setenv(char **env, char *str, bool see)
{
    char **envsplit = spliter(str, ' ', 0);

    if (envsplit == NULL)
        exit(EXIT_ERROR);
    if (my_tablen(envsplit) == 1 && see)
        my_putcharstarstar(env);
    else if (my_tablen(envsplit) == 2 || my_tablen(envsplit) == 3)
        env = env_changer(env, envsplit, see);
    else
        see ? my_puterror("setenv: Too many arguments.\n") : see;
    freetab(envsplit);
    return env;
}