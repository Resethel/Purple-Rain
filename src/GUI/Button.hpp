//
// Button.hpp
// Purple-Rain
//

#ifndef GUI_BUTTON_HPP
#define GUI_BUTTON_HPP

#include <functional>
#include <utility>
#include <SFML/Graphics.hpp>

#include "../HSL.hpp"
#include "../Utils.hpp"
#include "Component.hpp"

namespace GUI
{



    class Button : public Component
    {
    public:

        typedef std::shared_ptr<Button> Ptr;
        typedef std::function<void()> Callback;

    public:

                Button(const sf::Font& font);
        virtual ~Button();

        // Methods
        void            call();
        virtual void	handleEvent(const sf::Event& event);

        virtual void    activate();
        virtual void    deactivate();

        virtual void    select();
        virtual void    deselect();

        // Getters
        virtual bool            isSelectable() const;
        virtual sf::FloatRect   getBounds() const;

        // Setters

        void	setCallback(Callback callback);
        void    setColor(const sf::Color& color);
        void    setSize(const sf::Vector2f& size);
        void	setText(const std::string& text);
        void	setCharacterSize(const int& size);

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:

        sf::RectangleShape  mBody;
        sf::Text            mText;

        Callback            mCallback;
        sf::Color           mColor;


    };


}


#endif // GUI_BUTTON_HPP
