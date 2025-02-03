/*
** EPITECH PROJECT, 2025
** POOL DAY 11
** File description:
** ex01
*/
#include "IDirectoryLister.hpp"

class SafeDirectoryLister : public IDirectoryLister {
    private:
        DIR *dir;
        bool _hidden;

    public:
        SafeDirectoryLister();
        SafeDirectoryLister(const std::string &path, bool hidden);
        virtual ~SafeDirectoryLister();

        bool open(const std::string &path, bool hidden) override;
        std::string get() override;
};
