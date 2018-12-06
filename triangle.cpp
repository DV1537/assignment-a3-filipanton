#include <iostream>
#include <string>
#include <cmath>
#include "triangle.h"

Triangle::Triangle(float *x, float *y, int arraySize)
{
    xCord = x;
    yCord = y;
    this->arraySize = arraySize;

}

std::string Triangle::getType()
{
    return "triangle";
}

float Triangle::area()
{
  

    float area = std::abs((xCord[0]*(yCord[1]-yCord[2])+xCord[1]*(yCord[2]-yCord[0])+xCord[2]*(yCord[0]-yCord[1]))/2.0);
    area = decimalDigits(area);
    return area;
}

float Triangle::circumference()
{
    float deltaX1 = xCord[0] - xCord[1];
    float deltaY1 = yCord[0] - yCord[1];
    float length1 = sqrt(pow(deltaX1, 2.0) + pow(deltaY1, 2.0));

    float deltaX2 = xCord[1] - xCord[2];
    float deltaY2 = yCord[1] - yCord[2];
    float length2 = sqrt(pow(deltaX2, 2.0) + pow(deltaY2, 2.0));

    float deltaX3 = xCord[0] - xCord[2];
    float deltaY3 = yCord[0] - yCord[2];
    float length3 = sqrt(pow(deltaX3, 2.0) + pow(deltaY3, 2.0));

    float circumference = length1 + length2 + length3;
    circumference = decimalDigits(circumference);
    return circumference;
}

ReturnCords Triangle::position()
{
    float averageX = (xCord[0] + xCord[1] + xCord[2])/3;
    float averageY = (yCord[0] + yCord[1] + yCord[2])/3;
    averageX = decimalDigits(averageX);
    averageY = decimalDigits(averageY);
    ReturnCords mPosition(averageX, averageY);
    return mPosition;
}

bool Triangle::isConvex()
{
    return false;
}

float Triangle::distance(Shape *s)
{
    
    float deltaX = position().x - s->position().x;
    float deltaY = position().y - s->position().y;
    float distance = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
    distance = decimalDigits(distance);
    return distance;
}


