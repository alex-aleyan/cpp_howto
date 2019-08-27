#include <iostream>
using namespace std;

enum HorseType {HORSE, PEGASUS};
enum ColorType {RED, GREEN, BLUE};

class Horse
{
public:
	Horse() { itsAge = 5;}
	void Gallop() { std:cout << "Galloping... \n"; }
	//#1: This is undesired PERLOCATION of the Fly() function:
	virtual void Fly() { cout << "Horses can't fly!\n"; } // Unless a class derived from this Horse class provides its own Fly() function, the object will not be able to fly.
protected:
	int itsAge;
};

class Pegasus : public Horse
{
public:
	Pegasus() { itsAge = 5;}
	virtual void Fly() { cout << "I can fly!\n"; } // this method will replace the base Fly() method; keyword virtual is optional and is good for clarity.
};


//#2 CASTING DOWN:
class Horse1
{
public:
	Horse1() { itsAge = 5; itsType = HORSE; }
	void Gallop() { std:cout << "Galloping... \n"; }
	virtual HorseType HorseIsType() { return itsType; }
protected:
	int itsAge;
	HorseType itsType;
};

class Pegasus1 : public Horse1
{
public:
	Pegasus1() { itsAge = 5; itsType = PEGASUS; }
	virtual void Fly() { cout << "Pegasus1 can fly!\n"; } // this method will replace the base Fly() method; keyword virtual is optional and is good for clarity.
};


//#3 Multiple Inheritance:
class Horse3
{
public:
	Horse3() { cout << "Horse3 Constructor\n"; itsAge = 5; itsWeight = 200; }
	Horse3(int age, int weight) { cout << "Horse3 Constructor\n"; itsAge = age; itsWeight = weight; }
	virtual ~Horse3() { cout << "Horse3 Destructor\n"; }
	virtual void Whinny() const { std:cout << "Horse3 Whinny \n"; }
	virtual int getWeight() { return itsWeight; }
	virtual int getAge() { return itsAge; }

protected:
	int itsWeight;
	int itsAge;
};

class Bird3
{
public:
	Bird3() { cout << "Bird3 Constructor\n"; itsWeight = 1; itsAge = 5; }
	Bird3(int weight, int age) { cout << "Bird3 Constructor\n"; itsAge = age; itsWeight = weight; }
	virtual ~Bird3() { cout << "Bird3 Destructor\n"; }
	virtual void Chirp() const{ std:cout << "Bird3 Chirp \n"; }
	virtual void Fly() const { cout << "Bird3 flies\n"; }
	virtual int getWeight() { return itsWeight; }
	virtual int getAge() { return itsAge; }
protected:
	int itsWeight;
	int itsAge;
};

//It should be noted that the Horse3 has only the Age data and the Bird3 has only the weight data. This is a problem.
class Pegasus3 : public Horse3, public Bird3
{
public:
	Pegasus3(int age = 46, int weight = 300) :
		Horse3(age, weight)
		//Bird3(weight)
	{
		cout << "Pegasus3 constructor \n";
	}
	~Pegasus3() { cout << "Pegasus3 Destructor \n"; }
	//	Due to ambiguity (both Horse and Bird have itsWeight and itsAge) we must specify which class is used!
	//	It should also be noted that if a new class is inserted between the Pegasus3 class and Horse3 class (NewClass inherets Horse3 class now), 
	//	the Horse3::itsWeight will result in an problem; you must change Horse::itsAge to NewClass::itsAge
	virtual int getWeight() { return Horse3::itsWeight; }
	virtual int getAge() { return Horse3::itsAge; }
	virtual void Fly() const { cout << "Pegasus3, not Bird3:"; Bird3::Fly(); }
	virtual void Chirp() const { Whinny(); }	// THIS IS AN INGENIOUS TRICK TO REPLACE CHIRP() METHOD WITH WHINNY() METHOD!!!
												// NOTICE the signature including the keyword CONST must match!
};


//#4 Virtual Inheritance:
class Animal4
{
public:
	Animal4(int age = 1, int weight = 1) { cout << "Animal4 Constructor\n"; itsAge = age; itsWeight = weight; };
	virtual ~Animal4() { cout << "Animal4 Destructor\n"; }
	
	virtual int getWeight() { return itsWeight; }
	virtual int getAge() { return itsAge; }

protected:
	int itsWeight;
	int itsAge;
};

class Horse4 : virtual public Animal4 // SO THE SHARED BASE CLASS HAS TO HAVE VIRTUAL KEYWORD!!!
{
public:
	Horse4(int age = 5, int weight = 200, ColorType color = GREEN):
	Animal4(age, weight)
	{ 
		cout << "Horse4 Constructor\n"; 
		itsColor = color;
	}
	virtual ~Horse4() { cout << "Horse4 Destructor\n"; }
	
	virtual void Whinny() const { std:cout << "Horse4 Whinny \n"; }
	virtual void getColor() const { std:cout << "Horse4's color is " << itsColor; }

protected:
	ColorType itsColor;

};

class Bird4 : virtual Animal4 // SO THE SHARED BASE CLASS HAS TO HAVE VIRTUAL KEYWORD!!!
{
public:
	Bird4(int age = 5, int weight = 200, ColorType color = GREEN) :
	Animal4(age, weight)
	{ 
		cout << "Bird4 Constructor\n"; 
		itsColor = color;
	}
	virtual ~Bird4() { cout << "Bird4 Destructor\n"; }
	
	virtual void Chirp() const { std:cout << "Bird4 Chirp \n"; }
	virtual void Fly() const { cout << "Bird4 flies\n"; }
	virtual void getColor() const { std:cout << "Bird4's color is " << itsColor; }
protected:
	ColorType itsColor;
};

