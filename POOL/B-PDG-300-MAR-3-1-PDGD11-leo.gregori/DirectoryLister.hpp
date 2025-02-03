/*
** EPITECH PROJECT, 2025
** POOL DAY 11
** File description:
** ex00
*/
#include "IDirectoryLister.hpp"

#pragma once

class DirectoryLister : public IDirectoryLister {
    private:
        DIR *dir;
        bool _hidden;

    public:
        DirectoryLister();
        DirectoryLister(const std::string &path, bool hidden);
        virtual ~DirectoryLister();

        bool open(const std::string &path, bool hidden) override;
        std::string get() override;
};
