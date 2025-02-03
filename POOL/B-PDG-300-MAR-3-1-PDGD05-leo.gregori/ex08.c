/*
** EPITECH PROJECT, 2025
** POOL DAY 05
** File description:
** ex08
*/
#include "string.h"

const char *c_str(const string_t *this)
{
    if (!this || !this->str)
        return NULL;
    return this->str;
}
