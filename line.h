#ifndef LINE_H
#define LINE_H
#include "shape.h"
#include <iostream>
#include <string>

class Line : public Shape
{


public:
    Line(float *x, float *y, int arraySize);
    std::string getType();
    float area();
    float circumference();
    ReturnCords position();
    bool isConvex();
    float distance(Shape *s);
};


#endif