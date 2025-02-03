/*
** EPITECH PROJECT, 2025
** POOL DAY 05
** File description:
** ex02
*/
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    int len;

    if (this && ap && ap->str) {
        len = strlen(this->str) + strlen(ap->str) + 1;
        this->str = realloc(this->str, len);
        if (this->str)
            strcat(this->str, ap->str);
    }
}

void append_c(string_t *this, const char *ap)
{
    int len;

    if (this && ap) {
        len = strlen(this->str) + strlen(ap) + 1;
        this->str = realloc(this->str, len);
        if (this->str)
            strcat(this->str, ap);
    }
}
