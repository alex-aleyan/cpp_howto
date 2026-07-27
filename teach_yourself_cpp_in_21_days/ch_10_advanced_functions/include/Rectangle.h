#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    public:
        //construct
        Rectangle();
        Rectangle(int width, int height);
        ~Rectangle() {}
    
        //overloaded class f-ions DrawShape
        void DrawShape() const; // CONST prevents the function from causing any changes to the Class Data.
        void DrawShape(int aWidth, int aHeight) const; // CONST prevents the function from causing any changes to the Class Data.
    
    private:
        int itsWidth;
        int itsHeight;
};

#endif