/*
** EPITECH PROJECT, 2025
** POOL DAY 05
** File description:
** ex10
*/
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *occurrence = strstr(this->str + pos, str->str);

    if (this == NULL || str == NULL || str->str == NULL || this->str == NULL)
        return -1;
    if (pos >= strlen(this->str))
        return -1;
    if (occurrence == NULL)
        return -1;
    return occurrence - this->str;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *occurrence = strstr(this->str + pos, str);

    if (this == NULL || str == NULL || this->str == NULL)
        return -1;
    if (pos >= strlen(this->str))
        return -1;
    if (occurrence == NULL)
        return -1;
    return occurrence - this->str;
}
