/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** string length
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
