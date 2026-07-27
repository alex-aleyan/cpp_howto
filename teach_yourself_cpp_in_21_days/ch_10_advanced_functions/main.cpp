#include <iostream>

//-----------------------------------------------------------------------------------------------------------------------------
class Cat
{
public:
	Cat();
	Cat(const Cat &);
	Cat & operator=(const Cat &);
	~Cat();
	int GetAge() const {return *itsAge;}
	int GetWeight() const { return *itsWeight; }
	void SetAge(int age) { *itsAge = age; }
	void SetWeight(int weight) { *itsWeight = weight; }

private:
	int *itsAge;
	int *itsWeight;

};

Cat::Cat()
{
	itsAge = new int;
	itsWeight = new int;
	*itsAge = 5;
	*itsWeight = 9;
}

// Copy construct is used whenever the new object to be created is to be a copy of a current object rhs (rhs stands for right hand side).
Cat::Cat(const Cat & rhs)
{
	itsAge = new int;
	itsWeight = new int;
	*itsAge = rhs.GetAge(); // Using the reference to the object we copy the values of the original object so the copy object is a true copy!!!
	*itsWeight = *(rhs.itsWeight);// We can also use the private access to the member variable but it is a BAD PRACTICE!!! DONT DO IT, use GETS and SETS
}

Cat::~Cat()
{
	delete itsAge;
	itsAge = 0;
	delete itsWeight;
	itsWeight = 0;
}

//Since the class contains pointers, we must overload the '=' operator to make sure it changes the values the pointers contain and not where they point to.
Cat & Cat::operator= (const Cat & rhs)
{
	if (this == &rhs) return *this; // if we are equating lhs object to itself, we don't need to take care of object pointers locations
	this->SetAge(rhs.GetAge());
	this->SetWeight(rhs.GetWeight());
	return *this; // where this is the pointer to the lhs object so we just reassigning it to itself. 
}

//------------------------------------------------------------------------------------------------------------------------------------------------

class Rectangle
{
public:
	//construct
	Rectangle();
	Rectangle(int width, int height);
	~Rectangle() {}

	//overloaded class f-ions DrawShape
	void DrawShape() const; // CONST prevents the function from causing any changes to the Class Data.
	void DrawShape(int aWidth, int aHeight) const; // CONST prevents the function from causing any changes to the Class Data.

private:
	int itsWidth;
	int itsHeight;
};

//Constructor implementation
Rectangle::Rectangle(int width, int height)
{
	itsWidth = width;
	itsHeight = height;
}

Rectangle::Rectangle() 
	:itsWidth(5),itsHeight(10) // Using initialization stage instead of the body state to initialize the member variables.
{
	//itsWidth = 5;
	//itsHeight = 10;
}

void Rectangle::DrawShape() const // CONST prevents the function from causing any changes to the Class Data.
{
	// THIS IS VERY IMPORTANT WHEN OVERLOADING FUNCTIONS:
	// Instead of writing two implementations DrawShape, we write one that accepts 2 parameters
	// and an other one (which is this one) that passes DEFAULT parameters!!! Very nice trick since we
	// don't need to edit both functions should we need to edit the functionality of DrawShape...
	// CAUTION: This trick CANNOT be used on constructors!
	DrawShape(itsWidth, itsHeight);
}

void Rectangle::DrawShape(int width, int height) const // CONST prevents the function from causing any changes to the Class Data.
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

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


	//	Rectangle theRect;
	Rectangle theRect(30, 5);
	std::cout << "DrawShape: " << std::endl;
	theRect.DrawShape();
	std::cout << "\nDrawShape(40,2):" << std::endl;
	theRect.DrawShape(40, 2);
	std::cin >> x;
	return 0;
}
