#include <iostream>
#include <SFML/Graphics.hpp>
#include "Music.h"
#include "prototype.hpp"
#include "definition.hpp"

int PlayGameLoop(sf::RenderWindow &window, int game)
{
    //Event
    sf::Event event;

    //Audio

    //Game loop
    
    while (window.isOpen() && game == PLAY) {
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
                        case sf::Keyboard::M:
                            game = MENU;
                            break;
                    }
                    break;
            }
        }

        //Update

        //Render
        window.clear(sf::Color(255, 255, 0, 255)); //Clear old frame

        //Draw your game

        window.display(); //Draw new frame
    }
    return game;
}