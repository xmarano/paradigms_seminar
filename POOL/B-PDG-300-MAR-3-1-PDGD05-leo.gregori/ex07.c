/*
** EPITECH PROJECT, 2025
** POOL DAY 05
** File description:
** ex07
*/
#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t len = strlen(this->str);

    if (this == NULL || this->str == NULL || s == NULL)
        return 0;
    if (pos > len)
        return 0;
    strncpy(s, this->str + pos, n);
    if (n + pos > len)
        return strlen(s) + 1;
    else
        return strlen(s);
}
