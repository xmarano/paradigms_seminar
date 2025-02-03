/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex03
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    *res = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        (*res)[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++)
            (*res)[i][j] = array[i * width + j];
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    if (!array || height == 0 || width == 0)
        return;
    for (int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}
