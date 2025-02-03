/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex04
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int len = strlen(str);

    for (int i = len; i > 0; i--)
        printf("%c", str[i - 1]);
    printf("\n");
}

void print_upper(const char *str)
{
    while (*str) {
        printf("%c", toupper(*str));
        str++;
    }
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*actions[])(const char *) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };

    actions[action](str);
}
