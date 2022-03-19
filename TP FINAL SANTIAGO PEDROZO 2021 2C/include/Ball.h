#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball
{
    private:
        sf::Sprite _Bshape;
        sf::Texture _BshapeText;
        float _Diry;
        float _Dirx;
        sf::Vector2f _Position;
        float _Velocity;
    public:
        Ball();

        void cmd();
        void update();

        sf::Sprite& GetDraw();
        sf::Vector2f GetPosition();

        void checkcolitionBall();

        void DirY(float y);
        void DirX(float x);

        void Draw(sf::RenderWindow& window);

        float GetDirX();

};

#endif // BALL_H
