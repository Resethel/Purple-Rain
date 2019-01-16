//
// Buutton.cpp
// Purple-Rain
//

#include "Button.hpp"

namespace GUI
{

////////// Constructor & Destructor

    Button::Button(const sf::Font& font)
    : mBody(sf::Vector2f(60,20))
    , mText("", font, 16)
    , mColor(sf::Color::Blue)
    {
        utils::centerOrigin<sf::RectangleShape>(mBody);
        mBody.setFillColor(mColor);
    }

    Button::~Button()
    {}

////////// Methods

    void Button::call()
    {
        if(mCallback)
            mCallback();
    }

    void Button::handleEvent(const sf::Event& event)
    {
        switch( event.type )
        {
            case sf::Event::MouseLeft:
                deselect();
                break;

            case sf::Event::MouseMoved:
                // Check if the mouse is inside of the buttons bounds.
                if(this->contains(event.mouseMove.x, event.mouseMove.y))
                {
                    if(!isSelected()) // Check for entry event.
                        select();
                }
                else if(isSelected() and !isActive()) // Check for leave event.
                {
                    deselect();
                }
                break;

            case sf::Event::MouseButtonPressed:
                if(contains(event.mouseButton.x, event.mouseButton.y) and !isActive())
                {
                    activate();
                }
                break;

            case sf::Event::MouseButtonReleased:
                // Only process as a click when mouse button has been pressed inside the widget before.
                if(isActive())
                {
                    // When released inside the widget, the event can be considered a click.
                    if(contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        deactivate();
                        call();
                        select();
                    }
                    else
                    {
                        deactivate();
                        deselect();
                    }

                }
                break;

            case sf::Event::KeyPressed:
                if( isSelected() and event.key.code == sf::Keyboard::BackSpace)
                {
                    activate();
                }
                break;

            case sf::Event::KeyReleased:
                if( isSelected() and isActive())
                {
                    if(event.key.code == sf::Keyboard::BackSpace)
                    {
                        deactivate();
                        call();
                    }
                }
                break;

            default:
                break;
        }
    }


    void Button::activate()
    {
        Component::activate();

        HSL col(TurnToHSL(mColor));
        col.Luminance -= 10;

        mBody.setFillColor(col.TurnToRGB());
        // TODO: change sprite
    }

    void Button::deactivate()
    {
        Component::deactivate();
        mBody.setFillColor(mColor);
        // TODO: change color
    }

    void Button::select()
    {
        Component::select();

        HSL col(TurnToHSL(mColor));
        col.Luminance += 20;

        mBody.setFillColor(col.TurnToRGB());
    }

    void Button::deselect()
    {
        Component::deselect();
        mBody.setFillColor(mColor);
    }

////////// Getters

    bool Button::isSelectable() const
    {
        return true;
    }

    sf::FloatRect Button::getBounds() const
    {
        return this->getTransform().transformRect(mBody.getGlobalBounds());
    }

////////// Setters


    void Button::setCallback(Callback callback)
    {
        mCallback = std::move(callback);
    }

    void Button::setColor(const sf::Color& color)
    {
        mColor = color;
        mBody.setFillColor(mColor);
    }

    void Button::setSize(const sf::Vector2f& size)
    {
        mBody.setSize(size);
        utils::centerOrigin<sf::RectangleShape>(mBody);
    }

    void Button::setText(const std::string& text)
    {
        mText.setString(text);
        utils::centerOrigin<sf::Text>(mText);
    }

    void Button::setCharacterSize(const int& size)
    {
        mText.setCharacterSize(size);
        utils::centerOrigin<sf::Text>(mText);
    }

////////// Draw

    void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= this->getTransform();

        target.draw(mBody, states);
        target.draw(mText, states);
    }


}
