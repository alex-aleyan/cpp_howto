#include <iostream>

#include "Cat.h"

int main()
{
    // Object Frisky is instantiated by the Client:
    Cat Frisky(10,10);
    std::cout << "Frisky is a cat that is " << Frisky.getAge()    << " years old. \n";
    std::cout << "Frisky's weight is "      << Frisky.getWeight() << " kilos.     \n\n";

    Frisky.setAge(5);
    Frisky.setWeight(15);
    std::cout << "Frisky is a cat that is " << Frisky.getAge()    << " years old \n";
    std::cout << "Frisky's weight is "      << Frisky.getWeight() << " kilos.    \n\n";

    Frisky.meow();

    system("sleep 1");
}
