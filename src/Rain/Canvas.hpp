//
// Canvas.hpp
// Purple-Rain
//

#ifndef RAIN_CANVAS_HPP
#define RAIN_CANVAS_HPP

#include <random>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Drop.hpp"
#include "../Constant.hpp"
#include "../Utils.hpp"

namespace rain
{

    class Canvas : public sf::Drawable
    {
    public:

        // Declarations & Destructor

        Canvas();
        virtual ~Canvas();

        // Methods

        void addRainDrop();
        void clear();

        void update(sf::Time dt);

        // Setters

        void start();
        void stop();

        void setDensity(float density);
        void setGravity(float gravity);

        // Getters

        bool isRunning() const;

        float getDensity() const;
        float getGravity() const;

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:

        float    mDensity;
        float    mGravity;

        bool    mRunning;

        std::vector<Drop::Ptr> mDropArray;
        utils::Randomizer Rd;

    };

}


#endif // RAIN_CANVAS_HPP
