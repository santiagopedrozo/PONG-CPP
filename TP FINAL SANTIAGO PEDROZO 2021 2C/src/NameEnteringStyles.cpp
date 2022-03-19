#include "NameEnteringStyles.h"

void NameInputSigners(sf::RenderWindow& window, TextBox textInput[]){
    float x=45, y=220;

    sf::Font font;
    GetFont(font);

    sf::Color First(0, 60, 64);
    sf::Color Second(20, 173, 182);

    sf::Color BlueSky(103, 237, 255); //rgba(25, 211, 226, 0.8)
    sf::Color Blue(0, 111, 120);

    DrawRectangle(window, Blue, BlueSky, {65, 78}, {680, 70});
    WordStyle("Who will play?", {70, 90}, 42, First, Second, window, font);

    if(textInput[0].GetSelected()){
        DrawRectangle(window, Blue, BlueSky, {x - 5, y - 5}, {685, 42});
    }
    else{
        DrawRectangle(window, Blue, BlueSky, {x - 5, y + 95}, {725, 42});
    }

    WordStyle("NAME PLAYER 1 (LEFT SIDE)", {x, y}, 22, First, Second, window, font);
    WordStyle("NAME PLAYER 2 (RIGHT SIDE)", {x, y + 100}, 22, First, Second, window, font);

    textInput[0].SetPosition({x, y + 30});
    textInput[1].SetPosition({x, y + 100});

}

void NameEntering(TextBox TextName[], sf::RenderWindow& window){
    int j, i;
    float x=45, y=260;
    sf::Font font;
    GetFont(font);
    sf::Text TextNameBack[2];

    DrawBackground(window);
    BordersLineColor(window);
    NameInputSigners(window, TextName);

    sf::Color First(255, 253, 0);
    sf::Color Second(122, 121, 0);

    TextName[0].GetTextBox().setPosition({x, y});
    TextName[1].GetTextBox().setPosition({x, y + 100});

    TextNameBack[0].setPosition({x + 3, y - 3});
    TextNameBack[1].setPosition({x + 3, y + 97});

    for(i=0; i<2; i++)
    {
        TextNameBack[i].setString(TextName[i].GetTextBox().getString());
        TextName[i].GetTextBox().setColor(Second);
        TextName[i].SetFont(font);
        TextName[i].GetTextBox().setCharacterSize(25);
        TextName[i].drawTo(window);

        TextNameBack[i].setColor(First);
        TextNameBack[i].setFont(font);
        TextNameBack[i].setCharacterSize(25);
        window.draw(TextNameBack[i]);

    }
}
