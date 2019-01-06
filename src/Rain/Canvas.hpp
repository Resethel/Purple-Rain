//
// Canvas.hpp
// Purple-Rain
//
// Ollando Raphaël
//

#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <random>
#include <vector>

#include "Drop.hpp"
#include "../Utils.hpp"

namespace rain
{

    class Canvas : public sf::Drawable
    {
    public:

        Canvas();
        virtual ~Canvas();

        void addRainDrop();
        void update(sf::Time dt);

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:

        unsigned    mDropAmount;
        unsigned    mGravity;

        std::vector<Drop::Ptr> mDropArray;

        utils::Randomizer Rd;

    };


}


#endif // CANVAS_HPP
