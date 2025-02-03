/*
** EPITECH PROJECT, 2025
** POOL DAY 11
** File description:
** ex02
*/
#include "IDirectoryLister.hpp"
#include "IObject.hpp"

class UniquePointer {
    private:
        IObject *_ptr;

    public:
        UniquePointer();
        UniquePointer(IObject *obj);
        ~UniquePointer();

        UniquePointer(const UniquePointer&) = delete;
        UniquePointer &operator=(const UniquePointer&) = delete;

        IObject *operator->() const;
        IObject &operator*() const;
        UniquePointer &operator=(IObject *obj);

        void reset(IObject *obj = nullptr);
        void swap(UniquePointer &other);
};
