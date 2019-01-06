//
// Drop.hpp
// Purple-Rain
//
// Ollando Raphaël
//

#include "Drop.hpp"

namespace rain
{
    Drop::Drop(unsigned x, int y, unsigned depth)
    : mDepth(depth)
    , mYSpeed(depth)
    , mBody(sf::Vector2f(3, 20))
    {
        mBody.setPosition(x,y);
        mBody.setFillColor(rainDropColor);
    }

    Drop::~Drop()
    {}


    void Drop::fall(int gravity)
    {
        mBody.move(0,mYSpeed);
        mYSpeed += gravity;
    }

    sf::Vector2f Drop::getPosition() const
    {
        return mBody.getPosition();
    }


    void Drop::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(mBody, states);
    }

}
