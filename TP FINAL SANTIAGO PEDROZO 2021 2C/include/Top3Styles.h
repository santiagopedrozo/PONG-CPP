#ifndef TOP3STYLES_H
#define TOP3STYLES_H

#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Menu.h"
#include "BackGround.h"

void DrawMedalsBlack(sf::RenderWindow& window);

void DrawMedals(sf::RenderWindow& window);

void DrawScoresAndNamesTOP3(sf::RenderWindow& window, int Scores[], std::string Names[]);

#endif // TOP3STYLES_H
