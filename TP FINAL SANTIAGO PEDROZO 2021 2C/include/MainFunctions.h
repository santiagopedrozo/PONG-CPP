#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include"Gameplay.h"
#include"TextBox.h"
#include"Menu.h"
#include"BackGround.h"
#include"ScoreFuntions.h"

void MenuSelected(Menu& menu1, sf::RenderWindow& window);

void GameplaySelected(Menu& menu1, TextBox textInput[], Gameplay& gp, bool& Top3Selected, sf::RenderWindow& window);

void NameEnteringSelected(TextBox textInput[], sf::RenderWindow& window);

void Top3Selected(Menu& menu1, bool& Top3Selected, sf::RenderWindow& window);

void DrawAllObjects(Menu& menu1, TextBox textInput[], Gameplay& gp, bool& Top3Selected, sf::RenderWindow& window);

void textInputActive(Menu& menu1, TextBox textInput[]);

#endif // MAINFUNCTIONS_H
