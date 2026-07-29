#include <iostream>
#include "classes.h"

using namespace std;



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