//It should be noted that the Horse3 has only the Age data and the Bird3 has only the weight data. This is a problem.
class Pegasus4 : public Horse4, public Bird4
{
public:
	Pegasus4(int age = 74, int weight = 300, ColorType color = GREEN):
	Horse4(age, weight, color),
	Bird4(age, weight, color),
	Animal4(age,weight)
	{ 
		cout << "Pegasus4 constructor \n"; 
	}
	~Pegasus4() { cout << "Pegasus4 Destructor \n"; }
	virtual void Fly() const { cout << "Pegasus4, not Bird4:"; Bird4::Fly();  }
	virtual void Chirp() const { Whinny(); }	// THIS IS AN INGENIOUS TRICK TO REPLACE CHIRP() METHOD WITH WHINNY() METHOD!!!
												// NOTICE the signature including the keyword CONST must match!

	//#4.1:
	virtual ColorType getColor() { std:cout << "Horse4's color is " << Horse4::itsColor; return Horse4::itsColor; } //Since itsColor exists in both Horse4 and Bird4!!!
	virtual void setColor(ColorType color) { Horse4::itsColor = color; } //Since itsColor exists in both Horse4 and Bird4!!!
};



//#5:
class Shape5
{
public:
	Shape5() {}
	virtual ~Shape5() {}
	virtual long GetArea() = 0;
	virtual long GetPerim() = 0;
	virtual void Draw() = 0;
private:
};

void Shape5::Draw()
{
	cout << "Abstract drawing mechanism!\n";
}

class Circle5 : public Shape5
{
public:
	Circle5(int radius = 5) : itsRadius(radius) {}
	virtual ~Circle5() {}
	virtual long GetArea() { return 3.14 * itsRadius * itsRadius; }
	virtual long GetPerim() { return 2 * 3.14 * itsRadius; }
	virtual void Draw();
private:
	int itsRadius;
	int itsCircumference;
};

void Circle5::Draw()
{
	cout << "Circle drawing routine here!\n";
	Shape5::Draw(); // HERE WE ARE CHAINING UP TO THE METHOD INHERETED FROM THE ABSTRACT BASE CLASS!!!
}



const int NumberHorses = 3;


int main()
{
	Horse *Ranch[NumberHorses]; // an array of pointers!
	Horse *pHorse = NULL;

	Horse1 *Ranch1[NumberHorses];
	Horse1 *pHorse1 = NULL;
	Pegasus1 * pPegasus1 = NULL;

	Horse3 *Ranch3[NumberHorses];
	Bird3 *Aviary3[NumberHorses];
	Horse3 *pHorse3 = NULL;
	Bird3 *pBird3 = NULL;
	Pegasus3 *pPegasus3 = NULL;


	int choice, i, x;

	for (i = 0; i < NumberHorses; i++)
	{
		cout << "(1) Horse (2) Pegasus: ";
		cin >> choice;
		if (choice == 2)
		{
			pHorse = new Pegasus;	//	Notice, the pointer of base type Horse and the Object is of derived type Pegasus!!! 
									//	We are using the base type pointer to point to the derived type Object.
			
			//#2: This pointer will be used to explore Casting Down:
			pHorse1 = new Pegasus1;

			pHorse3 = new Pegasus3;
		}
		else
		{
			pHorse = new Horse;
			
			//#2: This pointer will be used to explore Casting Down:
			pHorse1 = new Horse1;

			pHorse3 = new Horse3;
		}
			Ranch[i] = pHorse;
			//#2: This pointer will be used to explore Casting Down:
			Ranch1[i] = pHorse1;

			Ranch3[i] = pHorse3;
	}
	cout << endl;
	for (i = 0; i < NumberHorses; i++)
	{
		Ranch[i]->Fly();
		delete Ranch[i];	// Don't forget to free the memory. Also, if it was a pointer to an array, we would use delete [] Ranch; 
							// but in our case it's an array of pointers!

		if (Ranch1[i]->HorseIsType() == PEGASUS)
		{
			//#2: This pointer will be used to explore Casting Down:
			pPegasus1 = (Pegasus1 *) Ranch1[i] ; // NOTICE how we are casting down the Ranch1[i] pointer to be Pegasus1 type pointer!
			//#2: This pointer will be used to explore Casting Down:
			Ranch1[i] = NULL;
			pPegasus1->Fly();
			delete pPegasus1;
		}
		else
		{
			cout << "Horses1 can't fly\n";
			//#2: This pointer was used to explore Casting Down:
			delete Ranch1[i];
			Ranch1[i] = NULL;
		}

		Ranch3[i]->Whinny();
		pPegasus3 = (Pegasus3 *) Ranch3[i];
		cout << "(*pPegasus3).getAge(): " << (*pPegasus3).getAge() << "\n"; // is 5 for Horse and is 6 for Pegasus!!!

		//can be used as long as the object is type Pegasus since Pegasus inherets both the weight from the Bird3 classand the itsage from the Horse3 class.
		//cout << "(*pPegasus3).getWeight(): " << (*pPegasus3).getWeight(); 
							
		pPegasus3 = NULL;
		delete Ranch3[i];

	}



	Pegasus4 *pPegasus4 = new Pegasus4();
	int age = pPegasus4->getAge();
	cout << "This is Pegasus4's age: " << age << "\n";

	ColorType colorways = pPegasus4->getColor();
	cout << "This is Pegasus4's color: " << colorways << "\n";
	delete pPegasus4;


	Shape5 *pShape = 0;
	Circle5 *pCircle = 0;
	pShape = new Circle5(10);
	pShape->Draw();
	pCircle = (Circle5 *) pShape; // Just as before, we have to cast the pointer.
	cout << "pCircle->GetArea(): " << pCircle->GetArea();

	cout << "\ntype to end: ";
	cin >> x;
	return 0;
}
