/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex01
*/
#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *new_node = malloc(sizeof(int_list_t));

    if (!new_node)
        return false;
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool int_list_add_elem_at_position(int_list_t **front_ptr, int elem,
    unsigned int position)
{
    int_list_t *current = *front_ptr;
    int_list_t *new_node = malloc(sizeof(int_list_t));

    if (position == 0) {
        free(new_node);
        return int_list_add_elem_at_front(front_ptr, elem);
    }
    for (unsigned int i = 0; current != NULL && i < position - 1; i++)
        current = current->next;
    if (!new_node || current == NULL)
        return false;
    new_node->value = elem;
    new_node->next = current->next;
    current->next = new_node;
    return true;
}
