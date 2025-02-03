/*
** EPITECH PROJECT, 2025
** POOL DAY 12
** File description:
** ex00
*/
#include <fstream>
#include <iostream>

#pragma once

class Picture {
    public:
        std::string data;
        
        Picture(const std::string &file);
        Picture();
        ~Picture();

        bool getPictureFromFile(const std::string &file);
};
