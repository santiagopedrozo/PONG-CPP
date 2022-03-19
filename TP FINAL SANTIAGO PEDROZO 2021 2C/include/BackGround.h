#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Menu.h"

///GENERAL FUNCTIONS

void GetFont(sf::Font& font);

void DrawBackground(sf::RenderWindow& window);

void DrawRectangle(sf::RenderWindow& window, sf::Color First, sf::Color Second, sf::Vector2f pos, sf::Vector2f Size);

void WordStyle(const std::string word, sf::Vector2f pos, int Size, sf::Color FirstColor, sf::Color SecondColor,sf::RenderWindow& window, sf::Font font);

void BordersLineColor(sf::RenderWindow& window);


#endif // BACKGROUND_H
