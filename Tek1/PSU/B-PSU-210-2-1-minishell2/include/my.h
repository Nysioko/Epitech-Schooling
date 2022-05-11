/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-minishell1
** File description:
** minishell
*/

// Include
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>

// Lib /lib/my/
void my_putchar(char c);
void my_putstr(char *str);
void my_puterror(char *str);
void my_swap(int *x, int *y);
void freetab(char **spliter);
int my_strlen(char *str);
int my_getnbr(char *str);
int my_putnbr(int nbr);
int my_atoi(char *av);
int check_spliter(char *str, char split);
char *my_strdup(char *src);
char *my_strcpy(char *dest, char *src);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *dest, char *src);
char *clean_str(char *src, char del);
char **spliter(char *str, char split, int i);
char **str_filler(char **spliter, char *str, char split, int i);
int my_tablen(char **tab);
void my_putcharstarstar(char **tablo);

// Struct

typedef struct mysh_s {
    char **env;
    char *str;
    int *old;
    int *new;
} mysh_t;

// MiniShell Functions
void signal_handler(int i);
char **cd(char **env, char *str, bool see);
void cd_error(char *str, bool see);
void cd2(char *str, char *str_getenv, char *old_pwd);
void modif_env(char **env, char **envsplit, int i);
void signal_handler(int i);
void init(char **env, char *str);
void signal_handler2(int i);
void execution(char **env, char *str, char *exec);
int execution_ext(pid_t pad, char **env, char **cmdstore, char *exec);
int perm(char **env, char *str, char *path, char *exec);
int dir(char **env, char *str, char *exec);
int segfault(int status);
int path(char **env, char *str, char *exec);
char *my_getenv(char **env, char *name);
char *clear_arg(char *str);
char **create_setenv(char **env, char *str, bool see);
char **create_unsetenv(char **env, char *str, bool see);
char **pip(char **env, char *str);
char **user_command2(char **env, char *str, bool see);
int redirection(mysh_t *mysh);


// Macros
#define EXIT_ERROR 84