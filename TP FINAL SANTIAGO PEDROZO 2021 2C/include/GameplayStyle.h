#ifndef GAMEPLAYSTYLE_H
#define GAMEPLAYSTYLE_H
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Menu.h"
#include "BackGround.h"
#include "ScoreFuntions.h"

void MidLine(sf::RenderWindow& window);

void ScoresAndNamesGameplay(int Score[], std::string Name[], sf::RenderWindow& window);

void gameplayPanel(sf::RenderWindow& window, int Scores[], std::string Names[]);

void FinalMenu(sf::RenderWindow& window, int Score[], std::string Names[]);


#endif // GAMEPLAYSTYLE_H
