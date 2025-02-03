/*
** EPITECH PROJECT, 2025
** POOL DAY 13
** File description:
** ex01
*/
#include <iostream>
#include <array>
#include <stdexcept>
#include <functional>

#pragma once

template <typename Type, std::size_t Size>

class Array {
    private:
        std::array<Type, Size> data{};

    public:
        Type& operator[](std::size_t index) {
            if (index >= Size)
                throw std::out_of_range("Out of range");
            return data[index];
        }

        const Type& operator[](std::size_t index) const {
            if (index >= Size)
                throw std::out_of_range("Out of range");
            return data[index];
        }

        std::size_t size() const { return Size; }

        void forEach(const std::function<void(const Type&)>& task) const {
            for (const auto& elem : data)
                task(elem);
        }

        template <typename U>
        Array<U, Size> convert(const std::function<U(const Type&)>& converter) const {
            Array<U, Size> newArray;
            for (std::size_t i = 0; i < Size; ++i)
                newArray[i] = converter(data[i]);
            return newArray;
        }

        friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
            os << "[";
            for (std::size_t i = 0; i < Size; ++i) {
                os << arr.data[i];
                if (i < Size - 1)
                    os << ", ";
            }
            os << "]";
            return os;
        }
};
