/*
** EPITECH PROJECT, 2025
** POOL DAY 05
** File description:
** ex06
*/
#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (this && this->str && str && str->str)
        return (strcmp(this->str, str->str));
    return (-1);
}

int compare_c(const string_t *this, const char *str)
{
    if (this && this->str && str)
        return (strcmp(this->str, str));
    return (-1);
}
