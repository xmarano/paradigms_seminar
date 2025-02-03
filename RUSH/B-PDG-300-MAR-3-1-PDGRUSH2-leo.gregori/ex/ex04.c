/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 04
*/
#include <stdio.h>
#include "new.h"
#include "int.h"
#include "float.h"
#include "char.h"

void calculs(Object *x, Object *y, bool a)
{
    printf("%s == %s = %s\n", str(x), str(x), eq(x, x) ? "true" : "false");
    printf("%s > %s = %s\n", str(x), str(y), gt(x, y) ? "true" : "false");
    printf("%s < %s = %s\n", str(x), str(y), lt(x, y) ? "true" : "false");
    printf("%s + %s = %s\n", str(x), str(y), str(addition(x, y)));
    if (a)
        printf("%s - %s = %s\n", str(x), str(y), str(subtraction(x, y)));
    printf("%s * %s = %s\n", str(x), str(y), str(multiplication(x, y)));
    printf("%s / %s = %s\n", str(x), str(y), str(division(x, y)));
    delete(x);
    delete(y);
}

int main(void)
{
    Object *i1 = new(Int, 10);
    Object *i2 = new(Int, 5);
    Object *f1 = new(Float, 3.14);
    Object *f2 = new(Float, 1.14);
    Object *c1 = new(Char, '&');
    Object *c2 = new(Char, '7');

    calculs(i1, i2, true);
    calculs(f1, f2, true);
    calculs(c1, c2, false);
    return 0;
}
