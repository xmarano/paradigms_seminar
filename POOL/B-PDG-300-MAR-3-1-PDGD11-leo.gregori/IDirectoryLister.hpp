/*
** EPITECH PROJECT, 2025
** POOL DAY 11
** File description:
** ex00
*/
#include <dirent.h>
#include <iostream>
#include <cstring>
#include <string>
#include <exception>
#include <utility>

#pragma once

class IDirectoryLister {
    public:
        virtual ~IDirectoryLister() = default;
        virtual bool open(const std::string &path, bool hidden) = 0;
        virtual std::string get() = 0;

    class OpenFailureException : public std::exception {
        private:
            std::string errorMessage;

        public:
            OpenFailureException();
            const char *what() const noexcept override;
    };

    class NoMoreFileException : public std::exception {
        public:
            const char* what() const noexcept override;
    };
};
