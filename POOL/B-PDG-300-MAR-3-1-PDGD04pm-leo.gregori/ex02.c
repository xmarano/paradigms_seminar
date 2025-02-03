/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex02
*/
#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

int int_list_get_elem_at_front(int_list_t *list)
{
    if (list == NULL)
        return 0;
    return list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    if (list == NULL)
        return 0;
    while (list->next != NULL)
        list = list->next;
    return list->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    for (unsigned int i = 0; list != NULL && i < position; i++)
        list = list->next;
    if (list == NULL)
        return 0;
    return list->value;
}
