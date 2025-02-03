/*
** EPITECH PROJECT, 2025
** POOL DAY 07 am
** File description:
** ex01
*/
#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

#ifndef BORG_HPP
#define BORG_HPP

namespace Borg {
    class Ship {
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _home;
            Destination _location;

        public:
            Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
    };
}

#endif