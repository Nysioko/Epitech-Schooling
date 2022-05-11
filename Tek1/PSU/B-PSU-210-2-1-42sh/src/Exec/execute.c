/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2
** File description:
** execute
*/

#include "sh.h"

int execute_cmd(char *path, char **arg, sh_t *sh)
{
    pid_t pid = getpid();

    pid = fork();
    if (pid == -1)
        exit(84);
    else if (pid == 0) {
        signal(SIGINT, SIG_DFL);
        if (arg == NULL)
            exit(84);
        execve(path, arg, sh->env);
        if (errno == 8)
            my_eprintf("%s: %s\n", sh->args[0],
            "Exec format error. Wrong Architecture.");
        exit(84);
    } else {
        waitpid(pid, &sh->status, WUNTRACED);
        return (exit_child(sh));
    }
    return 0;
}

int access_func(char *path_str, char **args, int *count, sh_t *sh)
{
    struct stat si;

    stat(path_str, &si);
    if (access(path_str, X_OK) == 0 && !(S_ISDIR(si.st_mode)))
        (*count) = execute_cmd(path_str, args, sh);
    else {
        write(2, args[0], my_strlen(args[0]));
        write(2, ": Permission denied.\n", 21);
        (*count) = 1;
        sh->status = 84;
    }
    return (0);
}

int path_fct(sh_t *sh, char **args)
{
    char *envi = my_getenv("PATH", sh->env);
    char **path = split(envi == NULL ? sh->save_path : envi, ":", 0);
    char *path_str = "no more warnings now, uh?";
    struct stat si;
    int count = 0;

    if (path == NULL)
        exit(84);
    for (int i = 0; path[i] != NULL; i++) {
        cat_path(&path_str, sh->args[0], path, i);
        if (stat(path_str, &si) != -1 && !my_alpcmp(path[i], "/"))
            access_func(path_str, args, &count, sh);
        free(path_str);
        if (count != 0)
            return need_place_to_free(envi, path, 0);
    }
    return need_place_to_free(envi, path, 84);
}

void other_cmd(sh_t *sh)
{
    char *str2 = extract_str(sh->args[0], 0, 2, '\0');
    struct stat si;
    char **tmp = split(sh->str, " ", 0);
    int count;

    if (tmp == NULL)
        exit(84);
    if (stat(sh->args[0], &si) == -1) {
        if (my_alpcmp("./", str2) ||
        path_fct(sh, tmp) == 84) {
            write(2, sh->args[0], my_strlen(sh->args[0]));
            write(2, ": Command not found.\n", 21);
            sh->status = 84;
        }
    } else
        access_func(sh->args[0], tmp, &count, sh);
    free(str2);
    free_charss(tmp);
}