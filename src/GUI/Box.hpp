//
// Box.hpp
// Purple-Rain
//

#ifndef GUI_BOX_HPP
#define GUI_BOX_HPP

#include <utility>

#include <SFML/Graphics.hpp>

#include "Component.hpp"
#include "../Utils.hpp"

namespace GUI
{



    class Box : public Component
    {
    public:

        typedef std::shared_ptr<Box> Ptr;

    public:

        Box(const unsigned& w, const unsigned& h, const sf::Color& color = sf::Color::Red);

        // Methods
        virtual void	handleEvent(const sf::Event& event);

        // Getters
        virtual bool    isSelectable() const;

        virtual sf::FloatRect getBounds() const;

        // Setters
        void    setColor(const sf::Color& color);
        void    setSize(const sf::Vector2f& size);


    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:

        sf::RectangleShape  mBody;

    };


}


#endif // GUI_BOX_HPP
