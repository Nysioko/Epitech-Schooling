/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** calculer la taille d'une string
*/

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}
