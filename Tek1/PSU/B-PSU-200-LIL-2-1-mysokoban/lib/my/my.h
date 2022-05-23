/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-mysokoban
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#define EXIT_ERROR 84

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
#include <ncurses.h>
#include <fcntl.h>
#include <string.h>
#include <ncurses.h>

// Lib /lib/my
void my_putchar(char c);
void my_puterror(char *str);
void my_putstr(char *str);
int my_atoi(char *av);
int my_getnbr(char *str);
int my_getnbr2(char *str, int i);
int my_strlen(char *str);
int check_spliter(char *str, char split);
int my_put_nbr(int x);
char *my_int_to_str(int nb);
char **str_filler(char **spliter, char *str, char split, int i);
char **spliter(char *str, char split, int i);
char *my_strdup(char *src);
void my_freeter(char **spliter);

#endif /* !MY_H_ */
