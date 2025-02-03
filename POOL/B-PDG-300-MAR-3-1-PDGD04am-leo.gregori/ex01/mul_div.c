/*
** EPITECH PROJECT, 2025
** POOL DAY 04
** File description:
** ex01
*/
#include <stdio.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    if (b != 0)
        *div = a / b;
    else
        *div = 42;
}

void mul_div_short(int *a, int *b)
{
    int a2 = *a;
    int b2 = *b;

    *a = a2 * b2;
    if (b2 != 0)
        *b = a2 / b2;
    else
        *b = 42;
}

// static void test_long ( void )
// {
//     int a = 13;
//     int b = -4;
//     int mul;
//     int div;

//     mul_div_long (a, b, &mul, &div);
//     printf ("%d * %d = %d\n", a, b, mul);
//     printf ("%d / %d = %d\n", a, b, div);
// }

// static void test_short(void)
// {
//     int a = 99;
//     int b = 11;
//     int mul_res = a;
//     int div_res = b;

//     mul_div_short(&mul_res, &div_res);
//     printf("%d * %d = %d\n", a, b, mul_res);
//     printf("%d / %d = %d\n", a, b, div_res);
// }

// int main(void)
// {
//     test_long();
//     test_short();
//     return(0);
// }
