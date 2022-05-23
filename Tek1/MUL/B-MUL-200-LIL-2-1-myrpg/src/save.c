/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg
** File description:
** save
*/

#include "rpg.h"

int get_infos_save2(rpg_t *rpg, char *str, int i)
{
    int tmp = my_getnbr(str, 0);

    if (i == 1 && tmp > 0)
        rpg->inventory.pok.lvl = tmp;
    if (i == 2 && tmp > 0)
        rpg->inventory.berries = tmp;
    if (my_alpcmp("muted\n", str, 0) == 2)
        rpg->bol.muted = true;
    return 0;
}

int get_infos_save(rpg_t *rpg, char *str, int i)
{
    if (my_alpcmp(str, "boy\n", 0) == 2) {
        if (create_boy(rpg) == 84)
            return 84;
        rpg->bol.player = true;
        rpg->bol.boy = true;
    }
    if (my_alpcmp(str, "girl\n", 0) == 2) {
        if (create_girl(rpg) == 84)
            return 84;
        rpg->bol.player = true;
        rpg->bol.boy = false;
    }
    return get_infos_save2(rpg, str, i);
}

int load_save(rpg_t *rpg)
{
    FILE *fd = fopen("save", "r");
    size_t len;
    char *str;

    if (fd == NULL)
        return 0;
    for (int i = 0; i != 4; i++) {
        str = NULL;
        if (getline(&str, &len, fd) == -1) {
            free(str);
            fclose(fd);
            return 0;
        }
        if (get_infos_save(rpg, str, i) == 84)
            return 84;
        free(str);
    }
    fclose(fd);
    return 0;
}

void save_game2(rpg_t *rpg, char *str, int fd)
{
    int_to_str(rpg->inventory.pok.lvl, str);
    write(fd, str, my_strlen(str));
    write(fd, "\n", 1);
    write(fd, rpg->inventory.berries_str,
    my_strlen(rpg->inventory.berries_str));
    write(fd, "\n", 1);
    if (rpg->bol.muted)
        write(fd, "muted\n", 6);
    free(str);
    my_printf("Saved !\n");
    close(fd);
}

void save_game(rpg_t *rpg)
{
    int fd = open("save", O_CREAT | O_RDWR | O_TRUNC, 0664);
    char *str = malloc(sizeof(char) * 11);

    if (!str)
        return;
    if (fd == -1) {
        write(2, "Could not save the game.\n", 25);
        return;
    }
    if (rpg->bol.boy)
        write(fd, "boy\n", 4);
    else
        write(fd, "girl\n", 5);
    save_game2(rpg, str, fd);
}