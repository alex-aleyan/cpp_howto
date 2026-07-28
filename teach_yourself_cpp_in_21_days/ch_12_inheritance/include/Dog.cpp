#include "Dog.h"
#include <iostream>


Dog::Dog(BREED breed = LAB) : itsBreed(breed) { std::cout << "Dog Constructor. \n"; }

//#13: VIRTUAL COPY CONSTRUCTOR implementation using a COPY CONSTRUCTOR and a VIRTUAL CLONE() METHOD:
Dog::Dog(const Mammal & rhs) : Mammal(rhs) { std::cout << "Dog Copy Construct\n"; };



//Attributes: Accessors
BREED Dog::GetBreed() const     { return itsBreed; }
void  Dog::SetBreed(BREED breed) { itsBreed = breed; }

//Attributes: Other Methods
void         Dog::WagTail()     { std::cout << "Tail goes: Shuh-shuh-shuh... \n"; }
void         Dog::BegForFood()  { std::cout << "Gimme some food, human. \n"; }





