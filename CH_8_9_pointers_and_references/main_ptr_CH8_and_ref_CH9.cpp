#include <iostream>
class SimpleCat
{
public:
	SimpleCat();
	~SimpleCat() {}
	void SetAge(int age) { itsAge = age; }
	int GetAge() const { return itsAge; } // Using keyword const, we made it read only function. IT CANNOT CAUSE CHANGES TO THE OBJECT OF THIS CLASS!

	void SetWeight(int weight) { itsWeight = weight; }
	int GetWeight() const { return itsWeight; }

private:
	int itsAge;
	int itsWeight;
};

SimpleCat::SimpleCat()
{
	itsAge = 1;
	itsWeight = 1;
	std::cout << "SimpleCat Object Created!";
}


int Func1(int z);

// THIS IS A FUNCTION THAT RETURNS A REFERENCE 
SimpleCat & Func();

// THIS IS DECLARATION OF A REFERENCE TO A FUNCTION "int (&Func2)(int z)" AND ITS INITIALIZATION TO THE FUNCTION "Func1;"
int(&Func2)(int z) = Func1;

// REFERENCE TO A FUNCTION THAT RETURNS A REFERENCE:
// SimpleCat & (&rFunc3)() :	IS A DECLARATION OF A REFERENCE TO A FUNCTION WHERE THE REFERENCED FUNCTION RETURNS A REFERENCE.
// Func :						IS THE FUNCTION TO BE REFERENCED.
SimpleCat & (&rFunc3)() = Func;

//POINTER TO A FUNCTIONS THAT RETURNS A REFERENCE
// SimpleCat & (*func4)() :		IS A DECLARATION OF A POINTER TO A FUNCTION WHERE THE POINTED FUNCTION RETURNS A REFERENCE.
// Func :						IS THE FUNCTION TO BE REFERENCED.
SimpleCat & (*func4)() = Func;

//const SimpleCat *pReadOnlyPtr = new SimpleCat; // THIS POINTER CANNOT BE USED TO SET WEIGHT OR AGE
SimpleCat * const pStaticPtr = new SimpleCat; // THIS POINTER CANNOT CHANGE THE OBJECT IT POINTS TO!


int main()
{
	int x = 0;

	// the Func() function returns a reference to an object that was allocated using the Func(). 
	SimpleCat & rCat = Func();

	// using a reference(not a pointer) to function, call the function!!! The benefit of it is that we can pass this refernece to a function!
	Func2(5);

	std::cout << "--------------------------------------------------------------------\n";
	// REFERENCE TO A FUNCTION THAT RETURNS A REFERENCE:
	//Let's play with the pointer to the function that returns a reference:
	// The rFunc3() is an alias to a Func(); Thus the Func() is called using an alias.
	// The rFunc3() returns and alias to a newly allocated Object 
	// The new reference rCat3 is created and set as an alias to the reference returned by rFunc3().
	SimpleCat & rCat3 = rFunc3(); // rFunc3() aliases Func()
	std::cout << "rCat3.GetAge() returns : " << rCat3.GetAge() << "\n\n";
	std::cout << "rCat3.GetWeight() returns : " << rCat3.GetWeight() << "\n\n";

	std::cout << "Let's set the age: ";
	std::cin >> x;
	rCat3.SetAge(x);
	std::cout << "\n ";
	std::cout << "Let's check the age of rCat3.GetAge() now: " << rCat3.GetAge() << "\n\n";

	std::cout << "Let's set the weight: ";
	std::cin >> x;
	rCat3.SetWeight(x);
	std::cout << "\n";
	std::cout << "Let's check the weight of rCat3.WeightAge() now: " << rCat3.GetWeight() << "\n\n";

	std::cout << "--------------------------------------------------------------------\n";
	// POINTER TO A FUNCTION WHICH RETURNS A REFERENCE:
	// Let's play with the pointer to the function that returns a reference:
	// The pFunc4() is a pointer to a Func(); Thus the Func() is called using an pointer.
	// The pFunc4() returns and alias to a newly allocated Object 
	// The new reference pCat4 is created and set as an alias to the reference returned by pFunc4().
	SimpleCat & pCat4 = func4();

	std::cout << "Let's set the age: ";
	std::cin >> x;
	pCat4.SetAge(x);
	std::cout << "\n ";
	std::cout << "Let's check the age of rCat3.GetAge() now: " << pCat4.GetAge() << "\n\n";

	std::cout << "Let's set the weight: ";
	std::cin >> x;
	pCat4.SetWeight(x);
	std::cout << "\n";
	std::cout << "Let's check the weight of rCat3.WeightAge() now: " << pCat4.GetWeight() << "\n\n";

	std::cout << "--------------------------------------------------------------------\n";
	//CONST TYPE POINTER WHICH CANNOT CAUSE CHANGES TO AN OBJECT:
	const SimpleCat *pReadOnlyPtr = new SimpleCat; // THIS POINTER CANNOT BE USED TO SET WEIGHT OR AGE

	std::cout << "(*pReadOnlyPtr).GetAge() returns: " << (*pReadOnlyPtr).GetAge() << "\n\n";
	std::cout << "Let's now set the age using (*pReadOnlyPtr).SetAge() : ";
	std::cin >> x;
	//(*pReadOnlyPtr).SetAge(x); // AS EXPECTED, THIS WILL NOT WORK SINCE IT'S A CONST TYPE POINTER (READ ONLY POINTER)
	std::cout << "\n (*pReadOnlyPtr).GetAge() returns: " << (*pReadOnlyPtr).GetAge() << "\n\n";

	std::cout << "--------------------------------------------------------------------\n";
	// POINTER TO A REFERENCE(to a referenced object): 
	//Since using the (&) Address of Operator on a reference returns the address of a target the reference is aliased to, we
	// can set a pointer to a target using the &reference:
	SimpleCat *pPtr = new SimpleCat;
	SimpleCat & rAlias = *pPtr; // no rAlias is a reference/alias to the same piece of memory the pPtr points to!
								// Finally let's set the pointer to point to the aliased object:
	SimpleCat *pPtrToRef = &rAlias; // Here &Alias will return the address of the target the alias is a reference to!
	std::cout << "Let's see what our pointer returns now:" << " \n (*pPtrToRef).GetAge() returns: " << (*pPtrToRef).GetAge() <<
		" \n (*pPtrToRef).GetWeight() returns: " << (*pPtrToRef).GetWeight() << "\n\n";
	(*pPtrToRef).SetAge(99);
	(*pPtrToRef).SetWeight(1000);
	std::cout << "Let's see what our pointer returns now:" << " \n (*pPtrToRef).GetAge() returns: " << (*pPtrToRef).GetAge() <<
		" \n (*pPtrToRef).GetWeight() returns: " << (*pPtrToRef).GetWeight() << "\n\n";

	std::cout << "\n--------------------------------------------------------------------\n";
	std::cout << "Press any key+return to finish" << std::endl;
	std::cin >> x;
}

SimpleCat & Func() // THIS IS A FUNCTION THAT RETURNS A REFERENCE 
{
	SimpleCat *ptr = new SimpleCat();
	std::cout << "ptr: " << ptr << std::endl;
	return *ptr;
}

int Func1(int z) // THIS IS A FUNCTION WE WILL CREATE AN ALIAS FOR USING THE FUNC2 REFERENCE!!!!
{
	std::cout << "Using a reference to a function, z is " << z << "\n\n";
	return (z + 1);
}
