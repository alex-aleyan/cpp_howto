#include <iostream>

#ifndef MAMMAL_H
#define MAMMAL_H


class Mammal
{
public:
    // constructor
    //Mammal() :itsAge(2), itsWeight(5) { std::cout << "Mammal Constructor. \n"; }
    Mammal(int age = 2, int weight = 5) :itsAge(age), itsWeight(weight) { std::cout << "Mammal Constructor. \n"; }

    //#13: VIRTUAL COPY CONSTRUCTOR implementation using a COPY CONSTRUCTOR and a VIRTUAL CLONE() METHOD:
    Mammal(const Mammal & rhs) : itsAge(rhs.GetAge()) { std::cout << "Mammal Copy Construct\n" ; }

    virtual Mammal* Clone()  { return new Mammal(*this); std::cout << "Mammal Virtrual Copy Construct\n";}
    virtual        ~Mammal() { std::cout << "Mammal Destructor. \n"; }

    //accessors
    int GetAge() const ;
    void SetAge(int age) ;
    int GetWeight()const ;
    void SetWeight(int weight) ;

    //other methods
    virtual void Speak() const { std::cout << "Mammal makes sound of: Pfff-Pfff"<<"\n"; } //#12: Virtual methods

    void Sleep() const;

protected:
    int itsAge;
    int itsWeight;
};


#endif