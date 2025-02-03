/*
** EPITECH PROJECT, 2025
** POOL DAY 11
** File description:
** ex00
*/
#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister() : dir(nullptr), _hidden(false)
{
}

DirectoryLister::DirectoryLister(const std::string &path, bool hidden) : dir(nullptr), _hidden(false)
{
    open(path, hidden);
}

DirectoryLister::~DirectoryLister()
{
    if (dir != nullptr)
        closedir(dir);
}

bool DirectoryLister::open(const std::string &path, bool hidden)
{
    if (dir != nullptr) {
        closedir(dir);
        dir = nullptr;
    }
    dir = opendir(path.c_str());
    if (dir == nullptr) {
        perror(path.c_str());
        return false;
    }
    _hidden = hidden;
    return true;
}

std::string DirectoryLister::get()
{
    if (dir == nullptr)
        return "";
    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string name(entry->d_name);
        if (!_hidden && name[0] == '.')
            continue;
        return name;
    }
    return "";
}
