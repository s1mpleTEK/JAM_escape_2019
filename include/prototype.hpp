#ifndef PROTOTYPE_HPP_
#define PROTOTYPE_HPP_

#include <SFML/Graphics.hpp>

int game_loop(void);
int SceneManager(void);
int MenuGameLoop(sf::RenderWindow &, int game);
int MenuEndGameLoop(sf::RenderWindow &, int game);
int HtpGameLoop(sf::RenderWindow &, int game);
int PlayGameLoop(sf::RenderWindow &, int game);

#endif /* !PROTOTYPE_HPP_ */