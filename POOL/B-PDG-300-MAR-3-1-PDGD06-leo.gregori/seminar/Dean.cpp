/*
** EPITECH PROJECT, 2025
** POOL DAY 06
** File description:
** Dean.cpp
*/
#include "Dean.hpp"

Dean::Dean(const std::string &name) : name(name), isWorking(false)
{
    std::cout << "Dean " << name << ": I'm Dean " << name << "! How do you do, fellow kids?\n";
}

Dean::~Dean()
{
    std::cout << "Dean " << name << ": Time to go home.\n";
}

void Dean::teachStudent(Student *student, const std::string &lesson)
{
    if (!student->learn(lesson)) {
        std::cout << "Dean " << name << ": All work and no play makes " << student->getName()
                  << " a dull student.\n";
        std::string filename = student->getName() + ".drink";
        std::ofstream file(filename);
        if (file.is_open()) {
            file << getRandomDrink();
            file.close();
        } else {
            std::cerr << "Dean " << name << ": Failed to write report for " << student->getName() << ".\n";
        }
    }
}

void Dean::timeCheck()
{
    if (!isWorking) {
        isWorking = true;
        std::cout << "Dean " << name << ": Where is everyone?\n";
    } else {
        isWorking = false;
        std::cout << "Dean " << name << ": Don't forget to close the windows when you leave.\n";
    }
}

std::string Dean::getRandomDrink() const
{
    const std::string drinks[] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};
    return drinks[std::rand() % 5];
}
