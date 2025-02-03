/*
** EPITECH PROJECT, 2025
** POOL DAY 05
** File description:
** ex00
*/
#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (this && s) {
        this->str = strdup(s);
        this->assign_c = assign_c;
        this->assign_s = assign_s;
        this->append_s = append_s;
        this->append_c = append_c;
        this->at = at;
        this->clear = clear;
        this->length = length;
        this->compare_s = compare_s;
        this->compare_c = compare_c;
        this->copy = copy;
        this->c_str = c_str;
        this->empty = empty;
        this->find_s = find_s;
        this->find_c = find_c;
    }
}

void string_destroy(string_t *this)
{
    if (this) {
        free(this->str);
        this->str = NULL;
    }
}
