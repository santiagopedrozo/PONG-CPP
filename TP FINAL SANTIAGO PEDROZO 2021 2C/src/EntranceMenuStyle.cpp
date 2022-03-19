#include "EntranceMenuStyle.h"

void MenuArrow(sf::RenderWindow& window, int SelectedItem){
    sf::Color BlueSky(103, 237, 255); //rgba(25, 211, 226, 0.8)
    sf::Color Blue(0, 111, 120);

    switch(SelectedItem){
        case 0:
            DrawRectangle(window, Blue, BlueSky, {75, 212}, {540, 70});
            break;
        case 1:
            DrawRectangle(window, Blue, BlueSky, {75, 212 + 80}, {680, 70});
            break;
        case 2:
            DrawRectangle(window, Blue, BlueSky, {75, 212 + 160}, {505, 70});
            break;
    }
}

void itemsFirstMenu(sf::RenderWindow& window){
    float x=80, y=230;

    sf::Font font;
    GetFont(font);

    sf::Color First(0, 60, 64);
    sf::Color Second(0, 130, 141);

    sf::Color BlueSky(25, 211, 226); //rgba(25, 211, 226, 0.8)
    sf::Color Blue(0, 111, 120);

    DrawRectangle(window, Blue, BlueSky, {155, 78}, {490, 70});
    WordStyle("PONG CPP", {177, 90}, 42, First, Second, window, font);
    WordStyle("PLAYER VS BOT", {x, y} , 32, First, Second, window, font);
    WordStyle("PLAYER VS PLAYER", {x, y + 80} , 32, First, Second, window, font);
    WordStyle("TOP 3 SCORES", {x, y + 160}, 32, First, Second, window, font);
}
