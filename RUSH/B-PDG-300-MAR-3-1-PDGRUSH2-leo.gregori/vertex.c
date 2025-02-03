/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 02
*/
#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y, z;
}   VertexClass;

static void vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this || !args)
        raise("Invalid constructor arguments");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void vertex_dtor(VertexClass *this)
{
    if (!this)
        raise("Invalid destructor arguments");
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

static char *vertex_str(VertexClass *this)
{
    int size = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>",
        this->x, this->y, this->z) + 1;
    char *str = malloc(size);

    if (!this)
        raise("Invalid object");
    if (!str)
        raise("Out of memory");
    snprintf(str, size, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return str;
}

static Object *vertex_add(const Object *this, const Object *other)
{
    const VertexClass *vertex1;
    const VertexClass *vertex2;
    VertexClass *result;

    if (!this || !other)
        raise("Invalid addition arguments");
    vertex1 = (const VertexClass *)this;
    vertex2 = (const VertexClass *)other;
    result = new(Vertex, vertex1->x + vertex2->x,
        vertex1->y + vertex2->y, vertex1->z + vertex2->z);
    return (Object *)result;
}

static Object *vertex_sub(const Object *this, const Object *other)
{
    const VertexClass *vertex1;
    const VertexClass *vertex2;
    VertexClass *result;

    if (!this || !other)
        raise("Invalid subtraction arguments");
    vertex1 = (const VertexClass *)this;
    vertex2 = (const VertexClass *)other;
    result = new(Vertex, vertex1->x - vertex2->x,
        vertex1->y - vertex2->y, vertex1->z - vertex2->z);
    return (Object *)result;
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&vertex_ctor,
        .__dtor__ = (dtor_t)&vertex_dtor,
        .__str__ =  (to_string_t)&vertex_str,
        .__add__ = (binary_operator_t)&vertex_add,
        .__sub__ = (binary_operator_t)&vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
