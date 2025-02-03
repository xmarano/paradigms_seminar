/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/
#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y;
}   PointClass;

static void point_ctor(PointClass *this, va_list *args)
{
    if (!this || !args)
        raise("Invalid constructor arguments");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void point_dtor(PointClass *this)
{
    if (!this)
        raise("Invalid destructor arguments");
    this->x = 0;
    this->y = 0;
}

static char *point_str(PointClass *this)
{
    int size = snprintf(NULL, 0, "<Point (%d, %d)>", this->x, this->y) + 1;
    char *str = malloc(size);

    if (!this)
        raise("Invalid object");
    if (!str)
        raise("Out of memory");
    snprintf(str, size, "<Point (%d, %d)>", this->x, this->y);
    return str;
}

static Object *add_point(PointClass *this, PointClass *other)
{
    if (!this || !other)
        raise("Invalid addition arguments");

    PointClass *result = new(Point, this->x + other->x, this->y + other->y);
    return (Object *)result;
}

static Object *sub_point(PointClass *this, PointClass *other)
{
    if (!this || !other)
        raise("Invalid subtraction arguments");

    PointClass *result = new(Point, this->x - other->x, this->y - other->y);
    return (Object *)result;
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_ctor,
        .__dtor__ = (dtor_t)&point_dtor,
        .__str__ = (to_string_t)&point_str,
        .__add__ = (binary_operator_t)&add_point,
        .__sub__ = (binary_operator_t)&sub_point,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
