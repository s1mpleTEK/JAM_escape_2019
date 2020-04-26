#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Music.h"
#include "prototype.hpp"
#include "definition.hpp"
#include "position.hpp"

int MenuEndGameLoop(sf::RenderWindow &window, int game)
{
    //Variable
    int over_jouer = 0;
    int over_quitter = 0;
    int mouse_x = 0;
    int mouse_y = 0;

    //Event
    sf::Event event;

    //Audio
    Music menu_m;
    menu_m.addMusic(MenuMusic);
    menu_m.loop(true);
    menu_m.play();

    //Menu
    sf::Texture menu_t;
    menu_t.loadFromFile(MenuImg);
    sf::Texture menu_up_t;
    menu_up_t.loadFromFile(MenuImg_Up);
    sf::Texture menu_down_t;
    menu_down_t.loadFromFile(MenuImg_Down);
    sf::Sprite menu_s;
    menu_s.setTexture(menu_t);

    //Jouer
    sf::Texture jouerw_t;
    jouerw_t.loadFromFile(JouerImg_W);
    sf::Texture jouerr_t;
    jouerr_t.loadFromFile(JouerImg_R);
    sf::Sprite jouer_s;
    jouer_s.setTexture(jouerw_t);
    jouer_s.setPosition(sf::Vector2f(JOUER_POS_X, JOUER_POS_Y));

    //Quitter
    sf::Texture quitterw_t;
    quitterw_t.loadFromFile(QuitterImg_W);
    sf::Texture quitterg_t;
    quitterg_t.loadFromFile(QuitterImg_G);
    sf::Sprite quitter_s;
    quitter_s.setTexture(quitterw_t);
    quitter_s.setPosition(sf::Vector2f(QUITTER_POS_X, QUITTER_POS_Y));

    ///Game loop
    while (window.isOpen() && game == MENU_END) {

        ///Event polling
        while (window.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                    switch (event.mouseButton.button)
                    {
                    case sf::Mouse::Left:
                        if (over_jouer)
                            game = PLAY;
                        if (over_quitter)
                            game = QUIT;
                        break;
                    }
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
                        case sf::Keyboard::H:
                            game = HTP;
                            break;
                    }
                    break;
            }
        }

        ///Update

        //Position mouse
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        mouse_x = mouse.x;
        mouse_y = mouse.y;

        //Over Jouer
        if (((mouse_x > JOUER_POS_X) && (mouse_x < (JOUER_POS_X + JOUER_DIM_X))) 
        && ((mouse_y > JOUER_POS_Y) && (mouse_y < (JOUER_POS_Y + JOUER_DIM_Y)))) {
                jouer_s.setTexture(jouerr_t);
                menu_s.setTexture(menu_down_t);
                over_jouer = 1;
            } else {
                jouer_s.setTexture(jouerw_t);
                over_jouer = 0;
            }

        //Over Quitter
        if (((mouse_x > QUITTER_POS_X) && (mouse_x < (QUITTER_POS_X+QUITTER_DIM_X))) 
        && ((mouse_y > QUITTER_POS_Y) && (mouse_y < (QUITTER_POS_Y+QUITTER_DIM_Y)))) {
                quitter_s.setTexture(quitterg_t);
                menu_s.setTexture(menu_up_t);
                over_quitter = 1;
            } else {
                quitter_s.setTexture(quitterw_t);
                over_quitter = 0;
            }

        //Over rien
        if (over_jouer == 0 && over_quitter == 0)
            menu_s.setTexture(menu_t);

        ///Render
        window.clear(sf::Color(255, 255, 255, 255)); //Clear old frame

        ///Draw your game
        window.draw(menu_s);
        window.draw(jouer_s);
        window.draw(quitter_s);
        window.display(); //Draw new frame
    }
    menu_m.stop();
    return game;
}
