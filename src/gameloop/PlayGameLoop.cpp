#include <iostream>
#include <SFML/Graphics.hpp>
#include "Music.h"
#include "prototype.hpp"
#include "definition.hpp"
#include "position.hpp"

int PlayGameLoop(sf::RenderWindow &window, int game)
{
    ///Varianle

    //Mouse
    int mouse_x = 0;
    int mouse_y = 0;

    //Over
    int over_left = 0;
    int over_right = 0;
    int over_door = 0;
    int over_key = 0;

    //Room
    int room1 = 0;
    int room1_n = 1;
    int room1_e = 0;

    //Item
    int key = 0;

    //Event
    sf::Event event;

    //Audio
    Music doorlock_m;
    doorlock_m.addMusic(DoorLockMusic);

    ///Sprite
    //Arrow
    /*Arrow up*/
    sf::Texture arrow_up_t;
    arrow_up_t.loadFromFile(Arrow_Up);
    sf::Sprite arrow_up_s;
    arrow_up_s.setTexture(arrow_up_t);
    arrow_up_s.setPosition(sf::Vector2f(ARROW_UP_POS_X, ARROW_UP_POS_Y));

    /*Arrow down*/
    sf::Texture arrow_down_t;
    arrow_down_t.loadFromFile(Arrow_Down);
    sf::Sprite arrow_down_s;
    arrow_down_s.setTexture(arrow_down_t);
    arrow_down_s.setPosition(sf::Vector2f(ARROW_DOWN_POS_X, ARROW_DOWN_POS_Y));

    /*Arrow left*/
    sf::Texture arrow_left_t;
    arrow_left_t.loadFromFile(Arrow_Left);
    sf::Sprite arrow_left_s;
    arrow_left_s.setTexture(arrow_left_t);
    arrow_left_s.setPosition(sf::Vector2f(ARROW_LEFT_POS_X, ARROW_LEFT_POS_Y));

    /*Arrow right*/
    sf::Texture arrow_right_t;
    arrow_right_t.loadFromFile(Arrow_Right);
    sf::Sprite arrow_right_s;
    arrow_right_s.setTexture(arrow_right_t);
    arrow_right_s.setPosition(sf::Vector2f(ARROW_RIGHT_POS_X, ARROW_RIGHT_POS_Y));

    //Room
    sf::Texture wall_n_t;
    wall_n_t.loadFromFile(Room1_N);
    sf::Texture wall_e_t;
    wall_e_t.loadFromFile(Room1_E);
    sf::Texture wall_s_t;
    wall_s_t.loadFromFile(Room1_S);
    sf::Texture wall_o_t;
    wall_o_t.loadFromFile(Room1_O);
    sf::Sprite room1_s;
    room1_s.setTexture(wall_n_t);

    //Items
    sf::Texture key_t;
    key_t.loadFromFile(Key);
    sf::Sprite key_s;
    key_s.setTexture(key_t);
    key_s.setPosition(sf::Vector2f(0, 0));

    //Game loop
    while (window.isOpen() && game == PLAY) {
        //Event polling
        while (window.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button)
                    {
                    case sf::Mouse::Left:
                        if (over_key && room1_e)
                            key = 1;
                        if (over_right)
                            switch (room1)
                            {
                            case 0:
                                room1_s.setTexture(wall_e_t);
                                room1_e = 1;
                                room1_n = 0;
                                room1++;
                                break;
                            case 1:
                                room1_s.setTexture(wall_s_t);
                                room1_e = 0;
                                room1_n = 0;
                                room1++;
                                break;
                            case 2:
                                room1_s.setTexture(wall_o_t);
                                room1_e = 0;
                                room1_n = 0;
                                room1++;
                                break;
                            case 3:
                                room1_s.setTexture(wall_n_t);
                                room1_e = 0;
                                room1_n = 1;
                                room1 = 0;
                                break;
                            }
                        if (over_left)
                            switch (room1)
                            {
                            case 0:
                                room1_s.setTexture(wall_o_t);
                                room1_e = 0;
                                room1_n = 0;
                                room1 = 3;
                                break;
                            case 1:
                                room1_s.setTexture(wall_n_t);
                                room1_e = 0;
                                room1_n = 1;
                                room1--;
                                break;
                            case 2:
                                room1_s.setTexture(wall_e_t);
                                room1_e = 1;
                                room1_n = 0;
                                room1--;
                                break;
                            case 3:
                                room1_s.setTexture(wall_s_t);
                                room1_e = 0;
                                room1_n = 0;
                                room1--;
                                break;
                            }
                        if (over_door && room1_n)
                            switch (key)
                            {
                            case 1:
                                game = MENU_END;
                                break;
                            
                            default:
                                doorlock_m.play();
                                break;
                            }
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
                        case sf::Keyboard::F2:
                            game = MENU;
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

        //Over left
        if (((mouse_x > (X-X)) && (mouse_x < ((X-X)+50))) && ((mouse_y > (Y-Y)) && (mouse_y < Y))) {
                over_left = 1;
            } else
                over_left = 0;

        //Over right
        if (((mouse_x > (X-50)) && (mouse_x < X)) && ((mouse_y > (Y-Y)) && (mouse_y < Y))) {
                over_right = 1;
            } else
                over_right = 0;

        //Over door
        if (((mouse_x > DOOR_POS_X) && (mouse_x < (DOOR_POS_X+DOOR_DIM_X))) && ((mouse_y > (DOOR_POS_Y)) && (mouse_y < (DOOR_DIM_Y+DOOR_POS_Y)))) {
                over_door = 1;
            } else
                over_door = 0;
        
        //Over key
        if (((mouse_x > CADRE_POS_X) && (mouse_x < (CADRE_POS_X+CADRE_DIM_X))) && ((mouse_y > CADRE_POS_Y) && (mouse_y < (CADRE_POS_Y+CADRE_DIM_Y)))){
            over_key = 1;
        } else
            over_key = 0;

        ///Render
        window.clear(sf::Color(255, 255, 0, 255)); //Clear old frame

        ///Draw your game
        window.draw(room1_s);
        if (key)
            window.draw(key_s);
        
        //Draw arrow
        if (over_left)
            window.draw(arrow_left_s);
        if (over_right)
            window.draw(arrow_right_s);
        if (over_door && room1_n)
            window.draw(arrow_up_s);
        else
            doorlock_m.stop();

        window.display(); //Draw new frame
    }
    return game;
}