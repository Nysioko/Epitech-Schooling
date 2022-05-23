/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse
*/

void my_otherswap(char *a, char *b)
{
    char c;

    c = *b;
    *b = *a;
    *a = c;
}

char *my_revstr(char *str)
{
    int i = 0;
    int d;
    int e = 0;

    while (str[i] != '\0') {
        i++;
    }
    d = i/2;
    i--;
    while (e != d) {
        my_otherswap(&str[e], &str[i]);
        e++;
        i--;
    }
    return (str);
}
