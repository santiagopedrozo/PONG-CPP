#include "Menu.h"
#include "BackGround.h"
#include "EntranceMenuStyle.h"

Menu::Menu()
{
    _selectedItem = 0;
    _IsActive = true;
    _ItemActive = false;
    _EnterPressed = false;
}

void Menu::menuPanel(sf::RenderWindow& window){
    DrawBackground(window);
    BordersLineColor(window);
    MenuArrow(window, _selectedItem);
    if(_IsActive) itemsFirstMenu(window);
}

void Menu::SetEnterPressed(bool p){
    _EnterPressed = p;
}

void Menu::SetIsActive(bool a){
    _IsActive=a;
}

void Menu::SetItemActive(bool a){
    _ItemActive=a;
}

int Menu::getPressedButton(){
    return _selectedItem;
}

bool Menu::GetIsActive(){
    return _IsActive;
}

bool Menu::GetItemActive(){
    return _ItemActive;
}

void Menu::drawTo(sf::RenderWindow& window){
    menuPanel(window);
}

void Menu::UP(){
    if(_selectedItem - 1 >= 0) _selectedItem--;
}

void Menu::DOWN(){
    if(_selectedItem + 1 < ITEMS) _selectedItem++;
}

void Menu::MenuAsignament(Gameplay& gp, TextBox tx[], bool& top3, sf::RenderWindow& window){
    if(!_ItemActive) window.setFramerateLimit(12); ///ESTARA ACTIVO SIEMPRE Y CUANDO SE ESTE EN ETAPA DE SELECCION DE ALGUN ITEM EN MENU

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        UP();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        DOWN();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        if(!_EnterPressed)
        {
            SetIsActive(false);  ///OBJETO MENU DEJA DE SER ACTIVO Y DA PASO A TEXTINPUT
            SetItemActive(true);
            window.setFramerateLimit(60);

            switch(_selectedItem)
            {
                case 0:
                    gp.setMode(0);
                    tx[0].SetSelected(true);
                    break;
                case 1:
                    gp.setMode(1);
                    tx[0].SetSelected(true);
                    break;
                case 2:
                    top3 = true;
                    break;
            }

            _EnterPressed = true;
        }
    }
}
