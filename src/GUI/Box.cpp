//
// Box.cpp
// Purple-Rain
//

#include "Box.hpp"

namespace GUI
{

////////// Constructor & Destructor

    Box::Box(const unsigned& w, const unsigned& h, const sf::Color& color)
    : mBody(sf::Vector2f(w,h))
    {
        utils::centerOrigin<sf::RectangleShape>(mBody);
        mBody.setFillColor(color);
    }

////////// Methods

    void Box::handleEvent(const sf::Event& event)
    {}

////////// Getters

    bool Box::isSelectable() const
    {
        return false;
    }

    sf::FloatRect Box::getBounds() const
    {
        return this->getTransform().transformRect(mBody.getLocalBounds());
    }

////////// Setters

    void Box::setColor(const sf::Color& color)
    {
        mBody.setFillColor(color);
    }

    void Box::setSize(const sf::Vector2f& size)
    {
        mBody.setSize(size);
        utils::centerOrigin<sf::RectangleShape>(mBody);
    }

////////// Draw

    void Box::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= this->getTransform();
        target.draw(mBody, states);
    }


}
