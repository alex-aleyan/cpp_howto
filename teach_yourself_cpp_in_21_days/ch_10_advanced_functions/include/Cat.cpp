#include "Cat.h"
#include <iostream>


Cat::Cat()
{
    itsAge = new int;
    itsWeight = new int;
    *itsAge = 5;
    *itsWeight = 9;
}

// Copy construct is used whenever the new object to be created is to be a copy of a current object rhs (rhs stands for right hand side).
Cat::Cat(const Cat & rhs)
{
    itsAge = new int;
    itsWeight = new int;
    *itsAge = rhs.GetAge(); // Using the reference to the object we copy the values of the original object so the copy object is a true copy!!!
    *itsWeight = *(rhs.itsWeight);// We can also use the private access to the member variable but it is a BAD PRACTICE!!! DONT DO IT, use GETS and SETS
}

Cat::~Cat()
{
    delete itsAge;
    itsAge = 0;
    delete itsWeight;
    itsWeight = 0;
}

//Since the class contains pointers, we must overload the '=' operator to make sure it changes the values the pointers contain and not where they point to.
Cat & Cat::operator= (const Cat & rhs)
{
    if (this == &rhs) return *this; // if we are equating lhs object to itself, we don't need to take care of object pointers locations
    this->SetAge(rhs.GetAge());
    this->SetWeight(rhs.GetWeight());
    return *this; // where this is the pointer to the lhs object so we just reassigning it to itself. 
}