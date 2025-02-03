/*
** EPITECH PROJECT, 2025
** POOL DAY 05
** File description:
** ex05
*/
#include "string.h"

int length(const string_t *this)
{
    int i = 0;

    if (!this || !this->str)
        return 0;
    for (; this->str[i]; i++);
    return i;
}
