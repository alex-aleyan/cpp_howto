#include <iostream>
#include "Dog.h"
#include "Dog.h"

#ifndef BENTLEYBEAR_H
#define BENTLEYBEAR_H


class BentleyBear : public Dog
{
public:
    //BentleyBear() : Dog(NUISANCE) { std::cout << "BentleyBear Constructor. \n"; }
    BentleyBear(int age ) ;

    //#13: VIRTUAL COPY CONSTRUCTOR implementation using a COPY CONSTRUCTOR and a VIRTUAL CLONE() METHOD:
    BentleyBear(const Mammal & rhs) ;

    virtual Mammal* Clone() { return new BentleyBear(*this); std::cout << "BentleyBear Virtrual Copy Construct\n"; }
    virtual ~BentleyBear() { std::cout << "BentleyBear Destructor. \n"; }
    
    //Attributes: Other Methods
    virtual void Speak() const //#12: Virtual methods
    { 
        Dog::Speak(); // #10: See, we provide an enriched version of the Speak since Bentley is extra annoying in his barking!!!
        std::cout << ". Woooooooooooooooooooooooof!!! Wauw-wauw-wauw-wauw." << "\n"; 
    }

    virtual void begForIceCube() const //#12: Virtual methods
    {
        std::cout << "Gimme an ice cube, you, sucker!" << "\n";
    }

};


#endif