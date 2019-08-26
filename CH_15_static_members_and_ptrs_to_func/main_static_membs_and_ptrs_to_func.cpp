//	SPECIAL CLASSES AND FUNCTIONS: USED TO SHARE DATA AMONG ALL INSTANCES OF A PARTICULAR CLASS!
//	1.	A PUBLIC STATIC MEMBER VARIABLES: Shared among all instances of a class (similar to global variables). They are created outside the class they belong to and thus they exist even if an object of 
//		the class was not created.
//	2.	Static Members can be accessed using NON STATIC MEMBER FUNCTIONS, but this requires an object of the class it belong to to be created which sucks (REQUIRES AN OBJECT INSTANTIATION)
//	3.	To provide access to STATIC DATA MEMBER without instantiating an object of the corresponding Class, a STATIC MEMBER FUNCTION has to be provided (DOES NOT REQUIRE AN OBJECT INSTANTIATION)
//		It should be noted that static member functions:
//		-	DO NOT have access to THIS pointer and CANNOT be made const as a result.
//		-	DO NOT have access to NON-STATIC MEMBER VARIABLES
//		-	CAN BE CALLED EVEN WHEN AN OBJECT OF THE CLASS THEY BELONG TO DOES NOT EXIST (was not created).
//	4.	POINTERS TO A FUNCTION:
//			Declaring a pointer to a function:				ReturnType (* pFuncName)(int arg1);
//				Also, derefencing a pointer to a function is optional and the function can be called using both: pFuncName(x) or  (*pFuncName)(x)
//			Function that returns a pointer:				ReturnType * FunctionName(int arg1);
//		Benefits of the pointers to functions:
//		-	Eliminate duplicate code.--
//		-	Clarify a program.
//		-	Enable tables of functions that can be chosen from during run-time.
//		It should be noted that Object-Oriented programming does not normally require pointers to functions. If an array of function pointers is used, the rpogrammer should ask himself whether an
//		array of appropriate objects is what actually needed instead!
//	5.	ARRAYS OF POINTERS TO FUNCTIONS:
//			Declaring an array of pointers to functions:	ReturnType (*pFuncArray[ArraySize])(type Param1, typeParam2);
//	6.	PASSING A FUNCTION POINTER TO A FUNCTION
//	7.	Using TYPEDEF with function pointers:
//			Next syntax is used:								typedef ReturnType(*TYPE_NAME) (int &, int &); 
//			which allows us to declare a function pointer as:	TYPE_NAME pFunc; 
//	8.	POINTERS TO MEMBER FUNCTIONS (Should be avoided): 
//			-	Used in the same way as pointers to functions, but require an object of the correct class on which to invoke the pointer
//			-	When the pointer to a member function of the DERIVED CLASS is set to point to an object of the DERIVED CLASS, virtualization holds true! 
#include <iostream>
using namespace std;

class Cat1
{
public:
	// Increment the STATIC MEMBER VARIABLE HowManyCats everytime a cat is made
	Cat1(int age): itsAge(age) { HowManyCats++; }
	// Increment the STATIC MEMBER VARIABLE HowManyCats everytime a cat is made
	virtual ~Cat1() { HowManyCats--; }
	virtual int GetAge() { return itsAge; }
	virtual void SetAge(int age) { itsAge = age; }

//	#1:	HowManyCats is DECLARED to be a PUBLIC STATIC MEMBER VARIABLE:
	static int HowManyCats;

//	#2: we can provide non-static member function to access a static data members:
	virtual int GetHowManyCats() { return HowManyCats; }

//	#3: we can provide the class with a STATIC MEMBER FUNCTION to allow the STATIC DATA MEMBER to be accessed without instantiating an object of this class:
	static int GetHowManyCatsPrivate() { return HowManyCatsPrivate; } // this function DOES NOT require an OBJECT, but HAS TO BE FULLY QUALIFIED as Class::Func(); .



private:
	int itsAge;
//	#3:	and to make it safer, lets make our STATIC DATA MEMBER a private
	static int HowManyCatsPrivate;

};


//	#1:	THIS IS HOW A PUBLIC STATIC MEMBER VARIABLE IS CREATED (DEFINED AND INITIALIZED) BY DECLARING IT OUTSIDE THE CLASS DEFINITION. Thus its existence DOES NOT depend of the existance of an object of the class 
//		(the class this data member belongs to):
int Cat1::HowManyCats = 0;

//	#3:	THIS IS HOW A PRIVATE STATIC MEMBER VARIABLE IS CREATED (DEFINED AND INITIALIZED) BY DECLARING IT OUTSIDE THE CLASS DEFINITION. Thus its existence DOES NOT depend of the existance of an object of the class 
//		(the class this data member belongs to):
int Cat1::HowManyCatsPrivate = 0;


//	#1:	Using a PUBLIC STATIC VARIABLE
void TelepathicFunction()
{
	cout << "There are " << Cat1::HowManyCats << " cats alive!\n";
}

//	#3:	THIS FUNCTION TelepathicFunctionPrivate() IMPLEMENTS A STATIT MEMBER FUNCTION Cat1::GetHowManyCatsPrivate() TO ACCESS THE STATIC DATA MEMBER HowManyCatsPrivate and DOES NOT REQUIRE 
//		an OBJECT to be instantiated:
void TelepathicFunctionPrivate()
{
	cout << "There are " << Cat1::GetHowManyCatsPrivate() << " cats alive!\n"; 
}

//	#4:	POINTERS TO A FUNCTION:
void Square(int &rX, int &rY) 
{
	cout << rX * rX << endl;
	cout << rY * rY << endl;
}

