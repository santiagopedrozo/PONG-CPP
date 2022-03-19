
#ifndef RECTANGLEBOT_H
#define RECTANGLEBOT_H
#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include "Ball.h"
#include <iostream>

class RectangleBOT : public Rectangle
{
    private:
        Ball _Ball;

    public:
        RectangleBOT();
        void updateBOT(float y, float x, int dir);

};

#endif // RECTANGLEBOT_H

