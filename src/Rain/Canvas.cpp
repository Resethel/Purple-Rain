//
// Canvas.cpp
// Purple-Rain
//
// Ollando Raphaël
//

#include "Canvas.hpp"

namespace rain
{

////////// Declaration & Destructor

    Canvas::Canvas()
    : mDensity(1)
    , mGravity(1.f)
    , mRunning(true)
    {}

    Canvas::~Canvas()
    {}

////////// Methods

    void Canvas::addRainDrop()
    {
        Drop::Ptr dr(new Drop(Rd.rand(1,800), -Rd.rand(100, 300), Rd.rand(1,20)));
        mDropArray.push_back(std::move(dr));
    }

    void Canvas::clear()
    {
        mDropArray.clear();
    }


    void Canvas::update(sf::Time dt)
    {
        if(isRunning()) // Updating only when the simulation is running...
        {
            for(int d(0) ; d < mDropArray.size() ; d++)
            {
                mDropArray[d]->fall(mGravity, dt);

                if(mDropArray[d]->getPosition().y > 600.f)
                    mDropArray.erase(mDropArray.begin() + d);

            }

            // We add rain drops depending on the density and a gravity correction
            // factor . Note that, since we use float value, we don't care about a
            // "division by 0" induced crash... No matter what mathematicians would say)
            float d = this->mDensity / ( 5.f - this->mGravity);
            char it(0);
            while(d > 1.f and it < CONSTANTS::MAX_DROP_PER_ITERATION - 1)
            {
                addRainDrop();
                --d;
                ++it;
            }

            if(Rd.rand(1,100) > (1 - mDensity) * 100.f)
                addRainDrop();

        }

    }

////////// Setters

    void Canvas::start()
    {
        this->mRunning = true;
    }


    void Canvas::stop()
    {
        this->mRunning = false;
    }


    void Canvas::setDensity(float density)
    {
        this->mDensity = utils::clamp<float>(density, 0.f, 5.f);
    }


    void Canvas::setGravity(float gravity)
    {
        this->mGravity = utils::clamp<float>(gravity, 0.f, 5.f);
    }

///////// Getters

    bool Canvas::isRunning() const
    {
        return this->mRunning;
    }


    float Canvas::getDensity() const
    {
        return this->mDensity;
    }


    float Canvas::getGravity() const
    {
        return this->mGravity;
    }

////////// Draw

    void Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for(auto& d : mDropArray)
        {
            target.draw(*d);
        }
    }



}
