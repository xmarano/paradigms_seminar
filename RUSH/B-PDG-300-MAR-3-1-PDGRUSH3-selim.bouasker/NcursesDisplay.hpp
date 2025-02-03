/*
** EPITECH PROJECT, 2025
** RUSH 3
** File description:
** HPP
*/
#include "Modules.hpp"

#pragma once

class NcursesDisplay : public Krell1::Display {
    public:
        void init() override;
        void render(const std::vector<Krell1::Module*>& modules) override;
};
