#ifndef SCOREFUNTIONS_H
#define SCOREFUNTIONS_H
#include"User.h"
#include"FilesFuntions.h"
#include <SFML/Graphics.hpp>
float FinalScore(int score[], int ScoreMatch);

void SortVector(int *v, int Size);

void ListTop(int v[]);

void Top3Scores(sf::RenderWindow& window);

void ShowAll();

void CharToString(const char * Char, std::string& Str, int Size);

void LoadTop3(int v[], int Scores[], std::string[]);

#endif // SCOREFUNTIONS_H
