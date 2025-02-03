/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex02
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    int len = strlen(str1) + strlen(str2) + 1;

    *res = (char *)malloc(len * sizeof(char));
    if (*res == NULL)
        return;
    strcpy(*res, str1);
    strcat(*res, str2);
}

void concat_struct(concat_t *str)
{
    int len = strlen(str->str1) + strlen(str->str2) + 1;

    str->res = (char *)malloc(len * sizeof(char));
    if (str->res == NULL)
        return;
    strcpy(str->res, str->str1);
    strcat(str->res, str->str2);
}
