/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** inverser une string
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
    int moitier_string;
    int compteur = 0;
    while (str[i] != '\0') {
        i++;
    }
    i--;
    moitier_string = i/2 + 1;
    while (compteur != moitier_string) {
        my_otherswap(&str[compteur], &str[i]);
        compteur++;
        i--;
    }
    return (str);
}
