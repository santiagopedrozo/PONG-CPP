#include "Rectangle.h"
#include <iostream>


Rectangle::Rectangle(){
    _RshapeText.loadFromFile("resources/Rectangle.png");
    _Rshape.setTexture(_RshapeText);
    _Rshape.setPosition(40, 0);
    _Velocity = 2.5;
}

void Rectangle::Cmd(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _state = StatesR::UP;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _state = StatesR::DOWN;

}

sf::Sprite& Rectangle::GetDraw(){
    return _Rshape;
}

void Rectangle::checkcolitionborder(){
    //top y
    if(_Rshape.getPosition().y < 0){
        _Rshape.setPosition(_Rshape.getPosition().x , 0);
    }

    //bottom y
    if(_Rshape.getPosition().y + _Rshape.getGlobalBounds().height > 600){
        _Rshape.setPosition(_Rshape.getPosition().x , 600 - _Rshape.getGlobalBounds().height);
    }

}

void Rectangle::update(){
    checkcolitionborder();
    switch(_state)
    {
        case UP:

            _Rshape.move(0, -10 * _Velocity);
            _state = StatesR::STILL;
            break;
        case DOWN:
            _Rshape.move(0, 10 * _Velocity);
            _state = StatesR::STILL;
            break;
    }
}

