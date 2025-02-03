/*
** EPITECH PROJECT, 2025
** POOL DAY 11
** File description:
** ex00
*/
#include "IDirectoryLister.hpp"

IDirectoryLister::OpenFailureException::OpenFailureException()
{
    errorMessage = strerror(errno);
}

const char *IDirectoryLister::OpenFailureException::what() const noexcept
{
    return errorMessage.c_str();
}

const char* IDirectoryLister::NoMoreFileException::what() const noexcept
{
    return "End of stream";
}
