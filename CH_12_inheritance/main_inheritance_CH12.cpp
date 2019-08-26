// INHERITANCE:
//	1. A Class that adds new functionality to an existing class is said to be DERIVED from that original class whereis the original
//		class is said to be the BASE CLASS of the DERIVED CLASS.
//	2. STUBBING-OUT a function means you'll write only enough to show that the function was called; good practice for debugging/learning.
//	3. DERIVATION SYNTAX:
//		class derivedClass : accessType baseClass
//		ex:	class Dog : publcic Mammal
//	4. THE BASE CLASS must be declared earlier before a new class derived: A class cannot be derived from a "yet to be declared" class.
//	5. When a NEW class is derived from a BASE Class, the DERIVED Class does not inheret the CONSTRUCTOR and DESTRUCTOR of the BASE Class. However,
//		the CONSTRUCTOR and DESTRUCTOR of the BASE Class are still called when the DERIVED Class is used to create an Object.
//	6. ACCESS TYPES:
//		1) PUBLIC - Can be accessed within the class, within derived classes, and by other objects.
//		2) PROTECTED - Can be acces within the class, within derived classes, but NOT by other objects.
//		3) PRIVATE - Can be accessed within their own class only!
//	7. INHERITANCE, CONSTRUCTORS and DESTRUCTORS: 
//		1)When an Object of a DERIVED Class is created next occurs:
//			a) The BASE CONSTRUCTOR is called first.
//			b) The DERIVED CONSTRUCTOR is called secondly.
//		2)When the object of the DERIVED Class is deleted, next occurs:
//			c) The DESTRUCTOR of the DERIVED Class is called first.
//			d) The DESTRUCTOR of the BASE Class is called secondly.
//	8. OVERRIDING a BASE CLASS FUNCTION with a function contained in the DERIVED CLASS required declaring a function in the DERIVED Class with the same RETURN TYPE and SIGNATURE(function name and parameters);
//		In other word, the return type, the name of the function and the parameter list must be one to one!
//	9. When overriding a method, all the overloaded versions of the original method in the BASE CLASS hide as well. Meaning, if you override a method that takes no parameters, and this method
//		in the base class was overloaded with its versions that take parameters, these overloaded versions are now unaccessible and you must write you own implementation of overloaded versions
//		for your derived class. See pg 388.
//	10. EXTENDING FUNCTIONALITY OF AN INHERITED METHOD: 
//		If a method in the BASE Class was overriden and yet you'd like to use that method within one of the derived methods or perhaps a construct, you can call the BASE method by
//		specifying the BASE class as the source using BaseClass::method() as shown:
//		DerivedClass::advancedBark()
//		{
//			BaseClass::simpleBark(); // where simple bark is just "woof-woof"  
//			std::cout << ", Woooooooooooooooooooooooooof!!! \n"; // so now it's "woof-woof, woooooooooooooooooooooof!!!"
//		}
//	11 BASE Class initialization can be performed within the CONTRUCTOR of the DERIVED Class by calling the CONSTRUCTOR of the BASE Class in the INITIALIZATION STAGE of the CONSTRUCTOR as follows:
//		DerivedClass(int x) : 
//		BaseClass(x), // Here we go, we call the BASE Class constructor and provide it with a value to initialize it with 
//		itsValue(x+1) // this is just a piece of data belonging to the Derived class being initialized to x + 1.
//		{ std::cout << "hey there \n";}
//	12. VIRTUAL METHODS: C++ extends its polymorphism to allow pointers of base class type to be assigned to an object of the derived class type.
//		Using the keyword "virtual" in front of the method declared in the BASE class, we let the compiler know that this method is to be overriden by a method with the same name if contained
//		in the DERIVED Class! Example:
//		Class Mammal // BASE Class
//		{
//			-//- Constructors and Destructor come here...
//			virtual void Speak() const {std::cout << "Mammal speak";}
//		}

//		Class Dog : public Mammal // DERIVED Class : BASE Class
//		{
//			-//- Constructors and Destructor come here...
//			virtual void Speak() const {std::cout << "woof-woof";} // the keyword "virtual" here is optional...
//		}	
//	13. VIRTUAL DESTRUCTORS: As a rule of thumb you MUST USE VIRTUAL DESTRUCTORS WHEN AT LEAST ONE METHOD IS VIRTUAL!!!
//		For example, if we remove keyword virtual from the DESTRUCTORS in each class below, deallocating the object the pMammal pointer points to will result
//		in removal of the Mammal part of the object and the memory leak will occur since the Dog and BentleyBear parts will not be deallocated!!! Next output
//		occurs when destructors are not declared as virtual as they are supposed to be declared as:

//		output when not using virtual destructor:

//			.Woooooooooooooooooooooooof!!!Wauw - wauw - wauw - wauw.
//			Mammal Destructor.
//			BentleyBear Destructor.
//			Dog Destructor.
//			Mammal Destructor.
//			Dog Destructor.
//			Mammal Destructor.

//		output when using virtual destructor:

//			.Woooooooooooooooooooooooof!!!Wauw - wauw - wauw - wauw.
//			BentleyBear Destructor.
//			Dog Destructor.
//			Mammal Destructor.
//			BentleyBear Destructor.
//			Dog Destructor.
//			Mammal Destructor.
//			Dog Destructor.
//			Mammal Destructor.

//	14. VIRTUAL COPY CONSTRUCTOR: While there is NO SUCH THING AS VIRTUAL COPY DESTRUCTOR, we can add a virtual method to a class whose implementation will create
//		a copy of a DERIVED Class Object with its values initialize to those of the Object thus  creating a copy of this Object.

#include <iostream>
using namespace std;

