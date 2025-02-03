/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex04
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

unsigned int list_get_size(list_t *list)
{
    unsigned int size = 0;

    if (list == NULL)
        return size;
    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *current = *front_ptr;

    if (!new_node)
        return false;
    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new_node;
    } else {
        current = *front_ptr;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
    return true;
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    while (list != NULL) {
        val_disp(list->value);
        list = list->next;
    }
}

void list_clear(list_t **front)
{
    list_t *current = *front;
    list_t *temp = current;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *front = NULL;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    list_t *current = *front_ptr;

    if (*front_ptr == NULL)
        return false;
    if ((*front_ptr)->next == NULL) {
        free(*front_ptr);
        *front_ptr = NULL;
        return true;
    }
    while (current->next->next != NULL)
        current = current->next;
    free(current->next);
    current->next = NULL;
    return true;
}
