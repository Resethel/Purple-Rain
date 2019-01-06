//
// Utils.hpp
// Purple-Rain
//
// Ollando Raphaël
//
#ifndef UTILS_HPP
#define UTILS_HPP

#include <random>

namespace utils
{

    class Randomizer
    {
    public:
        // The private constructor so that the user can not directly instantiate
        Randomizer();

        int rand(unsigned floor, unsigned ceil);

    private:
        std::mt19937 _rng;

    };

} // utils

#endif // UTILS_HPP