enum BREED {GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB, NUISANCE};

class Mammal
{
public:
	// constructor
	//Mammal() :itsAge(2), itsWeight(5) { std::cout << "Mammal Constructor. \n"; }
	Mammal(int age = 2, int weight = 5) :itsAge(age), itsWeight(weight) { std::cout << "Mammal Constructor. \n"; }

		//#13: VIRTUAL COPY CONSTRUCTOR implementation using a COPY CONSTRUCTOR and a VIRTUAL CLONE() METHOD:
		Mammal(const Mammal & rhs) : itsAge(rhs.GetAge()) { std::cout << "Mammal Copy Construct\n" ; }
		virtual Mammal* Clone() { return new Mammal(*this); std::cout << "Mammal Virtrual Copy Construct\n";}

	virtual ~Mammal() { std::cout << "Mammal Destructor. \n"; }

	//accessors
	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }
	int GetWeight()const { return itsWeight; }
	void SetWeight(int weight) { itsWeight = weight; };

	//other methods
	virtual void Speak() const { std::cout << "Mammal makes sound of: Pfff-Pfff"<<"\n"; } //#12: Virtual methods
	void Sleep() const { std::cout << "Mammal makes sound when sleeping: Zzz-Zzz" << "\n"; }

protected:
	int itsAge;
	int itsWeight;
};

class Dog : public Mammal
{
public:
	//Attributes: Constructors
	//Dog() : itsBreed(GOLDEN) { std::cout << "Dog Constructor. \n"; }
	Dog(BREED breed = LAB) : itsBreed(breed) { std::cout << "Dog Constructor. \n"; }

		//#13: VIRTUAL COPY CONSTRUCTOR implementation using a COPY CONSTRUCTOR and a VIRTUAL CLONE() METHOD:
		Dog(const Mammal & rhs) : Mammal(rhs) { std::cout << "Dog Copy Construct\n"; };
		virtual Mammal* Clone() { return new Dog(*this); std::cout << "Dog Virtrual Copy Construct\n"; }

	virtual ~Dog() { std::cout << "Dog Destructor. \n"; }

	//Attributes: Accessors
	BREED GetBreed() const { return itsBreed; }
	void SetBreed(BREED breed) { itsBreed = breed; }

	//Attributes: Other Methods
	void WagTail() { std::cout << "Tail goes: Shuh-shuh-shuh... \n"; }
	void BegForFood() { std::cout << "Gimme some food, human. \n"; }
	virtual void Speak() const { std::cout << "Woof, woof." << "\n"; }//#12: Virtual methods
	
protected:
	//Member Variable:
	BREED itsBreed;
};

class BentleyBear : public Dog
{
public:
	//BentleyBear() : Dog(NUISANCE) { std::cout << "BentleyBear Constructor. \n"; }
	BentleyBear(int age = 5) : Dog(NUISANCE) { this->itsAge = age;  std::cout << "BentleyBear Constructor. \n"; }

		//#13: VIRTUAL COPY CONSTRUCTOR implementation using a COPY CONSTRUCTOR and a VIRTUAL CLONE() METHOD:
		BentleyBear(const Mammal & rhs) : Dog(rhs) { std::cout << "BentleyBear Copy Construct\n"; };
		virtual Mammal* Clone() { return new BentleyBear(*this); std::cout << "BentleyBear Virtrual Copy Construct\n"; }

	virtual ~BentleyBear() { std::cout << "BentleyBear Destructor. \n"; }
	
	//Attributes: Other Methods
	virtual void Speak() const //#12: Virtual methods
	{ 
		Dog::Speak(); // #10: See, we provide an enriched version of the Speak since Bentley is extra annoying in his barking!!!
		std::cout << ". Woooooooooooooooooooooooof!!! Wauw-wauw-wauw-wauw." << "\n"; 
	}

	virtual void begForIceCube() const //#12: Virtual methods
	{
		std::cout << "Gimme an ice cube, you, sucker!" << "\n";
	}

};


int main()
{
	char x = 0;
	
	//Create the Dog Object to see the Mammal Constructor come first and Dog Destructor come secondly
	Dog *Fido = new Dog;
	Fido->Speak();
	Fido->WagTail();
	std::cout << "Fido is " << Fido->GetAge() << " years old \n" << endl;
	std::cout << "Fido is " << Fido->GetWeight() << " kgs \n" << endl;
	std::cout << "Fido is " << Fido->GetBreed() << " <- remember enum returns an integer corresponding to the enum value.\n" << endl;

	BentleyBear *Benny = new BentleyBear;
	Benny->Speak();
	Benny->WagTail();
	std::cout << "Benny is " << Benny->GetAge() << " years old \n" << endl;
	std::cout << "Benny is " << Benny->GetWeight() << " kgs \n" << endl;
	std::cout << "Benny is " << Benny->GetBreed() << " <- remember enum returns an integer corresponding to the enum value.\n" << endl;
	
	Mammal *pMammal_1 = new BentleyBear;// #12: Virtual methods
	pMammal_1->Speak();
	// So, how do I access the methods that exist only in the derived class using the pointer to the base class as shown below which doesn't work?
	//BentleyBear *pBentleyBear = NULL;	// #12: Virtual methods 
	//pBentleyBear = (BentleyBear) pMammal;
	//pBentleyBear->begForIceCube();

	//#13
	Mammal *pMammal_vir_cpy = (*pMammal_1).Clone();
	pMammal_vir_cpy->Speak();


	//Delete the Dog Object to see the Dog Destructor come first and Mammal Destructor come secondly
	delete pMammal_vir_cpy;
	delete pMammal_1;
	delete Benny;
	delete Fido;

	std::cin >> x;
	return 0;
}

