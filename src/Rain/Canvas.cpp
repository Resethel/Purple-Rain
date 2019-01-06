//
// Canvas.cpp
// Purple-Rain
//
// Ollando Raphaël
//

#include "Canvas.hpp"

namespace rain
{

    Canvas::Canvas()
    : mDropAmount(500)
    , mGravity(12)
    {

        for(int d(0) ; d < mDropAmount ; d++)
        {
            this->addRainDrop();
        }

    }

    Canvas::~Canvas()
    {}

    void Canvas::addRainDrop()
    {
        Drop::Ptr dr(new Drop(Rd.rand(1,800), -Rd.rand(100,300), Rd.rand(1,20)));
        mDropArray.push_back(std::move(dr));
    }


    void Canvas::update(sf::Time dt)
    {
        for(int d(0) ; d < mDropAmount ; d++)
        {
            mDropArray[d]->fall(mGravity, dt);

            if(mDropArray[d]->getPosition().y > 600.f)
            {
                mDropArray.erase(mDropArray.begin() + d);
                this->addRainDrop();

            }

        }

    }




    void Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for(auto& d : mDropArray)
        {
            target.draw(*d);
        }
    }



}
