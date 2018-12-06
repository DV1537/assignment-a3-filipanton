#include <iostream>
#include <string>
#include <cmath>
#include "line.h"

Line::Line(float *x, float *y, int arraySize)
{
    xCord = x;
    yCord = y;
    this->arraySize = arraySize;

}

std::string Line::getType()
{
    return "line";
}

float Line::area()
{
    return -1;
}

float Line::circumference()
{
    return 0;
}

ReturnCords Line::position()
{
    float averageX = (xCord[0] + xCord[1])/2;
    float averageY = (yCord[0] + yCord[1])/2;
    averageX = decimalDigits(averageX);
    averageY = decimalDigits(averageY);
    ReturnCords mPosition(averageX, averageY);
    return mPosition;
}

bool Line::isConvex()
{
    return false;
}

float Line::distance(Shape *s)
{
    
    float deltaX = position().x - s->position().x;
    float deltaY = position().y - s->position().y;
    float distance = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
    distance = decimalDigits(distance);
    return distance;
}


