#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Graphics.hpp>

#include "Ball.h"
#include "Rectangle.h"
#include "RectangleBOT.h"
#include "RectanglePlayer2.h"
#include "User.h"

class Gameplay
{
    private:
        enum StatesG{
            Start,
            Playing,
            Pause,
            Restart,
            Ended
        };

        StatesG _States;

        int _Mode;
        bool _IsPlaying;

        Ball _Ball;
        Rectangle _RecPlayer;
        RectanglePlayer2 _RecPlayer2;
        RectangleBOT _RecBOT;

        std::string _Names[2];
        int _Score[2];

        User _user1;
        User _user2;

        void Scoring();
        void GameplayStates(StatesG& States);

    public:

        Gameplay();

        void cmd();
        void update();
        void draw(sf::RenderWindow& window);
        void SetIsPlaying(bool p);
        void SetUserName1(const char* name);
        void SetUserName2(const char* name);
        void setMode(int m);
        void ResetScores();

        bool getIsPlaying();
        bool getIsEnded();

        void checkcolitionBallRectangle();
};

#endif // GAMEPLAY_H
