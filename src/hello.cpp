#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int hello(void)
{
    std::cout << "Hello World!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
    return (EXIT_SUCCESS);
}
