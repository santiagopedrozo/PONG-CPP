#include "Gameplay.h"
#include<string.h>
#include "FilesFuntions.h"
#include "ScoreFuntions.h"
#include"Random.h"
#include "BackGround.h"
#include "ScoreFuntions.h"
#include "GameplayStyle.h"

#define WIN_POINTS 10

Gameplay::Gameplay(){
    _IsPlaying =  true;
    _States = StatesG::Start;

    _Score[0] = {0};
    _Score[1] = {0};

    _Mode=1;
    ///0==playervsbot
    ///1==playervsplayer
}

bool Gameplay::getIsPlaying(){
    return _IsPlaying;
}

void Gameplay::SetIsPlaying(bool p){
    _IsPlaying = p;
}

void Gameplay::SetUserName1(const char* name){
    _user1.setUserName(name);
}

void Gameplay::SetUserName2(const char* name){
    _user2.setUserName(name);
}

void Gameplay::Scoring(){
    for(int i=0; i<1; i++)
    {
        //Right side X
        if(_Ball.GetDraw().getPosition().x + _Ball.GetDraw().getGlobalBounds().width  > 800)
        {
            _Score[0]++;
            _Ball.DirX(-1);

            if(_Score[0]== WIN_POINTS ){
                _States = StatesG::Ended;
                _IsPlaying=false;
            }
            else{
                _States = StatesG::Restart;
            }

        }

        //Left Side X
        if(_Ball.GetDraw().getPosition().x  < 0)
        {
            _Score[1]++;
            _Ball.DirX(1);

            if(_Score[1]==WIN_POINTS){
                _States = StatesG::Ended;
                _IsPlaying=false;
            }
            else{
                _States = StatesG::Restart;
            }


        }

    }
}

void Gameplay::setMode(int m){
    _Mode=m;
}

void Gameplay::checkcolitionBallRectangle(){

    sf::FloatRect BallBound = _Ball.GetDraw().getGlobalBounds();                 //bola
    sf::FloatRect RightRectangleBound = _RecPlayer.GetDraw().getGlobalBounds(); //rectangulo derecho

    //right
    if (RightRectangleBound.intersects(BallBound)){
        _Ball.DirX(1);
    }

    //left
    if(_Mode == 0)
    {
        if(_RecBOT.GetDraw().getGlobalBounds().intersects(BallBound)){
            _Ball.DirX(-1);
        }
    }
    else
    {
        if(_RecPlayer2.GetDraw().getGlobalBounds().intersects(BallBound)){
            _Ball.DirX(-1);
        }
    }

}

void Gameplay::cmd(){
    _Ball.cmd();

    _RecPlayer.Cmd(); //player 1
    if(_Mode==0) _RecBOT.Cmd(); //player 2 bot
    else _RecPlayer2.cmdplayer2(); //player2

    if(_IsPlaying) Scoring();
}

void Gameplay::update(){
    GameplayStates(_States);
}

void Gameplay::draw(sf::RenderWindow& window){
    gameplayPanel(window, _Score, _Names);

    window.draw(_Ball.GetDraw());

    window.draw(_RecPlayer.GetDraw());
    if(_Mode==0) window.draw(_RecBOT.GetDraw());    ///player 2 bot
    else window.draw(_RecPlayer2.GetDraw());        ///player2

    if(!_IsPlaying)
    {
        FinalMenu(window, _Score, _Names);
    }


}

void Gameplay::GameplayStates(StatesG& States){
    switch(States)
    {
        case Start:
            CharToString(_user1.GetUserName(), _Names[0], 30); ///COPIA AL STRING EL CONTENIDO DE LA CADENA CHAR
            CharToString(_user2.GetUserName(), _Names[1], 30);

            _States = StatesG::Playing;
            break;

        case Playing:
            checkcolitionBallRectangle();
            _Ball.update();

            _RecPlayer.update(); //player 1
            if(_Mode==0) _RecBOT.updateBOT(_Ball.GetPosition().y, _Ball.GetPosition().x, _Ball.GetDirX() ); //player 2 bot
            else  _RecPlayer2.update(); //player2

            break;

        case Restart:
            _Ball.GetDraw().setPosition(370, 260);
            _Ball.DirX( RandomDirection() );
            States = StatesG::Playing;
            break;

        case Pause:
            break;

        case Ended:
            FileLoad(_user1, _user2, _Score);
            _Ball.GetDraw().setPosition(370, 260);

            States = StatesG::Pause;
            break;
    }

}
