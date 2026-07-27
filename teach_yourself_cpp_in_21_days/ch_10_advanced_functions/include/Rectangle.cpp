#include "Rectangle.h"
#include <iostream>


//Constructor implementation
Rectangle::Rectangle(int width, int height)
{
    itsWidth = width;
    itsHeight = height;
}

Rectangle::Rectangle() 
    :itsWidth(5),itsHeight(10) // Using initialization stage instead of the body state to initialize the member variables.
{
    //itsWidth = 5;
    //itsHeight = 10;
}

void Rectangle::DrawShape() const // CONST prevents the function from causing any changes to the Class Data.
{
    // THIS IS VERY IMPORTANT WHEN OVERLOADING FUNCTIONS:
    // Instead of writing two implementations DrawShape, we write one that accepts 2 parameters
    // and an other one (which is this one) that passes DEFAULT parameters!!! Very nice trick since we
    // don't need to edit both functions should we need to edit the functionality of DrawShape...
    // CAUTION: This trick CANNOT be used on constructors!
    DrawShape(itsWidth, itsHeight);
}

void Rectangle::DrawShape(int width, int height) const // CONST prevents the function from causing any changes to the Class Data.
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}