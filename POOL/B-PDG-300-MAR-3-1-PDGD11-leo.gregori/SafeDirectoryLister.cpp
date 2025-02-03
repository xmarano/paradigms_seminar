/*
** EPITECH PROJECT, 2025
** POOL DAY 11
** File description:
** ex01
*/
#include "SafeDirectoryLister.hpp"

SafeDirectoryLister::SafeDirectoryLister() : dir(nullptr), _hidden(false)
{
}

SafeDirectoryLister::SafeDirectoryLister(const std::string &path, bool hidden) : dir(nullptr), _hidden(false)
{
    open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (dir != nullptr)
        closedir(dir);
}

bool SafeDirectoryLister::open(const std::string &path, bool hidden)
{
    if (dir != nullptr) {
        closedir(dir);
        dir = nullptr;
    }
    dir = opendir(path.c_str());
    if (dir == nullptr)
        throw IDirectoryLister::OpenFailureException();
    _hidden = hidden;
    return true;
}

std::string SafeDirectoryLister::get()
{
    if (dir == nullptr)
        throw IDirectoryLister::OpenFailureException();
    struct dirent* entry;
    entry = readdir(dir);
    if (entry == nullptr)
        throw IDirectoryLister::NoMoreFileException();
    std::string name(entry->d_name);
    while (name[0] == '.' && !_hidden) {
        entry = readdir(dir);
        if (entry == nullptr)
            throw IDirectoryLister::NoMoreFileException();
        name = entry->d_name;
    }
    return name;
}
