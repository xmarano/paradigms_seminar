/*
** EPITECH PROJECT, 2025
** Paradigms Seminar
** File description:
** Exercice 01
*/
#include "new.h"
#include "player.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
    Object *player = new(Player);

    delete(player);
    return (0);
}
