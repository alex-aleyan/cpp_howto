#include <iostream>
// FUNCTION THAT RETURNS A REFERENCE VS A REFERENCE TO A FUNCTION:
// THINGS TO REMEMBER:
// 1) * Indirection Operator (means the value stored at the address of this variable)
// 2) & Address of Operator
// 3) Why use pointers:
//		1. Managing data on the FREE STORE!!!
//		2. Accessing CLASS MEMBER DATA and FUNCTIONS!!!
//		3. Passing variables BY REFERENCE to allow a function access the data directly without making a copy and returning!
// 4) Memory (Cache, RAM, Bulk?):
//		1. Global namespace: stores Global Variables
//		2. Register(built in right into CPU so I guess it's cache): stores instruction pointer and so on
//		3. Code Space: stores the code
//		4. Stack(RAM?): stores local variables and f-ion parameters.
//		5. Free Store (The bulkiest; Hard Drive or RAM?): stores remaining memory
//	5) To allocate memory, use "new type". To Deallocate memory, use "delete object_address"
//	6) When creating an object from a class:
//		1. Use the constructor to allocate items from the heap/stack
//		2. Use destructor to deallocate items from the heap/stack (dont forget to test the pointer for NULL before deallocating) since the
//		   destructor is called everytime an object is being deleted: delete pPtr_to_object see page 239 for a good example.
//	7) Memory Leak can occur:
//		1. When the pointer used to point to allocated memory goes out of scope (at the end of function);
//		2. When reassining the pointer to point somewhere else without deallocating the memory it currently points to.
//		3. Stray pointer: Deallocating memory without setting its pointer to NULL results in a stray pointers which still points to the same
//						  memory block but that memory block is now used for something else.
//	8) If a method of a class is defined during the class declarationr, this method is defined as an inline function/method automatically.
//	9) THIS pointer: Each class member function/method has a hidden parameter THIS pointer. THIS pointer is automatically set to point to
//					the object of the declared class. Thus, it can be used on data and methods within definitions local to that object. See page 244.
//	10) Reference has properties of an ALIAS (#define) and of a POINTER since it can be used to pass a reference to a function:
//	11) Declaring an reference:
//			int &alias; // good
//			int & alias; // good
//			int& alias; // NOT GOOD!
//	12) When the Address of Operator (&) is used on an reference, it returns the address of its target.
//	13) A pointer can be set to a target of a reference using: type *ptr = &alias; which is same as type *ptr = &target;
//		Also, this is dangerous since you might accidentally deallocate the target thus leaving the reference that's aliased to nothing.
//	14) DO NOT ATTEMPT TO REASSIGN A REFERENCE!!!
//	15) Reference can be initialzied to NULL as long as it's not used while initialized to NULL -- STAY AWAY FROM THIS NULL INITIALIZATION!
//	16) We say PASSING BY REFERENCE when using a pointer, and we say PASSING A REFERENCE when using a reference/alias.
//	17) When passing an OBJECT by VALUE, an other copy of this object is made thus the memory is consumed: Use Pointers and References to save memory.
//	18) USING CONST:
//		1.	To be safe, use const type *ptr to pass an access to an object even if the class is not of the const type. 
//			Using CONST TYPE make the pointer of READ ONLY type. It can only pull information out of this object but it can't change the object data.
//		2.	When declaring a method inside a class, use keyword const to make it a read only method: type GetData() const {return SomeData;}
//		3.	When passing a pointer that point to an object, use next trick to make the function think that it's a READ ONLY TYPE Object even if it's not:
//			const type * func(const type *ptr)
//			{
//			some stuff goes here. Similar trick can be used on REFERENCES, justsSee page 276 and 278 for details!
//			}
//		4. Remember:
//				const type *ptr is a pointer to a type const. Meaning, pointer can't change Data.
//				type * const ptr is a constant pointer. It can only be set to point to one object and it CANNOT be set to point to another object after.
//				const type * const ptr can only point to one object and can't change Data in that object.
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