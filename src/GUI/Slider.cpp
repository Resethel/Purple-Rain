//
// Slider.cpp
// Purple-Rain
//

#include "Slider.hpp"

namespace GUI
{

////////// Constructor & Destructor

    Slider::Slider()
    : mBody(sf::Vector2f(0,0))
    , mSlider(sf::Vector2f(0,0))
    , mTitle()
    , mMinValue(0)
    , mMaxValue(100)
    , mDisplayTitle(true)
    , mMinorStep(15)
    , mDragOffset(0)
    {
        utils::centerOrigin<sf::RectangleShape>(mBody);
        utils::centerOrigin<sf::RectangleShape>(mSlider);
        mBody.setFillColor(mColor);
        mSlider.setFillColor(mColor);
    }

    Slider::~Slider()
    {}

////////// Methods

    void Slider::handleEvent(const sf::Event& event)
    {
        switch( event.type )
        {
            case sf::Event::MouseLeft:
                deselect();
                break;

            case sf::Event::MouseMoved:
                // Check if the mouse is inside of the buttons bounds.
                if(getSliderBounds().contains(event.mouseMove.x, event.mouseMove.y))
                {
                    if(!isSelected()) // Check for entry event.
                        select();
                }
                else if(isSelected() and !isActive()) // Check for leave event.
                {
                    deselect();
                }
                else if(isActive()) // mouving the slider.
                {
                    int x = event.mouseMove.x;
                    //int y = event.mouseMove.y;

                    auto steps = (mMaxValue - mMinValue)/mMinorStep;
                    auto sliderRect = getSliderBounds();

                    auto sliderCenterX = sliderRect.left + sliderRect.width/2.f;
		            auto stepDistance = (getBounds().width - sliderRect.width) / steps;
		            auto delta = static_cast<float>(x) - sliderCenterX;// - mDragOffset;

                    while(delta < (-stepDistance/2))
                    {
			           //mSlider.move(-stepDistance,0);
                       setValue(getValue() - mMinorStep);
                       delta += stepDistance;
                    }

		            while(delta > (stepDistance/2))
                    {
                        //mSlider.move(stepDistance,0);
                        setValue(getValue() + mMinorStep);
                        delta -= stepDistance;
		            }

                }
                break;

            case sf::Event::MouseButtonPressed:
                if(getSliderBounds().contains(event.mouseButton.x, event.mouseButton.y) and !isActive())
                {
                    activate();
                    // calculate drag offset
                    auto x = event.mouseButton.x;
                    mDragOffset = static_cast<float>(x) - getSliderBounds().left + getSliderBounds().width/2.f;
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
                    }
                }
                break;

            default:
                break;
        }
    }

    void Slider::activate()
    {
        Component::activate();

        HSL col(TurnToHSL(mColor));
        col.Luminance -= 10;

        mSlider.setFillColor(col.TurnToRGB());
        // TODO: change sprite
    }

    void Slider::deactivate()
    {
        Component::deactivate();
        mSlider.setFillColor(mColor);
        // TODO: change sprite
    }

    void Slider::select()
    {
        Component::select();

        HSL col(TurnToHSL(mColor));
        col.Luminance += 20;

        mSlider.setFillColor(col.TurnToRGB());
    }

    void Slider::deselect()
    {
        Component::deselect();
        mSlider.setFillColor(mColor);
    }

////////// Getters

    bool Slider::isSelectable() const
    {
        return true;
    }

    sf::FloatRect Slider::getBounds() const
    {
        sf::FloatRect bounds;
        bounds = mBody.getGlobalBounds();
        bounds.height = mSlider.getGlobalBounds().height;

        return this->getTransform().transformRect(bounds);
    }

    int Slider::getValue() const
    {
        return mValue;
    }

////////// Setters

    void Slider::displayTitle(const bool& display)
    {
        mDisplayTitle = display;
    }

    void Slider::setColor(const sf::Color& color)
    {
        mColor = color;

        HSL bodyColor = TurnToHSL(color);
        HSL outlineColor = TurnToHSL(color);

        bodyColor.Luminance -= 20;
        outlineColor.Luminance -= 40;

        mBody.setFillColor(bodyColor.TurnToRGB());
        mBody.setOutlineColor(outlineColor.TurnToRGB());

        outlineColor.Luminance += 20;

        mSlider.setFillColor(mColor);
        mSlider.setOutlineColor(outlineColor.TurnToRGB());
    }

    void Slider::setSize(const sf::Vector2f& size)
    {
        auto bodySize = size;
        bodySize.y *= 2/5.f;
        mBody.setSize(bodySize);

        auto sliderSize = size;
        sliderSize.x /= 10.f;
        mSlider.setSize(sliderSize);

        mBody.setOutlineThickness(std::ceil(bodySize.y/20.f));
        mSlider.setOutlineThickness(std::ceil(bodySize.y/20.f));

        utils::centerOrigin<sf::RectangleShape>(mBody);
        utils::centerOrigin<sf::RectangleShape>(mSlider);
        positionTitle();

    }

    void Slider::setStep(const int& step)
    {
        mMinorStep = step;
    }

    void Slider::setRange(const int& min, const int& max)
    {
        mMinValue = min;
        mMaxValue = max;
    }

    void Slider::setTitleFont(const sf::Font &font)
    {
        mTitle.setFont(font);
        positionTitle();
    }

    void Slider::setTitleCharacterSize(const unsigned& size)
    {
        mTitle.setCharacterSize(size);
        positionTitle();
    }

    void Slider::setTitleString(const std::string& text)
    {
        mTitle.setString(text);
        positionTitle();
    }

    void Slider::setValue(const int& value)
    {
	    mValue = utils::clamp<int>(value, mMinValue, mMaxValue);

        auto step = (getBounds().width - getSliderBounds().width) / (mMaxValue - mMinValue);
        mSlider.setPosition(mBody.getGlobalBounds().left + getSliderBounds().width/2.f + mValue*step , 0);
    }

////////// Internal Handling

    sf::FloatRect Slider::getSliderBounds() const
    {
        return this->getTransform().transformRect(mSlider.getGlobalBounds());
    }

    void Slider::positionTitle()
    {
        if(mTitle.getFont())
        {
            utils::centerOrigin<sf::Text>(mTitle);
            auto origin = mTitle.getOrigin();
            auto height = mTitle.getGlobalBounds().height;
            mTitle.setOrigin(0, origin.y);


            mTitle.setPosition(-mBody.getOrigin().x, -((getBounds().height + height)/2.f + 5));

        }
    }

////////// Draw

    void Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= this->getTransform();

        target.draw(mBody, states);
        target.draw(mSlider, states);

        if(mDisplayTitle)
            target.draw(mTitle, states);
    }


}
