#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
#include <iostream>
#include <string>

class Triangle : public Shape
{

public:
    Triangle(float *x, float *y, int arraySize);
    std::string getType();
    float area();
    float circumference();
    ReturnCords position();
    bool isConvex();
    float distance(Shape *s);
};


#endif