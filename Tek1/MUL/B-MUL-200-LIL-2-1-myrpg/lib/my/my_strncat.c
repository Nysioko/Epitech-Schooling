/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** strncat
*/

char *my_strncat(char *dest, char const *src, int n)
{
    int i;
    int f;

    for (i = 0; dest[i] != '\0'; i++);
    n = i + n;
    for (f = 0; src[f] != dest[n + 1]; f++) {
        dest[i] = src[f];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
