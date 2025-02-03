/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 06
*/
#include "container.h"

#ifndef LIST_H
    #define LIST_H


extern const Class *List;

void push_front(Object *list, Object *element);
void push_back(Object *list, Object *element);
size_t getlen(Object *list);
void del_front(Object *list);
void del_back(Object *list);

#endif
