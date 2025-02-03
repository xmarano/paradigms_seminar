/*
** EPITECH PROJECT, 2025
** POOL DAY 13
** File description:
** ex00
*/
#include <type_traits>
#include <iostream>

#pragma once

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
bool less_than(const T& a, const T& b)
{
    return a < b;
}

template <typename T>
T min(const T& a, const T& b)
{
    return less_than(a, b) ? a : b;
}

template <typename T>
T max(const T& a, const T& b)
{
    return less_than(a, b) ? b : a;
}

template <typename T>
T clamp(const T& a, const T& b, const T& c)
{
    if (less_than(a, b))
        return b;
    else if (less_than(c, a))
        return c;
    return a;
}
