/*
** EPITECH PROJECT, 2025
** POOL DAY 06
** File description:
** ex04
*/
#include "Assistant.hpp"

Assistant::Assistant(int id) : id(id)
{
    std::cout << "Assistant " << id << ": 'morning everyone *sip coffee*\n";
}

Assistant::~Assistant()
{
    std::cout << "Assistant " << id << ": see you tomorrow at 9.00 *sip coffee*\n";
}

void Assistant::giveDrink(Student *student, std::string drink)
{
    std::cout << "Assistant " << id << ": drink this, " << student->getName() << " *sip coffee*\n";
    student->drink(drink);
}

std::string Assistant::readDrink(std::string studentName)
{
    std::string filename = studentName + ".drink";
    std::ifstream file(filename);

    if (!file.is_open())
        return "";

    std::string drink;
    std::getline(file, drink);
    std::cout << "Assistant " << id << ": " << studentName << " needs a " << drink << " *sip coffee*\n";
    file.close();
    std::remove(filename.c_str());
    return drink;
}

void Assistant::helpStudent(Student *student)
{
    std::string drink = readDrink(student->getName());

    if (!drink.empty()) {
        giveDrink(student, drink);
        student->drink(drink);
    } else {
        std::cout << "Assistant " << id << ": " << student->getName() << " seems fine *sip coffee*\n";
    }
}

void Assistant::timeCheck()
{
    if (!isWorking) {
        isWorking = true;
        std::cout << "Assistant " << id << ": Time to teach some serious business *sip coffee*\n";
    } else {
        isWorking = false;
        std::cout << "Assistant " << id << ": Enough teaching for today *sip coffee*\n";
    }
}
