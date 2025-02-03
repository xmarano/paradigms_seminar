/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 01
*/
#include "new.h"

Object *new(const Class *class, ...)
{
    va_list ap;
    Object *obj;

    if (!class)
        raise("Class is NULL");
    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return (obj);
}

Object *va_new(const Class *class, va_list* ap)
{
    Object *obj;

    if (!class || !ap)
        raise("Invalid class or argument list");
    obj = malloc(class->__size__);
    if (obj == NULL)
        raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(obj, ap);
    return (obj);
}

void delete(Object *ptr)
{
    if (ptr && ((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}
