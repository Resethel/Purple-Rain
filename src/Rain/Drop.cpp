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
    , mYSpeed(utils::map(depth, 0, 20, 1, 20))
    , mBody(sf::Vector2f(utils::map(depth, 0, 20, 1, 5),
                         utils::map(depth, 0, 20, 10, 20)))
    {
        mBody.setPosition(x,y);
        mBody.setFillColor(rainDropColor);
    }

    Drop::~Drop()
    {}


    void Drop::fall(int gravity, sf::Time dt)
    {
        mBody.move(0,mYSpeed * dt.asSeconds());
        mYSpeed += utils::map(this->mDepth, 0, 20, 0.5, 1)*gravity;
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
