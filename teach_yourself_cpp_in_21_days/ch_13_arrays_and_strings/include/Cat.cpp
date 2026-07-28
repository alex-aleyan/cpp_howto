#include "Cat.h"
#include <iostream>


     Cat::Cat() { itsAge = 1; itsWeight = 5;}
     Cat::~Cat(){}

int  Cat::GetAge() const { return itsAge; }
int  Cat::GetWeight() const { return itsWeight; }
void Cat::SetAge(int age) { itsAge = age; }
void Cat::SetWeight(int weight) { itsWeight = weight; }
