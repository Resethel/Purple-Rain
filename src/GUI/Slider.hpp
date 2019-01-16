//
// Slider.hpp
// Purple-Rain
//

#ifndef GUI_SLIDER_HPP
#define GUI_SLIDER_HPP

#include <cmath>
#include <utility>
#include <SFML/Graphics.hpp>

#include "../HSL.hpp"
#include "../Utils.hpp"
#include "Component.hpp"

namespace GUI
{



    class Slider : public Component
    {
    public:

        typedef std::shared_ptr<Slider> Ptr;

    public:
        
        // Constructor & Destructor
                 Slider();
        virtual ~Slider();

        // Methods
        virtual void	handleEvent(const sf::Event& event);

        virtual void    activate();
        virtual void    deactivate();

        virtual void    select();
        virtual void    deselect();

        // Getters
        virtual bool            isSelectable() const;
        virtual sf::FloatRect   getBounds() const;

        int                     getValue() const;

        // Setters
        void    displayTitle(const bool& display);
        void    setColor(const sf::Color& color);
        void    setRange(const int& min, const int& max);
        void    setSize(const sf::Vector2f& size);
        void	setStep(const int& step);
        void    setTitleFont(const sf::Font& font);
        void    setTitleCharacterSize(const unsigned& size);
        void    setTitleString(const std::string& text);
        void    setValue(const int& value);

    protected:

        // Internal Handling Methods
        sf::FloatRect   getSliderBounds() const;
        void            positionTitle();

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:

        sf::RectangleShape  mBody;
        sf::RectangleShape  mSlider;
        sf::Text            mTitle;
        sf::Color           mColor;

        int                 mMinValue;
        int                 mMaxValue;
        int                 mValue;

        bool                mDisplayTitle;
        float               mMinorStep;
        float               mDragOffset;

    };


}


#endif // GUI_SLIDER_HPP
