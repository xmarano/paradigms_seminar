/*
** EPITECH PROJECT, 2025
** POOL DAY 06
** File description:
** ex04
*/
#include "Student.hpp"

#ifndef ASSISTANT_HPP
#define ASSISTANT_HPP

class Assistant {
    private:
        int id;
        bool isWorking;

    public:
        Assistant(int id);
        ~Assistant();
        void giveDrink(Student *student, std::string drink);
        std::string readDrink(std::string studentName);
        void helpStudent(Student *student);
        void timeCheck();
};

#endif
