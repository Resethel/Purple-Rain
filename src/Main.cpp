//
// Main.cpp
// Purple-Rain
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "Rain/Canvas.hpp"
#include "Constant.hpp"

#include "GUI/Interface.hpp"
#include "GUI/Button.hpp"
#include "GUI/Label.hpp"
#include "GUI/Box.hpp"
#include "GUI/Slider.hpp"


int main(int argc, char** argv)
{

    // Frame Counting
    sf::Clock       fpsClock;   // Used for fps calculation
    unsigned long   stat_frameElapsed = 0;
    unsigned        stat_fps = 0;

    // Fixed Step Related
    const sf::Time  TimePerFrame = sf::seconds(1.f / 60.f);
    sf::Clock       deltaClock; // Used for delta timing
    sf::Time        timeSinceLastUpdate = sf::Time::Zero;
    int             updateRealised = 0;

    // Creating the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Purple Rain", sf::Style::Close);

    // Loading the Font
    sf::Font pixeledFont;
    if(!pixeledFont.loadFromFile("media/pixeled.ttf"))
        return EXIT_FAILURE;

    // FPS display
    GUI::Label stat_display("FPS:", pixeledFont);
    stat_display.setOutlineColor(sf::Color::Black);
    stat_display.setOutlineThickness(2);
    stat_display.setOrigin(stat_display.getBounds().width/2.f,0);
    stat_display.setPosition(800-10,16+2);
    bool displayFPS(false);

    // Creating the canvas
    rain::Canvas rainCanvas;

    // Creating the settings GUI
    GUI::Interface settingsInterface;
    settingsInterface.deactivate();

    auto backgroundBox = std::make_shared<GUI::Box>(50,60);
    backgroundBox->setColor(sf::Color(138, 43, 226, 50));
    backgroundBox->setSize(sf::Vector2f(320,600));
    backgroundBox->setPosition(320/2.f,300);


    auto settingsTitle = std::make_shared<GUI::Label>("SETTINGS", pixeledFont);
    settingsTitle->setCharacterSize(20);
    settingsTitle->setPosition(320/2.f, 50);

    auto densitySlider = std::make_shared<GUI::Slider>();
    densitySlider->setColor(sf::Color(138, 43, 226));
    densitySlider->setSize(sf::Vector2f(320-80,40));
    densitySlider->setPosition((320-80)/2.f+40,250);
    densitySlider->setRange(0,500);
    densitySlider->setValue(100);
    densitySlider->setStep(25);
    densitySlider->setTitleFont(pixeledFont);
    densitySlider->setTitleCharacterSize(12);
    densitySlider->setTitleString("Density:");
    densitySlider->displayTitle(true);

    auto gravitySlider = std::make_shared<GUI::Slider>();
    gravitySlider->setColor(sf::Color(138, 43, 226));
    gravitySlider->setSize(sf::Vector2f(320-80,40));
    gravitySlider->setPosition((320-80)/2.f+40,400);
    gravitySlider->setRange(0,500);
    gravitySlider->setValue(100);
    gravitySlider->setStep(25);
    gravitySlider->setTitleFont(pixeledFont);
    gravitySlider->setTitleCharacterSize(12);
    gravitySlider->setTitleString("Gravity:");
    gravitySlider->displayTitle(true);

    auto startButton = std::make_shared<GUI::Button>(pixeledFont);
    startButton->setPosition(60,550);
    startButton->setColor(sf::Color(138, 43, 226));
    startButton->setSize(sf::Vector2f(80,30));
    startButton->setText("START");
    startButton->setCharacterSize(11);
    startButton->setCallback([&rainCanvas]()
    {
          rainCanvas.start();
    });

    auto stopButton = std::make_shared<GUI::Button>(pixeledFont);
    stopButton->setPosition(60*2+40,550);
    stopButton->setColor(sf::Color(138, 43, 226));
    stopButton->setSize(sf::Vector2f(80,30));
    stopButton->setText("STOP");
    stopButton->setCharacterSize(11);
    stopButton->setCallback([&rainCanvas]()
    {
          rainCanvas.stop();
    });

    auto clearButton = std::make_shared<GUI::Button>(pixeledFont);
    clearButton->setPosition(60*3+40*2,550);
    clearButton->setColor(sf::Color(138, 43, 226));
    clearButton->setSize(sf::Vector2f(80,30));
    clearButton->setText("CLEAR");
    clearButton->setCharacterSize(11);
    clearButton->setCallback([&rainCanvas]()
    {
          rainCanvas.clear();
    });

    settingsInterface.setPosition(0,0);

    settingsInterface.pack(backgroundBox);
    settingsInterface.pack(settingsTitle);
    settingsInterface.pack(densitySlider);
    settingsInterface.pack(gravitySlider);
    settingsInterface.pack(startButton);
    settingsInterface.pack(stopButton);
    settingsInterface.pack(clearButton);


    // Run the program as long as the window is open
    while (window.isOpen())
    {

        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            // Toggling the FPS display
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::F)
            {
                if(!displayFPS)
                    displayFPS = true;
                else
                    displayFPS = false;
            }

            // Toggling the settings
            if (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::S)
            {
                if(!settingsInterface.isActive())
                    settingsInterface.activate();
                else
                    settingsInterface.deactivate();
            }

            // We then pass the event to the settings interface
            settingsInterface.handleEvent(event);
        }

        // Update cycle
        timeSinceLastUpdate += deltaClock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            // Ensure we don't get stuck if we can't reach our intended number
            // of updates per second
            if (updateRealised++ < CONSTANT::MAX_UPDATES)
            {
                rainCanvas.setDensity(densitySlider->getValue()/100.f);
                rainCanvas.setGravity(gravitySlider->getValue()/100.f);
                rainCanvas.update(TimePerFrame);
            }
        }
        updateRealised = 0;

        // Updating the FPS
        if(displayFPS)
        {
            if(fpsClock.getElapsedTime() > sf::seconds(0.5f))
            {
                stat_fps = static_cast<int>(stat_frameElapsed/fpsClock.restart().asSeconds());
                stat_frameElapsed = 0;
            }

            ++stat_frameElapsed;
    		stat_display.setText("FPS: " + std::to_string(stat_fps));
            stat_display.setOrigin(stat_display.getBounds().width/2.f,0);
        }

        // drawing the Window
        window.clear(backgroundColor);
        window.draw(rainCanvas);
        window.draw(settingsInterface);
        if(displayFPS)
            window.draw(stat_display);

        // End of the current frame
        window.display();
    }

    return EXIT_SUCCESS;
}
