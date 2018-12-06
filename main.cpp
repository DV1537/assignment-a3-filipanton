#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "shape.h"
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "polygon.h"

struct OuputCords
{
    float *x;
    float *y;
    int arraySize;
    OuputCords(float *x, float *y, int arraySize)
    {
        this->x = x;
        this->y = y;
        this->arraySize = arraySize;
    }
};

Polygon operator+(Shape &shape, Shape &anotherShape)
    {
        float *ShapeX1 = shape.getXCord();
        float *ShapeY1 = shape.getYCord();
        int arraySize1 = shape.getArraySize();

        float *ShapeX2 = anotherShape.getXCord();
        float *ShapeY2 = anotherShape.getYCord();
        int arraySize2 = anotherShape.getArraySize();
      

        float *newShapeX = new float[arraySize1+arraySize2]{0.0};
        float *newShapeY = new float[arraySize1+arraySize2]{0.0};

        for(int i = 0; i < arraySize1; i++)
        {
            newShapeX[i] = ShapeX1[i];
            newShapeY[i] = ShapeY1[i];
        }
        for(int i = arraySize1; i < arraySize1+arraySize2; i++)
        {
            newShapeX[i] = ShapeX2[i-arraySize1];
            newShapeY[i] = ShapeY2[i-arraySize1];

        }
        int newArraySize = arraySize1+arraySize2;
        Polygon newPolygon(newShapeX, newShapeY, newArraySize);
        
        
        return newPolygon;
    }

std::ostream& operator<<(std::ostream& out, OuputCords object)
{
    for(int i = 0; i < object.arraySize ; i++)
    {
        std::cout << "(" << object.x[i] << "," << object.y[i] << ")\n";
    }

    return out;

}


void xArray(int &xArraySize, float input, int counterX, float *&arrX)
{
    if(counterX == xArraySize)
    {
        arrX[xArraySize -1] = input;
    }
    else
    {
        float *tempArray = new float[xArraySize+1]{0.0};
        for(int i = 0; i < xArraySize; i++)
        {
            tempArray[i] = arrX[i];
        }
        delete[] arrX;
        xArraySize++;
        arrX = new float[xArraySize];
        for(int x = 0; x < xArraySize; x++)
        {
            arrX[x] = tempArray[x];
        }
        arrX[xArraySize-1] = input;

    }
   
    
}

void yArray(int &yArraySize, float input, int counterY, float *&arrY)
{
    if(counterY == yArraySize)
    {
        arrY[yArraySize -1] = input;
    }
    else
    {
        float *tempArray = new float[yArraySize+1]{0.0};
        for(int i = 0; i < yArraySize; i++)
        {
            tempArray[i] = arrY[i];
        }
        delete[] arrY;
        yArraySize++;
        arrY = new float[yArraySize]{0.0};
        for(int x = 0; x < yArraySize; x++)
        {
            arrY[x] = tempArray[x];
        }
        arrY[yArraySize-1] = input;

    }
}

int main()
{
    float input = 0;
    std::string inputString1 = "";
    std::string inputString2 = "";
    int counter = 0;
    int counter2 = 0;
    int counterX = 0;
    int counterY = 0;
    int counterX2 = 0;
    int counterY2 = 0;
    float *arrX = new float[1]{0.0};
    float *arrY = new float[1]{0.0};
    float *arrX2 = new float[1]{0.0};
    float *arrY2 = new float[1]{0.0};
    int xArraySize = 1;
    int yArraySize = 1;
    int xArraySize2 = 1;
    int yArraySize2 = 1;
    std::ifstream myReadFile;
    myReadFile.open("cords");
    getline(myReadFile, inputString1);
    
        std::stringstream stream (inputString1);
        
        while(stream >> input)
        {
            
            
            counter++;

            if(counter % 2 == 0)
            {
                counterY++;
                yArray(yArraySize, input, counterY, arrY);
            }
            else
            {
                counterX++;
                xArray(xArraySize, input, counterX, arrX);
            }

        }
        getline(myReadFile, inputString2);

        std::stringstream stream2 (inputString2);
        
        while(stream2 >> input)
        {
                        
            counter2++;

            if(counter2 % 2 == 0)
            {
                counterY2++;
                yArray(yArraySize2, input, counterY2, arrY2);
            }
            else
            {
                counterX2++;
                xArray(xArraySize2, input, counterX2, arrX2);
            }

        }
    myReadFile.close();
    Polygon object(arrX, arrY, xArraySize);
    Shape *s = &object;
    Polygon object2(arrX2, arrY2, xArraySize2);
    Shape *s2 = &object2;
    Polygon result = *s + *s2;
    Shape* shape3 = &result;
    std::cout << "Area: " << shape3->area();

    
    
    getchar();
    return 0;
}