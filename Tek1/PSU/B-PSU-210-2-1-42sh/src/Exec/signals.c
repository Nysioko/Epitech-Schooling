/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-dante
** File description:
** signals2
*/

#include "sh.h"

void sig_handler3(int signum)
{
    if (signum == SIGINT)
        my_printf("");
}

void sig_handler2(int signum)
{
    if (signum == SIGINT)
        my_printf("\n");
}

void sig_handler(int signum)
{
    if (signum == SIGINT) {
        my_putchar('\n');
        display_prompt(1);
    }
}