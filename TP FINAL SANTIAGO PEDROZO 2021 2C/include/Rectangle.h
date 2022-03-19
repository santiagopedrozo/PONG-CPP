#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <SFML/Graphics.hpp>


class Rectangle
{
    protected:
        enum StatesR{
            STILL,
            UP,
            DOWN
        };

        sf::Sprite _Rshape;
        sf::Texture _RshapeText;
        StatesR _state;
        float _Velocity;

    public:
        Rectangle();
        void Cmd();
        void update();

        void checkcolitionborder();

        sf::Sprite& GetDraw();


};

#endif // RECTANGLE_H
