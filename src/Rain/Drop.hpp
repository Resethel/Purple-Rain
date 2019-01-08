//
// Drop.hpp
// Purple-Rain
//
// Ollando Raphaël
//

#ifndef DROP_HPP
#define DROP_HPP

#include <random>
#include <utility>

#include <SFML/Graphics.hpp>

#include "../Constants.hpp"
#include "../Utils.hpp"

const sf::Color backgroundColor(230,230,250);
const sf::Color rainDropColor(138, 43, 226);

namespace rain
{

    class Drop : public sf::Drawable
    {
    public:

        typedef std::unique_ptr<Drop> Ptr;

    public:

        // Declarations & Destructor

        Drop(unsigned x, int y, unsigned depth);
        virtual ~Drop();

        // Methods

        void fall(float fact, sf::Time dt);

        // Getters

        sf::Vector2f getPosition() const;

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:

        unsigned    mYSpeed;
        unsigned    mDepth;

        sf::RectangleShape  mBody;

    };

}

#endif // DROP_HPP
