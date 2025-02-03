/*
** EPITECH PROJECT, 2025
** POOL DAY 07 am
** File description:
** ex00
*/

#ifndef WARPSYSTEM_HPP
#define WARPSYSTEM_HPP

namespace WarpSystem {
    class QuantumReactor {
        private:
            bool _stability;

        public:
            QuantumReactor();
            bool isStable();
            void setStability(bool stability);
    };

    class Core {
        private:
            QuantumReactor *_coreReactor;

        public:
            Core(QuantumReactor *coreReactor);
            QuantumReactor *checkReactor();
    };
}

#endif
