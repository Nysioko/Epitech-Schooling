/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** sh
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <termios.h>
#include <dirent.h>

#define LEFT_CURS (char[4]){27, 91, 68, 0}
#define RIGHT_CURS (char[4]){27, 91, 67, 0}

typedef struct linked_s {
    char *alias;
    char *func;
    struct linked_s *next;
    struct linked_s *prev;
} linked_t;

typedef struct sh_s {
    char **env;
    char **args;
    char *str;
    char **mult;
    char *save_path;
    int status;
    int *old_pipe;
    int *new_pipe;
    bool quit;
    bool left;
    bool right;
    bool pipe;
    bool display;
    pid_t pid;
    linked_t *alias;
    linked_t *history;
    linked_t *history_tmp;
    struct termios old_term;
    struct termios new_term;
} sh_t;

char *filter_str(char *str);
char *my_getenv(char *name, char **env);
void pre_cd(sh_t *sh, char *path);
void setenv_cmd(sh_t *sh, char *path);
void unsetenv_cmd(sh_t *sh, char *path);
void other_cmd(sh_t *sh);
int exit_child(sh_t *sh);
void cat_path(char **path_str, char *name, char **path, int i);
int need_place_to_free(char *envi, char **path, int status);
void sig_handler(int signum);
void sig_handler2(int signum);
void sig_handler3(int signum);
char **cmd_handler(sh_t *sh);
char **add_env2(char **spl, char **env, char **tmp, int i);
void cd_error(sh_t *sh, char *dir);
void check_special_char(sh_t *sh);
void simple_right(sh_t *sh, int i);
void double_right(sh_t *sh, int i);
int *new_pipe(void);
int manage_redirection_right(sh_t *sh, char *str);
void manage_builtins(sh_t *sh, char *str);
char *get_file(char *str, int i, int j);
char *left(char *str, sh_t *sh);
void display_prompt(int status);
char *double_left(char *str, int i);
void remove_all_nodes(linked_t *elem, linked_t *history);
void remove_node(linked_t **elem, int pos);
int linked_len(linked_t *elem);
void link_node(linked_t **elem, linked_t *new);
linked_t *new_node(void);
void aliases(sh_t *sh, char *path);
char *replace_aliases(char *str, sh_t *sh);
void exit_cmd(sh_t *sh, char *path);
bool is_the_alias(char *str, char *str2);
char *echo_cmd(char *str, int status);
char *get_branch(void);
void ftc_true(sh_t *sh, char *path);
void ftc_false(sh_t *sh, char *path);
void exit_cmd(sh_t *sh, char *path);
void create_ls_alias(sh_t *sh);
void suppr_function(char **buff, char **tmp, int *i);
void delete_char(char **buff, int *i, char **tmp);
char *my_getline(sh_t *sh);
void manage_special(int *i, char **buff, char **tmp, sh_t *sh);
void manage_buffers(char **tmp, char **buff);
void reset_termios(struct termios *old);
void init_termios(struct termios *old, struct termios *new);
void manage_history(int **ci, char **tmp, char **buff, sh_t *sh);
bool null_command(char **spl);
void clear_input(int *c, char **buff);
char **finder(char *arg, char *path);
void completion(char **tmp, int *i, char **buff, sh_t *sh);
void exec_first_and(sh_t *sh, char *str);
void exec_first_or(sh_t *sh, char *str);
bool check_if_separators(sh_t *sh, char *str);
void main_loop3(sh_t *sh, char *str);
int check_if_bool(sh_t *sh, char *command, int i);
void go_oldpwd(char *oldpwd, sh_t *sh);
char *globbing(char *str);