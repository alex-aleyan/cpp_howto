#ifndef ANIMAL
#define ANIMAL

#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Animal
{
public:
    Animal(int weight = 0);
    //Animal();
    ~Animal();
    int GetWeight() const { return itsWeight;}
    void  displayWeight() const { cout << "Animal.displayWeight()=" << itsWeight << endl; }
private:
    int itsWeight;
};

Animal::Animal(int weight) :
    itsWeight(weight) {
    cout << "Constructor: Animal(int weight)" << endl;
}

Animal::~Animal() {
    cout << "Destructor: ~Animal(int weight)" << endl;
}


#endif