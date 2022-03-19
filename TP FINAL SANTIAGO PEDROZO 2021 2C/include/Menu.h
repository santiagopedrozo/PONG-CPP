#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Gameplay.h"
#include "TextBox.h"

#define ITEMS 3

class Menu
{
    private:
        int _selectedItem;
        sf::Text _text[ITEMS][2];
        bool _IsActive;
        bool _ItemActive;
        bool _EnterPressed;

        void menuPanel(sf::RenderWindow& window);
    public:
        Menu();

        void drawTo(sf::RenderWindow& window);


        void UP();
        void DOWN();

        void SetIsActive(bool a);
        void SetItemActive(bool a);

        void SetUpPressed(bool p);
        void SetDownPressed(bool p);
        void SetEnterPressed(bool p);

        bool GetIsActive();
        bool GetItemActive();
        int getPressedButton();

        void MenuAsignament(Gameplay& gp, TextBox tx[], bool& top3, sf::RenderWindow& window);


};

#endif // MENU_H
