//	1)How to :
//		1. overload member functions
//		2. overload operators
//		3. write f-ions to support classes with dynamically allocated variables
//	2) Polymorphism/FunctionOverloading: writing two or more f-ions with the same name but different parameter list.
//	3) When to use FUNCTION OVERLOADING (multiple functions with the same name, but with different parameter lists):
//		1. No reasonable default value exists.
//		2. You need different algorithms
//		3. Different types need to be supported in the parameter list.
//	4) IMPORTANT: Whenever you provide a class with a constructor that accepts arguments, you must provide a DEFAULT CONSTRUCTOR(paramereless consructor)!!!
//				  Thus, the constructor that accepts no arguments but setup your object as required!!!
//	5) A CONSTRUCTOR consists of an INITIALIZATION STAGE and the BODY. When constructor is used to initialize an object's data, use the initializations stage of the constructor.
//	6) If a copy of a class object is to be made, it's a good idea to use the copy construct property: If this object contains pointers, than the copy of the pointers will be made
//	   and the new pointers will be pointing to the same member data as the original object. This leads to a disaster when either of the objects goes out of
//	   scope!!! Thus, as a rule of thumb do next:
//		1. All member variables should be pointers to space allocated by the CONSTRUCT of that class.
//		2. A MUST TO USE a COPY CONSTRUCT which will allocate new space for the new member variable pointers to point to!!!
//		see the Cat example below and check the page 300 of the book
//	7) Overloading the Prefix Operator: returnType OPERATOR op () Ex: void operator++ () works kind of like a function but using the keyword operator
//	   followed by the operator to be replaced:
//	8) When overloading operators, remember:
//		1. If the operator's return type is VOID, the operator can be applied onto an object (++i) but it CANNOT be assigned to an object (x = ++i). See Analysis on pg 305.
//		2. The return value of an overloaded operator can be an object thus allowing us to assign its returned object to an other object (x = ++i). See Listing 10.10.
//		3. Use THIS POINTER (pointer to the object of the class) to avoid creating temporary objects!!!!!!! THIS pointer can be used inside any kind of
//		   proceedure implimenting method definitions of a particular class (ClassName::CONSTRUCT{...}; ClassName::DESTRUCT{...}; ClassName::SOME_METHOD{...}) See Listing 10.11
//		4. The RETURN type of the OVERLOADING OPERATOR should be of type CONSTANT. This will prevent any operation performed on its returned object (++++i). See Listing 10.11
//		5. When overloading BINARY OPERATORS, done the same way as postfix: ReturnType Class::OPERATORop (ParameterType & rhs){ return ReturnClass(this->value op rhs.value) }
//		   but make sure that the construct initilizes the just created object of ReturnClass before it's being returned. SEE LISTING 10.14!!!!!!!!
//		6. It's a good idea to provide the class with its own assignment operator. This way we can make sure that the pointers contained in the lhs object are not being set to point
//		   to the same memory locations where the pointers of the rhs object are pointing to. Instead, we should write our own assignment operator to make sure that
//		   the pointers of the lhs object get the values of the pointers of the rhs object. Example:
//				Cat & Cat::operator= (const Cat & rhs)
//					{
//						if (this = &rhs) return *this; // if we are equating lhs object to itself, we don't need to take care of object pointers locations
//						*itsAge = rhs.GetAge();
//						*itsWeight = rhs.GetWeight();
//					return *this // where this is the pointer to the lhs object so we just reassigning it to itself. 
//					}


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