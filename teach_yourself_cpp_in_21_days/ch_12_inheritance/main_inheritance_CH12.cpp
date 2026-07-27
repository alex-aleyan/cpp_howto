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

