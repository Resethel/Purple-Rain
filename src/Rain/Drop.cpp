//
// Drop.hpp
// Purple-Rain
//
// Ollando Raphaël
//

#include "Drop.hpp"

namespace rain
{

////////// Declarations & Destructor

    Drop::Drop(unsigned x, int y, unsigned depth)
    : mYSpeed(utils::map(depth, 0, 20, 1, 20))
    , mDepth(depth)
    , mBody(sf::Vector2f(utils::map(depth, 0, 20, 1, 5),
                         utils::map(depth, 0, 20, 10, 20)))
    {
        // Sets the origin at the center of the drop
        auto bounds = mBody.getLocalBounds();
        mBody.setOrigin(bounds.width/2.f, bounds.height/2.f);


        mBody.setPosition(x,y);
        mBody.setFillColor(rainDropColor);
    }

    Drop::~Drop()
    {}


////////// Methods

    void Drop::fall(float fact, sf::Time dt)
    {
        mBody.move(0,mYSpeed * dt.asSeconds());
        mYSpeed += utils::map(this->mDepth, 0, 20, 0.4, 1) *
                            fact * CONSTANTS::CANVAS_GRAVITY;
    }

////////// Getters

    sf::Vector2f Drop::getPosition() const
    {
        return mBody.getPosition();
    }

////////// Draw

    void Drop::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(mBody, states);
    }

}
