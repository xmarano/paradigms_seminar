/*
** EPITECH PROJECT, 2025
** POOL DAY 11
** File description:
** ex02
*/
#include "UniquePointer.hpp"

UniquePointer::UniquePointer() : _ptr(nullptr)
{
}

UniquePointer::UniquePointer(IObject *obj) : _ptr(obj)
{
}

UniquePointer::~UniquePointer()
{
    delete _ptr;
}

IObject *UniquePointer::operator->() const
{
    return _ptr;
}

IObject &UniquePointer::operator*() const
{
    return *_ptr;
}

void UniquePointer::reset(IObject *obj)
{
    delete _ptr;
    _ptr = obj;
}

void UniquePointer::swap(UniquePointer &other)
{
    std::swap(_ptr, other._ptr);
}

UniquePointer &UniquePointer::operator=(IObject *obj)
{
    reset(obj);
    return *this;
}
