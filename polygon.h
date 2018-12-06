#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include <iostream>
#include <string>
#include <math.h>


class Polygon : public Shape
{


public:
    Polygon(float *x, float *y,int arraySize);
    bool lineIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
    bool intersect();
    std::string getType();
    float area();
    float circumference();
    ReturnCords position();
    bool isConvex();
    float distance(Shape *s);
    Polygon& operator=(Polygon &anotherShape)
    {
        arraySize = anotherShape.arraySize;
        delete[] xCord;
        delete[] yCord;

        xCord = new float[arraySize];
        yCord = new float[arraySize];
        for(int i = 0; i < arraySize-1; i++)
        {
        xCord[i] = anotherShape.xCord[i];
        yCord[i] = anotherShape.yCord[i];
        }
        

        return *this;
    }
    Polygon& operator+(float arr[])
    {
        float *tempArrayX = new float[arraySize+1]{0.0};
        float *tempArrayY = new float[arraySize+1]{0.0};
        for(int i = 0; i < arraySize; i++)
        {
            tempArrayX[i] = xCord[i];
            tempArrayY[i] = yCord[i];
        }
        delete[] xCord;
        delete[] yCord;
        arraySize++;
        xCord = new float[arraySize];
        yCord = new float[arraySize];
        for(int i = 0; i < arraySize; i++)
        {
            xCord[i] = tempArrayX[i];
            yCord[i] = tempArrayY[i];
        }
        xCord[arraySize-1] = arr[0];
        yCord[arraySize-1] = arr[1];

        return *this;

    }
    

    
};


#endif