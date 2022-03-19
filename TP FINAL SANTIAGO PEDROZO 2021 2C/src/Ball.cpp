#include "Ball.h"
#include <iostream>

Ball::Ball(){

    _BshapeText.loadFromFile("resources/Ball.png");
    _Bshape.setTexture(_BshapeText);

    _Bshape.setPosition(370, 260);
    DirX(1);
    DirY(-1);
    _Velocity = 13;

}

void Ball::checkcolitionBall(){
    //bottom Y
    if(_Bshape.getPosition().y + _Bshape.getGlobalBounds().height > 600){
        _Diry=-1;
    }
    //top Y
    if(_Bshape.getPosition().y < 0){
        _Diry=1;
    }
}

void Ball::cmd(){
    _Position = _Bshape.getPosition();
}


void Ball::update(){
    checkcolitionBall();
    float x=0, y=0;
    x += _Velocity * _Dirx;
    y += _Velocity * _Diry;
    _Bshape.move(x, y);

}

void Ball::DirY(float y){
    _Diry=y;
}

void Ball::DirX(float x){
    _Dirx=x;
}

sf::Sprite& Ball::GetDraw(){
    return _Bshape;
}

sf::Vector2f Ball::GetPosition(){
    return _Position;
}

float Ball::GetDirX(){
    return _Dirx;
}
