/*
** EPITECH PROJECT, 2025
** POOL DAY 05
** File description:
** ex01
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this && str) {
        free(this->str);
        this->str = strdup(str->str);
    }
}

void assign_c(string_t *this, const char *s)
{
    if (this && s) {
        free(this->str);
        this->str = strdup(s);
    }
}
