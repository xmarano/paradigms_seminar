/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 06
*/
#include <stdlib.h>
#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct ListNode {
    Object *data;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

typedef struct {
    Container base;
    Class *_type;
    size_t _size;
    ListNode *_head;
    ListNode *_tail;
} ListClass;

static void List_ctor(ListClass *this, va_list *args)
{
    if (!this || !args)
        raise("Invalid arguments to List constructor");
    this->_type = va_arg(*args, Class *);
    this->_size = 0;
    this->_head = NULL;
    this->_tail = NULL;
}

static void List_dtor(ListClass *this)
{
    ListNode *current = this->_head;
    ListNode *next;

    while (current) {
        next = current->next;
        delete(current->data);
        free(current);
        current = next;
    }
    this->_size = 0;
    this->_head = NULL;
    this->_tail = NULL;
}

void push_front(Object *list, Object *element)
{
    ListClass *this = (ListClass *)list;
    ListNode *node = malloc(sizeof(ListNode));

    if (!node)
        raise("Out of memory");
    node->data = element;
    node->next = this->_head;
    node->prev = NULL;
    if (this->_head)
        this->_head->prev = node;
    this->_head = node;
    if (!this->_tail)
        this->_tail = node;
    this->_size++;
}

void push_back(Object *list, Object *element)
{
    ListClass *this = (ListClass *)list;
    ListNode *node = malloc(sizeof(ListNode));

    if (!node)
        raise("Out of memory");
    node->data = element;
    node->next = NULL;
    node->prev = this->_tail;
    if (this->_tail)
        this->_tail->next = node;
    this->_tail = node;
    if (!this->_head)
        this->_head = node;
    this->_size++;
}

size_t getlen(Object *list)
{
    ListClass *this = (ListClass *)list;

    return this->_size;
}

void del_front(Object *list)
{
    ListClass *this = (ListClass *)list;
    ListNode *node;

    if (this->_size == 0)
        raise("Cannot delete from an empty list");
    node = this->_head;
    this->_head = this->_head->next;
    if (this->_head)
        this->_head->prev = NULL;
    else
        this->_tail = NULL;
    delete(node->data);
    free(node);
    this->_size--;
}

void del_back(Object *list)
{
    ListClass *this = (ListClass *)list;
    ListNode *node;

    if (this->_size == 0)
        raise("Cannot delete from an empty list");
    node = this->_tail;
    this->_tail = this->_tail->prev;
    if (this->_tail)
        this->_tail->next = NULL;
    else
        this->_head = NULL;
    delete(node->data);
    free(node);
    this->_size--;
}

// description statique de la classe
static const ListClass _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = NULL,
        .__begin__ = NULL,
        .__end__ = NULL,
        .__getitem__ = NULL,
        .__setitem__ = NULL,
    },
    ._type = NULL,
    ._size = 0,
    ._head = NULL,
    ._tail = NULL
};

const Class *List = (const Class *)&_descr;
