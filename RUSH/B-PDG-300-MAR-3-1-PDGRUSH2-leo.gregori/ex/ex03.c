/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 03
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"

int main(void)
{
    Object *p1 = new(Point, 12, 13);
    Object *p2 = new(Point, 2, 2);
    Object *p3 = new(Point, 0, 0);
    Object *p4 = new(Point, 38, -42);
    Object *v1 = new(Vertex, 1, 2, 3);
    Object *v2 = new(Vertex, 4, 5, 6);
    Object *v3 = new(Vertex, 7, 8, 9);
    Object *v4 = new(Vertex, 10, 11, 12);

    printf("%s + %s = %s\n", str(p1), str(p2), str(addition(p1, p2)));
    printf("%s - %s = %s\n", str(p1), str(p2), str(subtraction(p1, p2)));
    printf("%s + %s = %s\n", str(p3), str(p4), str(addition(p3, p4)));
    printf("%s - %s = %s\n", str(p3), str(p4), str(subtraction(p3, p4)));
    printf("%s + %s = %s\n", str(v1), str(v2), str(addition(v1, v2)));
    printf("%s - %s = %s\n", str(v1), str(v2), str(subtraction(v1, v2)));
    printf("%s + %s = %s\n", str(v3), str(v4), str(addition(v3, v4)));
    printf("%s - %s = %s\n", str(v3), str(v4), str(subtraction(v3, v4)));
    return (0);
}
