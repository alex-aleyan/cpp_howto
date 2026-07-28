
#include "BentleyBear.h"
#include <iostream>



//BentleyBear() : Dog(NUISANCE) { std::cout << "BentleyBear Constructor. \n"; }
BentleyBear::BentleyBear(int age = 5) : Dog(NUISANCE) { this->itsAge = age;  std::cout << "BentleyBear Constructor. \n"; }

//#13: VIRTUAL COPY CONSTRUCTOR implementation using a COPY CONSTRUCTOR and a VIRTUAL CLONE() METHOD:
BentleyBear::BentleyBear(const Mammal & rhs) : Dog(rhs) { std::cout << "BentleyBear Copy Construct\n"; };