#include <iostream>
#include "Mammal.h"

#ifndef DOG_H
#define DOG_H

enum BREED {GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB, NUISANCE};

class Dog : public Mammal
{
public:
    //Attributes: Constructors
    //Dog() : itsBreed(GOLDEN) { std::cout << "Dog Constructor. \n"; }
    Dog(BREED breed) ;

    //#13: VIRTUAL COPY CONSTRUCTOR implementation using a COPY CONSTRUCTOR and a VIRTUAL CLONE() METHOD:
    Dog(const Mammal & rhs);

    virtual Mammal* Clone() { return new Dog(*this); std::cout << "Dog Virtrual Copy Construct\n"; }
    virtual        ~Dog()   { std::cout << "Dog Destructor. \n"; }

    //Attributes: Accessors
    BREED GetBreed() const      ;
    void  SetBreed(BREED breed) ;

    //Attributes: Other Methods
    void       WagTail()       ;
    void    BegForFood()       ;
    virtual void Speak() const { std::cout << "Woof, woof." << "\n"; }//#12: Virtual methods
    
protected:
    //Member Variable:
    BREED itsBreed;
};

#endif