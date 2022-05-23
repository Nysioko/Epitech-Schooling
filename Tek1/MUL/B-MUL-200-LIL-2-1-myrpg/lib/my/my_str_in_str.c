/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** checking strings
*/

int my_str_in_str(char *str, char const *to_find)
{
    int i = 0;
    int f = 0;

    for (; str[i] != '\0' + 1; i++) {
        if (to_find[f] == '\0')
            return (i - f);
        if (to_find[f] == str[i])
            f++;
        else
            f = 0;
    }
    return (-1);
}