void Cube(int &rX, int &rY)
{
	cout << rX*rX*rX << endl;
	cout << rY*rY*rY << endl;
}

//	#6:	PASSING A FUNCTION POINTER TO A FUNCTION

// also if its definition was placed after the main and only the declaration was placed here, we could've used void PrintValues( void(*)(int &, int &) , int & , int & 1) instead
void PrintValues(void(*func)(int &, int &), int &x, int &y) 
{
	(*func)(x, y);
	cout << "x: " << x << "\n";
	cout << "y: " << y << "\n";
}


typedef void(*FUNCTION_POINTER)(int &, int&);

int main()
{
	const int MaxCats = 5; int i;

	// An array of pointers:
	Cat1 *CatHouse[MaxCats];

	for (i = 0; i < MaxCats; i++)
	{
		CatHouse[i] = new Cat1(i);

		//	#2:	A STATIC MEMBER FUNCTION IS USED TO SEE HOW MANY CATS ARE LEFT ALIVE:
		TelepathicFunction();	
	}

	for (i = 0; i < MaxCats; i++)
	{
		
		cout << "There are ";
//	#2:	Using the object and its NON-STATIC member function we can obtain the value stored by the STATIC data member:
		cout << "#2: ACCESSING A STATIC DATA MEMBER USING A NON-STATIC MEMBER FUNCTION:\n";
		cout << CatHouse[i]->GetHowManyCats();
		cout << " cats left!" ;

		cout << "Deleting the one that is ";
		cout << CatHouse[i]->GetAge();
		cout << " years old" << endl;
		delete CatHouse[i];
		CatHouse[i] = 0;

//	#3:	THIS FUNCTION TelepathicFunctionPrivate() IMPLEMENTS A STATIC MEMBER FUNCTION Cat1::GetHowManyCatsPrivate() TO ACCESS THE STATIC DATA MEMBER HowManyCatsPrivate and DOES NOT REQUIRE 
//		an OBJECT to be instantiated:
		cout << "#3: ACCESSING A STATIC DATA MEMBER USING A STATIC MEMBER FUNCTION:\n";
		TelepathicFunctionPrivate();
		
 	}

//	#4:	POINTERS TO A FUNCTION:
	cout << "#4: POINTERS TO A FUNCTION:\n";
	void(*pFunc) (int &, int &) = NULL;

	cout << "#4: POINTERS TO A FUNCTION:\n";
	int val1 = 0, val2 = 0, choice = 0;
	cout << "enter value1: ";	cin >> val1;	cout << endl;
	cout << "enter value2: ";	cin >> val2;	cout << endl;
	cout << "Press (2) for Square or (3) Cube: ";	cin >> choice; cout << endl;
	switch (choice)
	{
		case 2: pFunc = Square; pFunc(val1, val2); break;
		case 3: pFunc = Cube; pFunc(val1, val2); break;
		default: cout << "nothing to calculate\n"; break;
	}

//	#5:	ARRAY OF POINTERS TO FUNCTIONS:
	cout << "#5: ARRAY OF POINTERS TO FUNCTIONS:\n";
	const int MaxArray = 2;
	//ARRAY OF POINTERS TO FUNCTIONS DECLARED
	void(*pFuncArray[MaxArray])(int &x, int &) = { NULL, NULL};
	//Let's be extra tedious and literate, and initialize the pointer to NULL
	for (i = 0; i < MaxArray; i++)
	{
		pFuncArray[i] = NULL;
	}

	for (i = 0; i < MaxArray; i++)
	{
		cout << "enter value1: ";	cin >> val1;	cout << endl;
		cout << "enter value2: ";	cin >> val2;	cout << endl;
		cout << "Press (2) for Square or (3) Cube: ";	cin >> choice; cout << endl;
		switch (choice)
		{
		case 2: pFuncArray[i] = Square; pFuncArray[i](val1, val2); break;
		case 3: pFuncArray[i] = Cube; pFuncArray[i](val1, val2); break;
		default: cout << "nothing to calculate\n"; break;
		}
	}

//	#6:	PASSING A FUNCTION POINTER TO A FUNCTION
	cout << "#6: PASSING A FUNCTION POINTER TO A FUNCTION:\n";
	cout << "enter value1: ";	cin >> val1;	cout << endl;
	cout << "enter value2: ";	cin >> val2;	cout << endl;
	//Remember that the name of the function returns the pointer to a function (the address of the first byte of the function)
	PrintValues (Square, val1, val2);

//	#7:	Using TYPEDEF with function pointers:
	cout << "#7: Using TYPEDEF with function pointers:\n";
	FUNCTION_POINTER pFuncUsingTypedef;
	pFuncUsingTypedef = Cube;
	cout << "enter value1: ";	cin >> val1;	cout << endl;
	cout << "enter value2: ";	cin >> val2;	cout << endl;
	//Remember that the name of the function returns the pointer to a function (the address of the first byte of the function)
	PrintValues(pFuncUsingTypedef, val1, val2);

//	#8:	POINTERS TO MEMEBER FUNCTIONS:
	cout << "#8: POINTERS TO MEMEBER FUNCTIONS:\n";
	int (Cat1::*pMemberFunc)() = NULL;
	int (*pMemberFunc2)(void) = NULL;
	Cat1 *ptr = new Cat1(5);
	pMemberFunc = &Cat1::GetAge;
	cout << "The cat's age is: " << (ptr->*pMemberFunc)() << "\n";
	//pMemberFunc2 = (*ptr).GetAge;// GetHowManyCats;
	//cout << "The cat's age is: " << (*pMemberFunc2)() << "\n";

	system("pause");
	return 0;
}