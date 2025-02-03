/*
** EPITECH PROJECT, 2025
** POOL DAY 05
** File description:
** ex03
*/
#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (this && this->str && pos < strlen(this->str))
        return (this->str[pos]);
    return (-1);
}
