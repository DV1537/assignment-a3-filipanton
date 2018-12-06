#ifndef POINT_H
#define POINT_H
#include "shape.h"
#include <iostream>
#include <string>

class Point : public Shape
{


public:
    Point(float *x, float *y, int arraySize);
    std::string getType();
    float area();
    float circumference();
    ReturnCords position();
    bool isConvex();
    float distance(Shape *s);
};


#endif