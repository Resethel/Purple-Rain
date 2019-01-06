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
    , mGravity(1)
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
        Drop::Ptr dr(new Drop(Rd.rand(1,800), -Rd.rand(100,200), Rd.rand(0,20)));
        mDropArray.push_back(std::move(dr));
    }


    void Canvas::update()
    {
        for(int d(0) ; d < mDropAmount ; d++)
        {
            mDropArray[d]->fall(mGravity);

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
