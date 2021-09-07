#include <iostream>

// Class Interface starts here and strentches through the next 23 lines:
class Cat
{
public:

// CONSTRUCTOR:
	Cat(int age = 1, int weight = 5) { itsAge = age; itsWeight = weight; };

// DESTRUCTOR:
	// notice, even so the DESTRUCTOR doesn't do anything, we still have to define it by using an empty block { } or a cout statement:
	~Cat() { std::cout << "Destructor envoked; it's content could've been left empty;\n"; }; 

// PUBLIC ACCESSORs:
	// Putting the definition of this method into the class interface make this method's implementation of type INLINE. 
	// Notice, since this is a SET kind of method, it is not of a const type.
	void setAge(int age) { itsAge = age; };

	// Putting the definition of this method into the class interface make this method's implementation of the type INLINE. 
	// Also, using the const keyword right after the method's tag, we restrict this method from being able to change 
	// the content of data members:int getAge() const { return itsAge; }; 
	void setWeight(unsigned int weight) { itsWeight = weight; };
	int getWeight() const { return itsWeight; };

// OUR CAT CAN MEOW NOW:
	void meow() const { std::cout << "Meow-meow. Feed me, you, B@$T@ЯD. \n"; };

private:
	// All the data members are private:
	int itsAge;
	int itsWeight;
};

int main()
{
	// Object Frisky is instantiated by the Client:
	Cat Frisky(10,10);
	std::cout << "Frisky is a cat that is " << Frisky.getAge() << " years old. \n";
	std::cout << "Frisky's weight is " << Frisky.getWeight() << " kilos. \n";
	Frisky.setAge(5);
	Frisky.setWeight(15);
	std::cout << "Frisky is a cat that is " << Frisky.getAge() << " years old \n";
	std::cout << "Frisky's weight is " << Frisky.getWeight() << " kilos. \n";
	Frisky.meow();
	system("pause");
}
