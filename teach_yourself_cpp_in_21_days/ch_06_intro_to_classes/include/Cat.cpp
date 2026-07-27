#include "Cat.h"
#include <iostream>



// CONSTRUCTOR:
Cat::Cat(int    age = 1, 
    int weight = 5) 
    {   itsAge    = age; 
        itsWeight = weight; };

// DESTRUCTOR:
// notice, even so the DESTRUCTOR doesn't do anything, we still have to define it by using an empty block { } or a cout statement:
Cat::~Cat() { std::cout << "Destructor envoked; it's content could've been left empty;\n"; }; 

// PUBLIC ACCESSORs:
// Putting the definition of this method into the class interface make this method's implementation of type INLINE. 
// Notice, since this is a SET kind of method, it is not of a const type.
void Cat::setAge(int age) { itsAge = age; };

int  Cat::getAge() const  { return itsAge; };

// Putting the definition of this method into the class interface make this method's implementation of the type INLINE. 
// Also, using the const keyword right after the method's tag, we restrict this method from being able to change 
// the content of data members:int getAge() const { return itsAge; }; 
void Cat::setWeight(unsigned int weight) { itsWeight = weight; };

int  Cat::getWeight() const              { return itsWeight; };

// OUR CAT CAN MEOW NOW:
void Cat::meow() const { std::cout << "Meow-meow. Feed me. \n"; };