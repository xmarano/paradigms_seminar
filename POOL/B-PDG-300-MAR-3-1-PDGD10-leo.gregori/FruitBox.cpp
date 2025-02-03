/*
** EPITECH PROJECT, 2025
** POOL DAY 10
** File description:
** ex01
*/
#include "FruitBox.hpp"

FruitBox::FruitBox(unsigned int size) : maxSize(size)
{
}

FruitBox::~FruitBox()
{
    for (auto fruit : fruits)
        delete fruit;
    fruits.clear();
}

unsigned int FruitBox::getSize() const
{
    return maxSize;
}

unsigned int FruitBox::nbFruits() const
{
    return fruits.size();
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    if (fruit == nullptr || fruits.size() >= maxSize)
        return false;
    if (std::find(fruits.begin(), fruits.end(), fruit) != fruits.end())
        return false;
    fruits.push_back(fruit);
    return true;
}

IFruit *FruitBox::popFruit()
{
    if (fruits.empty())
        return nullptr;
    IFruit *fruit = fruits.front();
    fruits.erase(fruits.begin());
    return fruit;
}

std::ostream &operator<<(std::ostream &os, const FruitBox &box)
{
    os << "[";
    for (size_t i = 0; i < box.fruits.size(); ++i) {
        os << *box.fruits[i];
        if (i != box.fruits.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
