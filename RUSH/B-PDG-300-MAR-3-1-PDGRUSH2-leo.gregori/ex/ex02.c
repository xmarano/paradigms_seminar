/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercise 02
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"

int main(void)
{
    Object *point = new(Point, 42, -42);
    Object *point2 = new(Point, 16, 7);
    Object *point3 = new(Point, 20, 40);
    Object *vertex = new(Vertex, 0, 1, 2);
    Object *vertex2 = new(Vertex, 0, 15, 30);
    Object *vertex3 = new(Vertex, 13, -13, 1);

    printf("point = %s\n", str(point));
    printf("point2 = %s\n", str(point2));
    printf("point3 = %s\n", str(point3));
    printf("vertex = %s\n", str(vertex));
    printf("vertex2 = %s\n", str(vertex2));
    printf("vertex3 = %s\n", str(vertex3));
    delete(point);
    delete(point2);
    delete(point3);
    delete(vertex);
    delete(vertex2);
    delete(vertex3);
    return (0);
}
