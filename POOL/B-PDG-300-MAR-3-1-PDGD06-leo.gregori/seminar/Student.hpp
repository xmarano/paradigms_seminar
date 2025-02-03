/*
** EPITECH PROJECT, 2025
** POOL DAY 06
** File description:
** ex03
*/
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#ifndef STUDENT_HPP
#define STUDENT_HPP

class Student {
    private:
        std::string name;
        int energy;

    public:
        Student(const std::string &name);
        ~Student();
        bool learn(const std::string &text);
        void drink(const std::string &drink);
        // Setter
        void setName(std::string name);
        // Getter
        std::string getName();
};

#endif
