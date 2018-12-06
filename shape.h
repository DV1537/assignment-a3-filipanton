#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>

struct ReturnCords
{
    float x;
    float y;
    ReturnCords(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};

class Shape
{
protected:
    float *xCord;
    float *yCord;
    int arraySize;
public:

    float decimalDigits(float a)
    {
        a = round( a* 1000.0 ) / 1000.0;
        return a;
    }   
    float* getXCord()
    {
        return xCord;
    }
    float* getYCord()
    {
        return yCord;
    }
    int getArraySize()
    {
        return arraySize;
    }
    virtual std::string getType() = 0;
    virtual float area() = 0;
    virtual float circumference() = 0;
    virtual ReturnCords position() = 0;
    virtual bool isConvex() = 0;
    virtual float distance(Shape *s) = 0;
};


#endif