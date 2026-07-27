#include "Mammal.h"
#include <iostream>


// // constructor
// //Mammal() :itsAge(2), itsWeight(5) { std::cout << "Mammal Constructor. \n"; }
// Mammal::Mammal(int age, int weight) :itsAge(age), itsWeight(weight) { std::cout << "Mammal Constructor. \n"; }

// //#13: VIRTUAL COPY CONSTRUCTOR implementation using a COPY CONSTRUCTOR and a VIRTUAL CLONE() METHOD:
// Mammal::Mammal(const Mammal & rhs) : itsAge(rhs.GetAge()) { std::cout << "Mammal Copy Construct\n" ; }

// virtual Mammal* Mammal::Clone()  { return new Mammal(*this); std::cout << "Mammal Virtrual Copy Construct\n";}
// virtual        ~Mammal::Mammal() { std::cout << "Mammal Destructor. \n"; }

//accessors
int  Mammal::GetAge() const { return itsAge; }
void Mammal::SetAge(int age) { itsAge = age; }
int  Mammal::GetWeight()const { return itsWeight; }
void Mammal::SetWeight(int weight) { itsWeight = weight; };

//other methods
void Mammal::Sleep() const { std::cout << "Mammal makes sound when sleeping: Zzz-Zzz" << "\n"; }




