/*
** EPITECH PROJECT, 2025
** POOL DAY 06
** File description:
** ex02
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

void degree(std::string input)
{
    float temperature;
    std::string scale;

    std::stringstream ss(input);
    ss >> temperature >> scale;

    if (scale == "Fahrenheit") {
        float celsius = 5.0 / 9.0 * (temperature - 32);
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << celsius << std::setw(16) << "Celsius" << std::endl;
    } else if (scale == "Celsius") {
        float fahrenheit = (temperature * 9.0 / 5.0) + 32;
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << fahrenheit << std::setw(16) << "Fahrenheit" << std::endl;
    }
}

int main()
{
    std::string input;

    while (std::getline(std::cin, input))
        degree(input);
    return 0;
}
