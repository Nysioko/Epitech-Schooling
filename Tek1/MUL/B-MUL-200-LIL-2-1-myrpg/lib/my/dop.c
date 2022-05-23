/*
** EPITECH PROJECT, 2020
** do-op
** File description:
** calculator i guess
*/

#include "my.h"
#include <stdlib.h>

int do_op3(int i, char c, int x, int nb)
{
    if (c == '%') {
        if (x == 0) {
            my_putstr("Stop : modulo by zero\n");
            return (84);
        } else {
            nb = i % x;
            return (nb);
        }
    }
    return (nb);
}

int do_op2(int i, char c, int x, int nb)
{
    nb = 0;

    if (c == '/' && x == 0) {
        my_putstr("Stop: division by zero\n");
        return (84);
    }
    if (c == '/') {
        nb = i / x;
        return (nb);
    }
    return (do_op3(i, c, x, nb));
}

int do_op1(int i, char c, int x)
{
    int nb = 0;

    if (c == '+') {
        nb = i + x;
        return (nb);
    }
    if (c == '-') {
        nb = i - x;
        return (nb);
    }
    if (c == '*') {
        nb = i * x;
        return (nb);
    }
    return (do_op2(i, c, x, nb));
}

int do_op(int i, char c, int x)
{
    return (do_op1(i, c, x));
}