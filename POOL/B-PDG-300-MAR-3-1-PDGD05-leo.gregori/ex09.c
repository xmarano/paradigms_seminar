/*
** EPITECH PROJECT, 2025
** POOL DAY 05
** File description:
** ex09
*/
#include "string.h"

int empty(const string_t *this)
{
    if (!this || !this->str)
        return 1;
    if (strlen(this->str) == 0)
        return 1;
    return 0;
}
