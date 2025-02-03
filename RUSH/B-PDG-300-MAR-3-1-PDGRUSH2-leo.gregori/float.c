/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 04
*/
#include <stdio.h>
#include <string.h>
#include "new.h"
#include "float.h"

typedef struct
{
    Class base;
    float value;
} FloatClass;

static void float_ctor(FloatClass *this, va_list *args)
{
    if (!this || !args)
        raise("Invalid constructor arguments");
    this->value = (float)va_arg(*args, double);
}

static void float_dtor(FloatClass *this)
{
    (void)this;
}

static char *float_str(FloatClass *this)
{
    char *str = NULL;
    size_t size;

    if (!this)
        raise("Invalid object for string conversion");
    size = snprintf(NULL, 0, "<Float (%f)>", this->value) + 1;
    str = malloc(size);
    if (!str)
        raise("Out of memory");
    snprintf(str, size, "<Float (%f)>", this->value);
    return str;
}

static Object *float_add(const Object *this, const Object *other)
{
    FloatClass *a;
    FloatClass *b;

    if (!this || !other)
        raise("Null object in addition");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    return new(Float, a->value + b->value);
}

static Object *float_sub(const Object *this, const Object *other)
{
    FloatClass *a;
    FloatClass *b;

    if (!this || !other)
        raise("Null object in subtraction");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    return new(Float, a->value - b->value);
}

static Object *float_mul(const Object *this, const Object *other)
{
    FloatClass *a;
    FloatClass *b;

    if (!this || !other)
        raise("Null object in multiplication");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    return new(Float, a->value * b->value);
}

static Object *float_div(const Object *this, const Object *other)
{
    FloatClass *a;
    FloatClass *b;

    if (!this || !other)
        raise("Null object in division");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    if (b->value == 0.0f)
        raise("Division by zero");
    return new(Float, a->value / b->value);
}

static bool float_eq(const Object *this, const Object *other)
{
    FloatClass *a;
    FloatClass *b;

    if (!this || !other)
        raise("Null object in comparison");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    return a->value == b->value;
}

static bool float_lt(const Object *this, const Object *other)
{
    FloatClass *a;
    FloatClass *b;

    if (!this || !other)
        raise("Null object in comparison");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    return a->value < b->value;
}

static bool float_gt(const Object *this, const Object *other)
{
    FloatClass *a;
    FloatClass *b;

    if (!this || !other)
        raise("Null object in comparison");
    a = (FloatClass *)this;
    b = (FloatClass *)other;
    return a->value > b->value;
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = (to_string_t)&float_str,
        .__add__ = (binary_operator_t)&float_add,
        .__sub__ = (binary_operator_t)&float_sub,
        .__mul__ = (binary_operator_t)&float_mul,
        .__div__ = (binary_operator_t)&float_div,
        .__eq__ = (binary_comparator_t)&float_eq,
        .__lt__ = (binary_comparator_t)&float_lt,
        .__gt__ = (binary_comparator_t)&float_gt
    },
    .value = 0.0f
};

const Class *Float = (const Class *)&_description;
