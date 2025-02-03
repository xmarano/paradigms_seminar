/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 04
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "new.h"
#include "int.h"

typedef struct {
    Class base;
    int value;
} IntClass;

static void int_ctor(IntClass *this, va_list *args)
{
    if (!this || !args)
        raise("Invalid constructor arguments");
    this->value = va_arg(*args, int);
}

static void int_dtor(IntClass *this)
{
    (void)this;
}

static char *int_str(IntClass *this)
{
    char *str = NULL;
    size_t size = snprintf(NULL, 0, "<Int (%d)>", this->value) + 1;

    if (!this)
        raise("Invalid object for string conversion");
    str = malloc(size);
    if (!str)
        raise("Out of memory");
    snprintf(str, size, "<Int (%d)>", this->value);
    return str;
}

static Object *int_add(const Object *this, const Object *other)
{
    IntClass *a = (IntClass *)this;
    IntClass *b = (IntClass *)other;

    if (!this || !other)
        raise("Null object in addition");
    return new(Int, a->value + b->value);
}

static Object *int_sub(const Object *this, const Object *other)
{
    IntClass *a = (IntClass *)this;
    IntClass *b = (IntClass *)other;

    if (!this || !other)
        raise("Null object in subtraction");
    return new(Int, a->value - b->value);
}

static Object *int_mul(const Object *this, const Object *other)
{
    IntClass *a = (IntClass *)this;
    IntClass *b = (IntClass *)other;

    if (!this || !other)
        raise("Null object in multiplication");
    return new(Int, a->value * b->value);
}

static Object *int_div(const Object *this, const Object *other)
{
    IntClass *a = (IntClass *)this;
    IntClass *b = (IntClass *)other;

    if (!this || !other)
        raise("Null object in division");
    if (b->value == 0)
        raise("Division by zero");
    return new(Int, a->value / b->value);
}

static bool int_eq(const Object *this, const Object *other)
{
    IntClass *a = (IntClass *)this;
    IntClass *b = (IntClass *)other;

    if (!this || !other)
        raise("Null object in comparison");
    return a->value == b->value;
}

static bool int_lt(const Object *this, const Object *other)
{
    IntClass *a = (IntClass *)this;
    IntClass *b = (IntClass *)other;

    if (!this || !other)
        raise("Null object in comparison");
    return a->value < b->value;
}


static bool int_gt(const Object *this, const Object *other)
{
    IntClass *a = (IntClass *)this;
    IntClass *b = (IntClass *)other;

    if (!this || !other)
        raise("Null object in comparison");
    return a->value > b->value;
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&int_ctor,
        .__dtor__ = (dtor_t)&int_dtor,
        .__str__ = (to_string_t)&int_str,
        .__add__ = (binary_operator_t)&int_add,
        .__sub__ = (binary_operator_t)&int_sub,
        .__mul__ = (binary_operator_t)&int_mul,
        .__div__ = (binary_operator_t)&int_div,
        .__eq__ = (binary_comparator_t)&int_eq,
        .__lt__ = (binary_comparator_t)&int_lt,
        .__gt__ = (binary_comparator_t)&int_gt
    },
    .value = 0
};

const Class *Int = (const Class *)&_description;
