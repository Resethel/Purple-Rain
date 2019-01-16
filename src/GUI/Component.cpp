//
// Component.cpp
// Purple-Rain
//

#include "Component.hpp"

namespace GUI
{

////////// Constructor & Destructor

        Component::Component()
        : mIsSelected(false)
        , mIsActive(false)
        {}

        Component::~Component()
        {}


////////// Methods

        bool Component::contains(const float& x, const float& y)
        {
            return this->getBounds().contains(static_cast<float>(x),
                                              static_cast<float>(y));
        }

        void Component::activate()  { mIsActive = true; }
        void Component::deactivate(){ mIsActive = false; }

        void Component::select()    { mIsSelected = true; }
        void Component::deselect()  { mIsSelected = false; }

////////// Getters

        bool Component::isActive() const
        {
            return mIsActive;
        }

        bool Component::isSelected() const
        {
            return mIsSelected;
        }


    }
