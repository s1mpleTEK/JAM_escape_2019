#include <iostream>
#include <SFML/Graphics.hpp>
#include "Music.h"
#include "prototype.hpp"
#include "definition.hpp"

int HtpGameLoop(sf::RenderWindow &window, int game)
{
    //Event
    sf::Event event;

    //Audio

    //Game loop
    
    while (window.isOpen() && game == HTP) {
        //Event polling
        while (window.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                    break;
                case sf::Event::Closed:
                    game = QUIT;
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            game = QUIT;
                            break;
                        case sf::Keyboard::B:
                            game = MENU;
                            break;
                    }
                    break;
            }
        }

        //Update

        //Render
        window.clear(sf::Color(0, 255, 255, 255)); //Clear old frame

        //Draw your game

        window.display(); //Draw new frame
    }
    return game;
}