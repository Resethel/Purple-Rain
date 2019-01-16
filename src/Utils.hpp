//
// Utils.hpp
// Purple-Rain
//

#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>
#include <random>

#include <SFML/Graphics.hpp>

namespace utils
{

    inline float map(float value, float istart, float istop, float ostart, float ostop)
    {
	   return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
   }

   template <typename T>
   inline T clamp(const T& n, const T& lower, const T& upper)
   {
       return std::max(lower, std::min(n, upper));
   }


   template <typename T>
   inline void centerOrigin(T& object)
   {
       auto bounds = object.getLocalBounds();
       object.setOrigin(bounds.width/2.f, bounds.height/2.f);
   }



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
