/*
** EPITECH PROJECT, 2025
** POOL DAY 06
** File description:
** ex03
*/
#include "Student.hpp"

void Student::setName(std::string name)
{
    this->name = name;
}

std::string Student::getName()
{
    return (this->name);
}

Student::Student(const std::string &name)
{
    energy = 100;
    setName(name);
    std::cout << "Student " << name << ": I'm ready to learn C++.\n";
}

Student::~Student()
{
    std::cout << "Student " << name << ": Wow, much learning today, very smart, such C++.\n";
}

bool Student::learn(const std::string &text)
{
    if (energy < 42) {
        std::string modified_text = text;
        int pos = 0;

        while ((pos = modified_text.find("C++", pos)) != std::string::npos) {
            modified_text.replace(pos, 3, "shit");
            pos += 4;
        }
        std::cout << "Student " << name << ": " << modified_text << std::endl;
        return false;
    }
    std::cout << "Student " << name << ": " << text << std::endl ;
    energy -= 42;
    return true;
}

void Student::drink(const std::string &drink)
{
    if (drink == "Red Bull"){
        std::cout << "Student " << name << ": Red Bull gives you wings!\n";
        energy += 32;
    } else if (drink == "Monster"){
        std::cout << "Student " << name << ": Unleash The Beast!\n";
        energy += 64;
    } else {
        std::cout << "Student " << name << ": ah, yes... enslaved moisture.\n";
        energy += 1;
    }
    if (energy > 100)
        energy = 100;
}
