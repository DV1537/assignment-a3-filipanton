#include <iostream>
#include <string>
#include <cmath>
#include "polygon.h"


bool Polygon::intersect()
{
    bool intersecting = false;
    bool skip = false;
    for(int j = 0; j < arraySize; j++)
    {
        for(int i = 0; i < arraySize-2; i++)
        {
            intersecting = lineIntersect(xCord[j], yCord[j], xCord[j+1], yCord[j+1], xCord[i+1], yCord[i+1], xCord[i+2], yCord[i+2]);
            if(intersecting == true)
            {
                i = arraySize;
                j = arraySize;
                skip = true;

            }
        }
        if(skip == false)
        {
            intersecting = lineIntersect(xCord[j], yCord[j], xCord[j+1], yCord[j+1], xCord[j], yCord[j], xCord[arraySize-1], yCord[arraySize-1]);
            if(intersecting == true)
            {
                j = arraySize;
            }
        }
    }
    return intersecting;
}

bool Polygon::lineIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    float a1 = y2 - y1; 
    float b1 = x1 - x2; 
  
    
    float a2 = y4 - y3; 
    float b2 = x3 - x4; 
    
  
    float determinant = a1*b2 - a2*b1; 
    
    bool intersecting = false;
    if (determinant == 0.0) 
    { 
        return intersecting;
    } 
    else
    { 
        
        float tA = ((y3 - y4)*(x1 - x3) + (x4 - x3)*(y1 - y3))/((x4 - x3)*(y1 - y2)-(x1-x2)*(y4-y3));
        float tB = ((y1 - y2)*(x1 - x3) + (x2 - x1)*(y1 - y3))/((x4 - x3)*(y1 - y2)-(x1-x2)*(y4-y3));
        if(tA < 1 && tA > 0 && tB < 1 && tB > 0)
        {
            intersecting = true;
            return intersecting;
        }
        else
        {
            return intersecting;
        }

    } 
}

Polygon::Polygon(float *x, float *y, int arraySize)
{
    xCord = x;
    yCord = y;
    this->arraySize = arraySize;
    
}

std::string Polygon::getType()
{
    return "polygon";
}

float Polygon::area()
{
    bool selfIntersecting = false;
    bool convex = true;
    selfIntersecting = intersect();
    convex = isConvex();
    if(selfIntersecting == true || convex == false)
    {
        return -1;
    }
    float area = 0;
    int j = arraySize -1;

    for(int i = 0; i < arraySize; i++)
    {
        area +=(xCord[j]+ xCord[i]) * (yCord[j]- yCord[i]);
        j = i;
    }
    area = std::abs(area/2.0);
    area = decimalDigits(area);
    return area;
}

float Polygon::circumference()
{
    float circumference = 0;
    int j = arraySize -1;
    float deltaX = 0;
    float deltaY = 0;
    float length = 0;

    for(int i = 0; i < arraySize; i ++)
    {

    
        deltaX = xCord[i] - xCord[j];
        deltaY = yCord[i] - yCord[j];
        length = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
        circumference += length;
        j=i;

    }

    
    circumference = decimalDigits(circumference);
    return circumference;
}

ReturnCords Polygon::position()
{   
    bool selfIntersecting = false;
    selfIntersecting = intersect();
    if(selfIntersecting == true)
    {
        std::cout << "ERROR: CAN ONLY CALCULATE CENTROID OF NON SELF INTERSECTING POLYGON, DEFAULT CENTROID (0.0 , 0.0)" << std::endl;
        ReturnCords centroid(0.0, 0.0);
        return centroid;
    }
    float A;
    float averageX;
    float averageY;
    for(int i = 0; i <arraySize-1; i++)
    {
        A += (xCord[i] * yCord[i+1]) - (xCord[i+1] * yCord[i]);
    }

    for(int i = 0; i < arraySize -1; i++)
    {
        averageX += (xCord[i] + xCord[i+1]) * ((xCord[i] * yCord[i+1]) - (xCord[i+1] * yCord[i]));
    }

    for(int i = 0; i < arraySize -1; i++)
    {
        averageY += (yCord[i] + yCord[i+1]) * ((xCord[i] * yCord[i+1]) - (xCord[i+1] * yCord[i]));
    }
    A = A * (1.0/2.0);
    averageX = averageX * (1/(6.0*A));
    averageY = averageY * (1/(6.0*A));
    averageX = decimalDigits(averageX);
    averageY = decimalDigits(averageY);
    ReturnCords centroid(averageX, averageY);
    return centroid;
    
}

bool Polygon::isConvex()
{
    bool isConvex = true;
    bool selfIntersecting = false;
    selfIntersecting = intersect();
    if(selfIntersecting == true)
    {
        isConvex = false;
        return isConvex;
    }
    bool checkIfPositive = false;
    bool checkIfNegative = false;
    
    
    float dx1 = 0.0;
    float dy1 = 0.0;
    float dx2 = 0.0;
    float dy2 = 0.0;
    float zcrossproduct = 0.0;
    for(int x = 0; x < arraySize-2; x++)
    {
        dx1 = xCord[x+1]-xCord[x];
        dy1 = yCord[x+1]-yCord[x];
        dx2 = xCord[x+2]-xCord[x+1];
        dy2 = yCord[x+2]-yCord[x+1];
        zcrossproduct = dx1*dy2 - dy1*dx2;
        if(zcrossproduct < 0 &&  x == 0)
        {
            checkIfNegative = true;
        }
        if(zcrossproduct >= 0 &&  x == 0)
        {
            checkIfPositive = true;
        }
        if(checkIfPositive == true)
        {
            if(zcrossproduct <= 0)
            {
                isConvex = false;
                x = arraySize;
            }
        }
        if(checkIfNegative == true)
        {
            if(zcrossproduct >= 0)
            {
                isConvex = false;
                x = arraySize;
            }
        }
    }
        if(isConvex != false)
        {
        dx1 = xCord[arraySize-1]-xCord[arraySize-2];
        dy1 = yCord[arraySize-1]-yCord[arraySize-2];
        dx2 = xCord[0]-xCord[arraySize-1];
        dy2 = yCord[0]-yCord[arraySize-1];
        zcrossproduct = dx1*dy2 - dy1*dx2;
        if(checkIfPositive == true)
        {
            if(zcrossproduct <= 0)
            {
                isConvex = false;
                
            }
        }
        if(checkIfNegative == true)
        {
            if(zcrossproduct >= 0)
            {
                isConvex = false;
                
            }
        }
        dx1 = xCord[0]-xCord[arraySize-1];
        dy1 = yCord[0]-yCord[arraySize-1];
        dx2 = xCord[1]-xCord[0];
        dy2 = yCord[1]-yCord[0];
        zcrossproduct = dx1*dy2 - dy1*dx2;
        if(checkIfPositive == true)
        {
            if(zcrossproduct <= 0)
            {
                isConvex = false;
                
            }
        }
        if(checkIfNegative == true)
        {
            if(zcrossproduct >= 0)
            {
                isConvex = false;
                
            }
        }
        }
    return isConvex;
}

float Polygon::distance(Shape *s)
{
    
    float deltaX = position().x - s->position().x;
    float deltaY = position().y - s->position().y;
    float distance = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
    distance = decimalDigits(distance);
    return distance;
}


