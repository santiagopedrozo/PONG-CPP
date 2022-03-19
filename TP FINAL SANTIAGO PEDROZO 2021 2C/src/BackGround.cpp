#include "BackGround.h"
#include "ScoreFuntions.h"
#include "Menu.h"
#include <iostream>

///GENERAL FUNCTIONS

void GetFont(sf::Font& font){
    font.loadFromFile("Resources/FONT.TTF");
}

void DrawBackground(sf::RenderWindow& window){
    sf::Texture background;
    background.loadFromFile("Resources/BACKGROUND.JPG");

    sf::Sprite BckGround;
    BckGround.setTexture(background);

    window.draw(BckGround);
}

void DrawRectangle(sf::RenderWindow& window, sf::Color First, sf::Color Second, sf::Vector2f pos, sf::Vector2f Size){
    sf::RectangleShape Shape[2];

    Shape[0].setPosition(pos);
    Shape[1].setPosition(pos.x - 7, pos.y - 7);

    Shape[0].setFillColor(First);
    Shape[1].setFillColor(Second);

    for(int i=0; i<2; i++){
        Shape[i].setSize({Size});
        window.draw(Shape[i]);
    }
}

void WordStyle(const std::string word, sf::Vector2f pos, int Size, sf::Color FirstColor, sf::Color SecondColor,sf::RenderWindow& window, sf::Font font){
    float x2=150, y2=90;
    sf::Text WordStyle[2];

    WordStyle[0].setColor(FirstColor);
    WordStyle[1].setColor(SecondColor);

    WordStyle[0].setPosition({pos.x, pos.y});
    WordStyle[1].setPosition({pos.x + 3, pos.y - 4});

    for(int i=0; i<2; i++)
    {
        WordStyle[i].setCharacterSize(Size);
        WordStyle[i].setString(word);
        WordStyle[i].setFont(font);
        window.draw(WordStyle[i]);
    }
}

void BordersLineColor(sf::RenderWindow& window){
    sf::Color Main(158, 252, 255);

    sf::RectangleShape XLine[2];    ///0 Superior, 1 Inferior
    sf::RectangleShape YLine[2];    ///0 Left, 1 right

    for(int i=0; i<2; i++){
        XLine[i].setFillColor(Main);
        YLine[i].setFillColor(Main);
    }

    XLine[0].setSize({800, 6});
    XLine[0].setPosition(0, 0);
    window.draw(XLine[0]);

    XLine[1].setSize({800, 6});
    XLine[1].setPosition(0, 600 - 6);
    window.draw(XLine[1]);

    YLine[0].setSize({6, 600});
    YLine[0].setPosition(0, 0);
    window.draw(YLine[0]);

    YLine[1].setSize({10, 600});
    YLine[1].setPosition(800 - 6, 0);
    window.draw(YLine[1]);
}
