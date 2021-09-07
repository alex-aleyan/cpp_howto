#include <iostream>

class Cat
{
public:
	Cat() { itsAge = 1; itsWeight = 5;}
	~Cat(){}
	int GetAge() const { return itsAge; }
	int GetWeight() const { return itsWeight; }
	void SetAge(int age) { itsAge = age; }
	void SetWeight(int weight) { itsWeight = weight; }
private:
	int itsAge;
	int itsWeight;
};

/*
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

bool GetWord(char * theString, char *word, int & wordOffset)
{
	if (theString[wordOffset] == 0) // end of string
		return false;
	char *p1, *p2;
	p1 = p2 = theString + wordOffset;

	for (int i = 0; i < (int)strlen(p1) && !isalnum(p1[0]); i++)
		p1++;

	if (!isalnum(p1[0]))
		return false;
	p2 = p1;

	while (isalnum(p2[0]))
		p2++;
	int len = int(p2 - p1);

	strncpy(word, p1, len);

	word[len] = '\0';

	for (int j = int(p2 - theString); j < (int)strlen(theString) && !isalnum(p2[0]); j++)
	{
		p2++;
	}

	wordOffset - int(p2 - theString);
	return true;
}
*/

int main()
{
	int x = 0;
	//Remember WeekDays is not a type that can take on the next values:
	//				0	 1	  2	   3	4	 5	  6		  7
	enum WeekDays {Sun, Mon, Tue, Wed, Thu, Fri, Sat, DaysInWeek};
	int ArrayWeek[DaysInWeek] = {0,0,0,0,0,0,0};
	std::cout << "The value at Tuesday is: " << ArrayWeek[Tue] << "\n";

	int multiArray[3][2] = { {1,2} , {3,4} , {5,6} };
	int *pmultiArray = &multiArray[0][0];
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			std::cout << "theMultiArray[" << i << "][" << j << "] = ";
			std::cout << multiArray[i][j] << "\n";
			std::cout << "Using *pmultiArray [" << i << "][" << j << "] = ";
			std::cout << multiArray[i][j] << "\n";
			pmultiArray++;
		}
	}

// ARRAY OF POINTERS:
	Cat * Family[5]; // An array of pointers
	int i;
	Cat *pCat;
	
	for (i = 0; i < 5;i++)
	{
		pCat = new Cat;				//Allocating memory
		(*pCat).SetAge(2 * i + 1);	//Setting the age for the just created object
		Family[i] = pCat;			//Setting one of the array pointers to point to the newly allocated object
	}

	for (i = 0; i < 5; i++)
	{
		std::cout << "Cat #" << i << ":" << (*Family[i]).GetAge() << "\n";
	}

// POINTER ARITHMETICS
/*	const int bufferSize = 255;
	char buffer[bufferSize + 1];
	char word[bufferSize + 1];
	int wordOffset = 0;

	std::cout << "Enter a string: ";
	std::cin.getline(buffer, bufferSize);

	while (GetWord(buffer, word, wordOffset))
	{
		std::cout << "Got this word: " << word << "\n";
	}
*/

// #7:	RESIZING AN DYNAMICALLY ALLOCATED ARRAY DURING RUN TIME. See code below:
	int AllocationSize = 3;
	int *pArrayOfNumbers = new int[AllocationSize];
	int ElementsUsedSoFar = 0;
	int MaximumElementsAllowed = AllocationSize;
	int InputNumber = -1;

	std::cout << "\n" << "First number = ";
	std::cin >> InputNumber;

	std::cout << "&pArrayOfNumbers: " << &pArrayOfNumbers;

	while (InputNumber > 0)
	{
		pArrayOfNumbers[ElementsUsedSoFar++] = InputNumber;
		std::cout << "\npArrayOfNumbers["<< ElementsUsedSoFar - 1 <<"]: "<< pArrayOfNumbers[ElementsUsedSoFar - 1];
		//std::cout << "\npArrayOfNumbers[1]: " << pArrayOfNumbers[1];
		//std::cout << "pArrayOfNumbers[0]: " << pArrayOfNumbers[0];
		
		if (ElementsUsedSoFar == MaximumElementsAllowed) {
			std::cout << "\nExpanding the array size \n";
			int *pLargerArray = new int[MaximumElementsAllowed + AllocationSize];

			for (int CopyIndex = 0; CopyIndex < MaximumElementsAllowed; CopyIndex++)
			{
				pLargerArray[CopyIndex] = pArrayOfNumbers[CopyIndex];
			}
			delete[] pArrayOfNumbers;
			pArrayOfNumbers = pLargerArray;
			MaximumElementsAllowed += AllocationSize;

		}
		std::cout << "\n" << "Provide a negative value to finish, else Next number = ";
		std::cin >> InputNumber;
	}

	for (int Index = 0; Index < ElementsUsedSoFar; Index++)
	{
		std::cout << pArrayOfNumbers[Index] << "\n";
	}

	delete[] pArrayOfNumbers;
// #7 over.

// #8 Filling an array: The problem with this method is that once the white space is incountered in the inputted message, cin thinks its end of message and
//						stops writing into the buffer
	char buffer[80];
/*	std::cout << "Enter the string: ";
	std::cin >> buffer;
	std::cout << "Here is the buffer: " << buffer << std::endl;
*/	//this can be corrected using cin.get(&buffer, bufferSize):
	std::cout << "Enter the string again: ";
	std::cin.get(&buffer[0], 79);
	std::cout << "Here is the buffer: " << buffer << std::endl;

	std::cin >> x;
	return 0;
}
