#include <iostream>
#include <string>
#include <cmath>
#include "point.h"

Point::Point(float *x, float *y, int arraySize)
{
    xCord = x;
    yCord = y;
    this->arraySize = arraySize;
}

std::string Point::getType()
{
    return "point";
}

float Point::area()
{
    return -1;
}

float Point::circumference()
{
    return 0;
}

ReturnCords Point::position()
{
    
    ReturnCords mposition(*xCord, *yCord);
    return mposition;
}

bool Point::isConvex()
{
    return false;
}

float Point::distance(Shape *s)
{
    
    float deltaX = position().x - s->position().x;
    float deltaY = position().y - s->position().y;
    float distance = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
    distance = decimalDigits(distance);
    return distance;
}


