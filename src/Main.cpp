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



int main(int argc, char** argv)
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Purple Rain");
    window.setFramerateLimit(10);

    rain::Canvas can;

    // run the program as long as the window is open
    while (window.isOpen())
    {

        can.update();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(backgroundColor);

        // draw everything here...
        window.draw(can);

        // end the current frame
        window.display();
    }

    return 0;
}
