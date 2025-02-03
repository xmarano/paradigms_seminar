/*
** EPITECH PROJECT, 2025
** File description:
** FruitUtils
*/
#include "FruitUtils.hpp"
#include "Lemon.hpp"
#include "ACitrus.hpp"
#include "ABerry.hpp"

void FruitUtils::sort(FruitBox& unsorted, FruitBox& lemon, FruitBox& citrus, FruitBox& berry)
{
    FruitBox temp(unsorted.getSize());

    IFruit* fruit = nullptr;
    while ((fruit = unsorted.popFruit()) != nullptr) {
        if (dynamic_cast<Lemon*>(fruit)) {
            if (!lemon.pushFruit(fruit))
                temp.pushFruit(fruit);
        } else if (dynamic_cast<ACitrus*>(fruit)) {
            if (!citrus.pushFruit(fruit))
                temp.pushFruit(fruit);
        } else if (dynamic_cast<ABerry*>(fruit)) {
            if (!berry.pushFruit(fruit))
                temp.pushFruit(fruit);
        } else
            temp.pushFruit(fruit);
    }
    while ((fruit = temp.popFruit()) != nullptr)
        unsorted.pushFruit(fruit);
}
