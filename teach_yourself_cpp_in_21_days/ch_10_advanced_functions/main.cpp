#include <iostream>
#include "Cat.h"
#include "Rectangle.h"


int main()
{

    char x = 0;

    Cat Frisky;
    std::cout << "Frisky's age: " << Frisky.GetAge() << std::endl;
    std::cout << "Frisky's weight: " << Frisky.GetWeight() << std::endl;
    std::cout << "Setting Frisky's age to 6 and weight to 9: " << std::endl;
    Frisky.SetAge(6);
    Frisky.SetWeight(9);
    std::cout << "Making Whisker as a copy out of Frisky (Frisky is the CLICHE used to make Whiskers!): " << std::endl;
    Cat Whiskers(Frisky); // passing a Frisky reference to a copy construct so that Whiskers is basically a copy of a Frisky object!!!
    std::cout << "Whiskers' age: " << Whiskers.GetAge() << std::endl;
    std::cout << "Whiskers' weight: " << Whiskers.GetWeight() << std::endl;
    Whiskers.SetAge(21);
    Whiskers.SetWeight(50);
    std::cout << "Whiskers' age: " << Whiskers.GetAge() << std::endl;
    std::cout << "Whiskers' weight: " << Whiskers.GetWeight() << std::endl;
    //Using overloaded operator '=', let's see if it actually works!
    Frisky = Whiskers;
    std::cout << "Age of Frisky, after Frisky = Whiskers : " << Frisky.GetAge() << std::endl;
    std::cout << "Age of Frisky, after Frisky = Whiskers : " << Frisky.GetWeight() << std::endl;


    //    Rectangle theRect;
    Rectangle theRect(30, 5);
    std::cout << "DrawShape: " << std::endl;
    theRect.DrawShape();
    std::cout << "\nDrawShape(40,2):" << std::endl;
    theRect.DrawShape(40, 2);
    std::cin >> x;
    return 0;
}
