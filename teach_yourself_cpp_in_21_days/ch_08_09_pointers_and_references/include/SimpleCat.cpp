#include "SimpleCat.h"
#include <iostream>

SimpleCat::SimpleCat()
{
    itsAge    = 1;
    itsWeight = 1;
    std::cout << "SimpleCat Object Created!";
}

void SimpleCat::SetAge(int age) { itsAge = age; }
int  SimpleCat::GetAge() const  { return itsAge; } // Using keyword const, we made it read only function. IT CANNOT CAUSE CHANGES TO THE OBJECT OF THIS CLASS!

void SimpleCat::SetWeight(int weight) { itsWeight = weight; }
int  SimpleCat::GetWeight() const     { return itsWeight; }