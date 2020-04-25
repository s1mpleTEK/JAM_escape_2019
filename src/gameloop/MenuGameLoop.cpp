#include <iostream>
#include <SFML/Graphics.hpp>
#include "Music.h"
#include "prototype.hpp"
#include "definition.hpp"

int MenuGameLoop(sf::RenderWindow  &window, int game)
{
    //Event
    sf::Event event;

    //Audio
    Music menu;
    menu.addMusic(MenuMusic);
    menu.loop(true);
    menu.play();

    //Game loop
    
    while (window.isOpen() && game == MENU) {
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
                        case sf::Keyboard::P:
                            game = PLAY;
                            break;
                        case sf::Keyboard::H:
                            game = HTP;
                            break;
                    }
                    break;
            }
        }

        //Update

        //Render
        window.clear(sf::Color(255, 255, 255, 255)); //Clear old frame

        //Draw your game

        window.display(); //Draw new frame
    }
    menu.stop();
    return game;
}
