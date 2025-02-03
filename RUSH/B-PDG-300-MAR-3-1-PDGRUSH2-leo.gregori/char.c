/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 04
*/
#include <stdio.h>
#include <string.h>
#include "new.h"
#include "char.h"

typedef struct {
    Class base;
    char value;
} CharClass;

static void Char_constructor(Object *self, va_list *args)
{
    CharClass *this = (CharClass *)self;

    this->value = (char)va_arg(*args, int);
}

static void Char_destructor(Object *self)
{
    (void)self;
}

static char *Char_str(Object *self)
{
    CharClass *this = (CharClass *)self;
    char *buffer = malloc(32);
    
    if (buffer == NULL)
        raise("Out of memory");
    snprintf(buffer, 32, "<Char (%c)>", this->value);
    return buffer;
}

static Object *Char_add(const Object *self, const Object *other)
{
    CharClass *this = (CharClass *)self;
    CharClass *that = (CharClass *)other;
    
    return new(Char, this->value + that->value);
}

static Object *Char_sub(const Object *self, const Object *other)
{
    CharClass *this = (CharClass *)self;
    CharClass *that = (CharClass *)other;
    
    return new(Char, this->value - that->value);
}

static Object *Char_mul(const Object *self, const Object *other)
{
    CharClass *this = (CharClass *)self;
    CharClass *that = (CharClass *)other;
    
    return new(Char, this->value * that->value);
}

static Object *Char_div(const Object *self, const Object *other)
{
    CharClass *this = (CharClass *)self;
    CharClass *that = (CharClass *)other;
    
    if (that->value == 0)
        raise("Division by zero");
    return new(Char, this->value / that->value);
}

static bool Char_eq(const Object *self, const Object *other)
{
    CharClass *this = (CharClass *)self;
    CharClass *that = (CharClass *)other;
    
    return this->value == that->value;
}

static bool Char_gt(const Object *self, const Object *other)
{
    CharClass *this = (CharClass *)self;
    CharClass *that = (CharClass *)other;
    
    return this->value > that->value;
}

static bool Char_lt(const Object *self, const Object *other)
{
    CharClass *this = (CharClass *)self;
    CharClass *that = (CharClass *)other;
    
    return this->value < that->value;
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = &Char_constructor,
        .__dtor__ = &Char_destructor,
        .__str__ = &Char_str,
        .__add__ = &Char_add,
        .__sub__ = &Char_sub,
        .__mul__ = &Char_mul,
        .__div__ = &Char_div,
        .__eq__ = &Char_eq,
        .__gt__ = &Char_gt,
        .__lt__ = &Char_lt
    },
    .value = 0
};

const Class *Char = (const Class *)&_description;
