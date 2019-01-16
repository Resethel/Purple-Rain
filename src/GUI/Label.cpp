//
// Label.cpp
// Purple-Rain
//

#include "Label.hpp"

namespace GUI
{

    Label::Label(const std::string& text, const sf::Font& fonts)
    : mText(text, fonts, 16)
    {
        utils::centerOrigin(mText);
    }

////////// Methods

    void Label::setText(const std::string& text)
    {
        mText.setString(text);
        utils::centerOrigin(mText);
    }

    void Label::handleEvent(const sf::Event&)
    {}

    sf::FloatRect Label::getBounds() const
    {
        return this->getTransform().transformRect(mText.getGlobalBounds());
    }

////////// Getters

    bool Label::isSelectable() const
    {
        return false;
    }

////////// Setters

    void Label::setCharacterSize(const int& size)
    {
        mText.setCharacterSize(size);
        utils::centerOrigin(mText);
    }

    void Label::setFillColor(const sf::Color& color)
    {
        mText.setFillColor(color);
    }

    void Label::setOutlineColor(const sf::Color& color)
    {
        mText.setOutlineColor(color);
    }

    void Label::setOutlineThickness(const float& thickness)
    {
        mText.setOutlineThickness(utils::clamp<float>(thickness,0,10));
        utils::centerOrigin<sf::Text>(mText);
    }

////////// Draw

    void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= this->getTransform();
        target.draw(mText, states);
    }



}
