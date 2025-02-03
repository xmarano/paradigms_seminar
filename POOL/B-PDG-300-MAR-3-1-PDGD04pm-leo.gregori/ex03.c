/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex03
*/
#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *temp = *front_ptr;

    if (*front_ptr == NULL)
            return false;
    *front_ptr = (*front_ptr)->next;
    free(temp);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    int_list_t *current = *front_ptr;

    if (*front_ptr == NULL)
        return false;
    if (!current->next) {
        free(current);
        *front_ptr = NULL;
        return true;
    }
    while (current->next->next)
        current = current->next;
    free(current->next);
    current->next = NULL;
    return true;
}

bool find_and_delete_at_position(int_list_t **front_ptr, unsigned int position)
{
    int_list_t *temp = *front_ptr;
    int_list_t *prev = NULL;
    unsigned int i = 0;

    while (temp != NULL) {
        if (i == position) {
            prev->next = temp->next;
            free(temp);
            return true;
        }
        prev = temp;
        temp = temp->next;
        i++;
    }
    return false;
}

bool int_list_del_elem_at_position(int_list_t **front_ptr,
    unsigned int position)
{
    int_list_t *temp = *front_ptr;

    if (*front_ptr == NULL)
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
    return find_and_delete_at_position(front_ptr, position);
}
