/*
** EPITECH PROJECT, 2025
** POOL DAY 06
** File description:
** Dean.hpp
*/
#include "Assistant.hpp"

#ifndef DEAN_HPP
#define DEAN_HPP

class Dean {
    private:
        std::string name;
        bool isWorking;

    public:
        Dean(const std::string &name);
        ~Dean();
        std::string getRandomDrink() const;
        void teachStudent(Student *student, const std::string &lesson);
        void timeCheck();
};

#endif
