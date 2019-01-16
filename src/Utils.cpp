//
// Utils.cpp
// Purple-Rain
//

#include "Utils.hpp"


namespace utils
{
    Randomizer::Randomizer()
    {
        this->_rng = std::mt19937();
    }

    int Randomizer::rand(unsigned floor, unsigned ceil)
    {
        std::uniform_int_distribution<std::mt19937::result_type> rand_(floor,ceil);
        return rand_(_rng);
    }


}
