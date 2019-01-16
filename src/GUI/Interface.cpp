//
// Interface.cpp
// Purple-Rain
//

#include "Interface.hpp"

namespace GUI
{

////////// Constructor & Destructor

    Interface::Interface()
    : mChildren()
    {}

    Interface::~Interface()
    {}

////////// Methods

    void Interface::handleEvent(const sf::Event& event)
    {
        if(this->isActive())
        {
            // We create a copy of the event and transform mouse coordinates to the
            // interface coordinates if event is a mouse event.
            sf::Event localEvent(event);

            if(localEvent.type == sf::Event::MouseMoved)
            {
                localEvent.mouseMove.x -= static_cast<int>(getPosition().x);
                localEvent.mouseMove.y -= static_cast<int>(getPosition().y);
            }

            if(localEvent.type == sf::Event::MouseButtonPressed
                or localEvent.type == sf::Event::MouseButtonReleased)
            {
                localEvent.mouseButton.x -= static_cast<int>(getPosition().x);
                localEvent.mouseButton.y -= static_cast<int>(getPosition().y);
            }

            // Pass event to children.
            for(const auto& child : mChildren )
            {
                child->handleEvent(localEvent);
            }
        }
    }

    void Interface::pack(Component::Ptr component, const Layer &layer)
    {
        mChildren.push_back(component);
    }

////////// Getters

    bool Interface::isSelectable() const
    {
        return false;
    }

    sf::FloatRect Interface::getBounds() const
    {
        // TODO: Make the interface give an englobing rectangle of its children
        return sf::FloatRect(0,0,0,0);
    }

////////// Draw

    void Interface::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= this->getTransform();

        if(this->isActive())
        {
            for(const auto& child : mChildren)
            {
                target.draw(*child, states);
            }
        }
    }


}
