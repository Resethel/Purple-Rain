//
// Main.cpp
// Purple-Rain
//
// Ollando Raphaël
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "Rain/Canvas.hpp"
#include "Constants.hpp"


int main(int argc, char** argv)
{


    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Purple Rain", sf::Style::Close);

    rain::Canvas can;

    sf::Clock clock; // Used for delta timing
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // run the program as long as the window is open
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            // Modifying Canvas parameters
            if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::Up)
            {
                can.setDensity(can.getDensity() + 0.25f);
            }

            if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::Down)
            {
                can.setDensity(can.getDensity() - 0.25f);
            }

            if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::Right)
            {
                can.setGravity(can.getGravity() + 0.25f);
            }

            if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::Left)
            {
                can.setGravity(can.getGravity() - 0.25f);
            }

            if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::Space)
            {
                can.start();
            }

            if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::S)
            {
                can.stop();
            }

            if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::C)
            {
                can.clear();
            }
        }

        // Update cycle
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            can.update(TimePerFrame);
        }

        window.clear(backgroundColor);
        window.draw(can);

        // end the current frame
        window.display();
    }

    return 0;
}
