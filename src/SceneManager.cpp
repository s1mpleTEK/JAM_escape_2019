#include <iostream>
#include "prototype.hpp"
#include "definition.hpp"
#include "position.hpp"

int SceneManager(void)
{
    sf::RenderWindow window(sf::VideoMode(X, Y), "ESCAPE", sf::Style::Close);
    int game = MENU;
    while (game != QUIT) {
        switch (game)
        {
        case MENU:
            game = MenuGameLoop(window, game);
            break;

        case MENU_END:
            game = MenuEndGameLoop(window, game);
            break;
        
        case HTP:
            game = HtpGameLoop(window, game);
            break;

        case PLAY:
            game = PlayGameLoop(window, game);
            break;
        }
    }
    window.close();
    return EXIT_SUCCESS;
}