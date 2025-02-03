/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 06
*/
#include <stdio.h>
#include "new.h"
#include "int.h"
#include "char.h"
#include "list.h"

int main(void)
{
    Object *list = new(List, Int);

    printf("Adding elements to the list:\n");
    push_front(list, new(Int, 42));
    push_back(list, new(Int, 24));
    push_front(list, new(Int, 84));
    push_back(list, new(Char, '&'));
    printf("List length: %zu\n", getlen(list));
    printf("Deleting elements from the list:\n");
    del_front(list);
    printf("List length after del_front: %zu\n", getlen(list));
    del_back(list);
    printf("List length after del_back: %zu\n", getlen(list));
    delete(list);
    return 0;
}
