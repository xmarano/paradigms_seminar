/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex00
*/
#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"


bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *new_node = malloc(sizeof(int_list_t));
    int_list_t *current = *front_ptr;

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

void int_list_dump(int_list_t *list)
{
    while (list != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
}

unsigned int int_list_get_size(int_list_t *list)
{
    unsigned int size = 0;

    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

bool int_list_is_empty(int_list_t *list)
{
    return (list == NULL);
}

void int_list_clear(int_list_t **front_ptr)
{
    int_list_t *current = *front_ptr;
    int_list_t *temp = current;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *front_ptr = NULL;
}
