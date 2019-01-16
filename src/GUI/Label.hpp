//
// Label.hpp
// Purple-Rain
//

#ifndef GUI_LABEL_HPP
#define GUI_LABEL_HPP


#include <SFML/Graphics.hpp>

#include "../Utils.hpp"
#include "Component.hpp"

namespace GUI
{

    class Label : public Component
    {
    public:

            typedef std::shared_ptr<Label> Ptr;

    public:

        Label(const std::string& text, const sf::Font& fonts);

        // Methods

        void			setText(const std::string& text);
        virtual void	handleEvent(const sf::Event& event);

        // Getters
        virtual bool            isSelectable() const;
        virtual sf::FloatRect   getBounds() const;

        // Setters
        void    setCharacterSize(const int& size);
        void    setFillColor(const sf::Color& color);
        void    setOutlineColor(const sf::Color& color);
        void    setOutlineThickness(const float& thickness);

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:

        sf::Text			mText;

    };

}

#endif // GUI_LABEL_HPP
