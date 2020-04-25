#include <iostream>
#include "prototype.hpp"
#include "definition.hpp"

int SceneManager(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "ESCAPE", sf::Style::Close);
    int game = MENU;
    while (game != QUIT) {
        switch (game)
        {
        case MENU:
            game = MenuGameLoop(window, game);
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