/*
** EPITECH PROJECT, 2021
** Git
** File description:
** open_file
*/

#include "my.h"
#include "my_sokoban.h"

char *open_file2(struct stat stat_buff, char *buff, int fr, int fd)
{
    buff = malloc(sizeof(char) * stat_buff.st_size + 2);
    fr = read(fd, buff, stat_buff.st_size);
    if (fr == -1 || stat_buff.st_size == 0) {
        my_puterror("Unable to read the file.\n");
        exit(84);
    }
    buff[stat_buff.st_size] = '\0';
    return buff;
}

char *open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int fr = 0;
    char *buff = "nope";
    struct stat stat_buff;

    if (fd == -1) {
        my_puterror("Unable to open the file.\n");
        exit(84);
    }
    stat(filepath, &stat_buff);
    return (open_file2(stat_buff, buff, fr, fd));
}