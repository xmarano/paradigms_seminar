/*
** EPITECH PROJECT, 2025
** POOL DAY 07 am
** File description:
** ex00
*/
#include <iostream>
#include <string>
#include "WarpSystem.hpp"
#include "Borg.hpp"
#include "Destination.hpp"

#ifndef FEDERATION_HPP
#define FEDERATION_HPP

namespace Federation {
    namespace Starfleet {
        class Captain;

        class Ship {
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
                Destination _location;
                Destination _home;

            public:
                Ship(int length, int width, const std::string &name, short maxWarp);
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Captain *captain);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
        };

        class Captain {
            private:
                std::string _name;
                int _age;

            public:
                Captain(const std::string &name);
                std::string getName();
                int getAge();
                void setAge(int age);
        };

        class Ensign {
            private:
                std::string _name;

            public:
                Ensign(const std::string &name);
        };
    }

    class Ship {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;

        public:
            Ship(int length, int width, const std::string &name);
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
    };
}

#endif