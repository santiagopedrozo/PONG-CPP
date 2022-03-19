#include "MainFunctions.h"
#include "NameEnteringStyles.h"

void MenuSelected(Menu& menu1, sf::RenderWindow& window){
    if(menu1.GetIsActive()) menu1.drawTo(window);
}

void GameplaySelected(Menu& menu1, TextBox textInput[], Gameplay& gp, bool& Top3Selected, sf::RenderWindow& window){
    if(!menu1.GetIsActive() && !textInput[1].GetSelected() && !textInput[0].GetSelected() && !Top3Selected)
    {
        gp.draw(window);
        gp.cmd();
        gp.update();
    }
}

void NameEnteringSelected(TextBox textInput[], sf::RenderWindow& window){
    if(textInput[0].GetSelected() || textInput[1].GetSelected()){
        NameEntering(textInput, window);
    }
}


void TopScoresSelected(Menu& menu1, bool& Top3Selected, sf::RenderWindow& window){
    if(Top3Selected)
    {
        window.clear();
        Top3Scores(window);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Top3Selected = false;
            menu1.SetIsActive(true);
            menu1.SetEnterPressed(false);
            menu1.SetItemActive(false);
        }
    }
}


void DrawAllObjects(Menu& menu1, TextBox textInput[], Gameplay& gp, bool& Top3Selected, sf::RenderWindow& window){
    MenuSelected(menu1, window);
    GameplaySelected(menu1, textInput, gp, Top3Selected, window);
    NameEnteringSelected(textInput, window);
    TopScoresSelected(menu1, Top3Selected, window);
}

void textInputActive(Menu& menu1, TextBox textInput[]){
    if(menu1.GetItemActive())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            if(textInput[0].GetSelected()){
                textInput[0].SetSelected(false);
                textInput[1].SetSelected(true);
            }
            else textInput[1].SetSelected(false);
        }
    }
}
