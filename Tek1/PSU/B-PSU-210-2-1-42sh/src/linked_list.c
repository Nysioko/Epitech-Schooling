/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-42sh
** File description:
** linked_list
*/

#include "sh.h"

linked_t *new_node(void)
{
    linked_t *new = malloc(sizeof(linked_t));

    if (!new)
        exit(84);
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void link_node(linked_t **elem, linked_t *new)
{
    linked_t *tmp = *elem;

    if (*elem == NULL) {
        *elem = new;
        (*elem)->prev = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
    (*elem)->prev = new;
}

int linked_len(linked_t *elem)
{
    int i = 0;

    for (linked_t *tmp = elem; tmp != NULL; tmp = tmp->next)
        i++;
    return i;
}

void remove_node(linked_t **elem, int pos)
{
    int i = 0;
    linked_t *tmp2 = *elem;

    if (pos < 0 || pos > linked_len(*elem))
        pos = linked_len(*elem);
    if (pos == 0) {
        *elem = tmp2->next;
        free(tmp2);
        return;
    }
    for (linked_t *tmp = *elem; tmp != NULL; tmp = tmp->next, tmp2 = tmp) {
        if (i == pos) {
            tmp2->next = tmp->next;
            if (tmp->next != NULL)
                tmp->next->prev = tmp2;
            free(tmp);
            return;
        }
        i++;
    }
}

void remove_all_nodes(linked_t *elem, linked_t *history)
{
    while (elem != NULL) {
        free(elem->alias);
        free(elem->func);
        remove_node(&elem, 0);
    }
    while (history != NULL) {
        free(history->func);
        remove_node(&history, 0);
    }
}