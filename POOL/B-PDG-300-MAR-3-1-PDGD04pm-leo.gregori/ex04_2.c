/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex042
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool list_is_empty(list_t *list)
{
    if (list == NULL)
        return true;
    return false;
}

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *new_node = malloc(sizeof(list_t));

    if (!new_node)
        return false;
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool list_add_elem_at_position(list_t **front_ptr, void *elem,
    unsigned int position)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *current = *front_ptr;

    if (!new_node)
        return false;
    new_node->value = elem;
    if (position == 0) {
        new_node->next = *front_ptr;
        *front_ptr = new_node;
        return true;
    }
    for (unsigned int i = 0; i < position - 1 && current; i++)
        current = current->next;
    if (!current)
        return false;
    new_node->next = current->next;
    current->next = new_node;
    return true;
}

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *temp = *front_ptr;

    if (*front_ptr == NULL)
        return false;
    *front_ptr = (*front_ptr)->next;
    free(temp);
    return true;
}
