/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex043
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool list_del_elem_at_position(list_t **front_ptr, unsigned int position)
{
    list_t *current = *front_ptr;
    list_t *temp = NULL;

    if (*front_ptr == NULL)
        return false;
    if (position == 0) {
        *front_ptr = (*front_ptr)->next;
        free(current);
        return true;
    }
    for (unsigned int i = 0; i < position - 1; i++) {
        if (current == NULL)
            return false;
        current = current->next;
    }
    temp = current->next;
    current->next = temp->next;
    free(temp);
    return true;
}

void *list_get_elem_at_front(list_t *list)
{
    if (list == NULL)
        return NULL;
    return list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    if (list == NULL)
        return NULL;
    while (list->next != NULL)
        list = list->next;
    return list->value;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    if (list == NULL)
        return NULL;
    for (unsigned int i = 0; i < position; i++) {
        if (list == NULL)
            return NULL;
        list = list->next;
    }
    return list->value;
}
