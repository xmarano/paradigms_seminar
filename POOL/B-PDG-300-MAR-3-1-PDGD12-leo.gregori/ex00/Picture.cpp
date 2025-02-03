/*
** EPITECH PROJECT, 2025
** POOL DAY 12
** File description:
** ex00
*/
#include "Picture.hpp"

Picture::Picture() : data("")
{
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream ifs(file);
    std::string line;
    std::string content;

    if (!ifs.is_open()) {
        data = "ERROR";
        return false;
    }
    while (std::getline(ifs, line))
        content += line + "\n";
    data = content;
    return true;
}
