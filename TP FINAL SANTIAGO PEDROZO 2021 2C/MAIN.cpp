#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>

#include"Random.h"
#include"Gameplay.h"
#include"TextBox.h"
#include"Menu.h"
#include "User.h"
#include "FilesFuntions.h"
#include "ScoreFuntions.h"
#include "BackGround.h"
#include "Top3.h"
#include "MainFunctions.h"
#include "Top3Styles.h"
#include "EntranceMenuStyle.h"
#include "NameEnteringStyles.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "PONG CPP EDITION");
    window.setFramerateLimit(60);

    sf::Event event;
    Gameplay gp;
    Menu menu1;
    TextBox textInput[2];
    bool Top3Selected = false;

    ShowAll();
    //deleteRegisters(); ///Para borrar registros
    //std::cout << CountRegisters();
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::TextEntered:
                    if(!menu1.GetIsActive())
                    {
                        if(textInput[0].GetSelected()) textInput[0].TypedOn(event);
                        if(textInput[1].GetSelected()) textInput[1].TypedOn(event);
                    }
                    textInputActive(menu1, textInput); ///cuando el menu deje de estar activo se activa textinput
                    break;

                case sf::Event::Closed:
                    window.close();

            }

        }

        menu1.MenuAsignament(gp, textInput, Top3Selected, window); ///MANEJA EL NAVEGAMIENTO DEL MENU Y ESTABLECE LOS MODOS
        gp.SetUserName1(textInput[0].GetText());
        gp.SetUserName2(textInput[1].GetText());

        window.clear();
        DrawAllObjects(menu1, textInput, gp, Top3Selected, window);
        window.display();

    }
    return 0;
}
