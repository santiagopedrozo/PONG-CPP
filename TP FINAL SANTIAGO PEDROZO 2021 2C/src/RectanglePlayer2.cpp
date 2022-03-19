#include "RectanglePlayer2.h"

RectanglePlayer2::RectanglePlayer2()
{
    _Rshape.setPosition(740, 0);
}

void RectanglePlayer2::cmdplayer2(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        _state = StatesR::UP;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        _state = StatesR::DOWN;
    }

    checkcolitionborder();
}


