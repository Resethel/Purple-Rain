//
// Interface.hpp
// Purple-Rain
//


/* An interface is like a 3-layer canvas.
 * A background surface
 * a content surface
 * a control surface.
 * the layer might be implemented later on
 */
#include <utility>
#include <vector>

#include "Component.hpp"

namespace GUI
{
    class Interface : public Component
    {
    public:

        typedef std::shared_ptr<Interface> Ptr;
        enum Layer { background, content, control };

    public:

                Interface();
        virtual ~Interface();

        // Methods
        virtual void    handleEvent(const sf::Event& event);
        void            pack(Component::Ptr component, const Layer& layer = content);

        // Getters
        virtual bool            isSelectable() const;
        virtual sf::FloatRect   getBounds() const;

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:

        std::vector<Component::Ptr> mChildren;

    };
}
