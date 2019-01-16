//
// Component.hpp
// Purple-Rain
//

#ifndef GUI_COMPONENT_HPP
#define GUI_COMPONENT_HPP

#include <utility>

#include <SFML/Graphics.hpp>

namespace GUI
{



    class Component : public sf::Drawable
                    , public sf::Transformable
                    , public sf::NonCopyable
    {
    public:

        typedef std::shared_ptr<Component> Ptr;

    public:

                 Component();
        virtual ~Component();

        // Methods
        bool            contains(const float& x, const float& y);
        virtual void    handleEvent(const sf::Event& event) =0;

        virtual void    activate();
        virtual void    deactivate();

        virtual void    select();
        virtual void    deselect();

        // Getters

        bool            isActive() const;

        virtual bool    isSelectable() const =0;
        bool            isSelected() const;

        virtual sf::FloatRect  getBounds() const =0;

    private:

        bool    mIsSelected;
        bool    mIsActive;

    };



}


#endif // GUI_COMPONENTS_HPP
