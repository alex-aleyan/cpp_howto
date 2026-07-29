#include <iostream>
//#include <string.h>
using namespace std;

class String
{
public:
	// constructors
	String();
	String(const char *const); // a read only pointer that can't change what it points to!
	String(const String &); // copy construct
	~String();

	//overloaded operators
	char & operator[](int offset);
	char operator [](int offset) const; // can't change private data members
	String operator+(const String&);
	void operator+=(const String&);
	String & operator=(const String &);

	int GetLen()const { return itsLen; }
	const char * GetString() const { return itsString; }
	static int ConstructorCount;

//#7:
	friend String operator+(const String&, const String&);

//#8:
	//ostream is a type of stream/buffer?
	friend ostream& operator<<(ostream& theStream, String& theString);

private:
	String(int); // private constructor huh?
	char * itsString;
	unsigned short itsLen;

};

// default constructor creates string of 0 bytes
String::String()
{
	itsString = new char[1];
	itsString[0] = '\0';//Initialize the first and only byte to NULL
	itsLen = 0;
	 cout << "\tDefault string constructor\n";
	 ConstructorCount++;
};

//private (helper) constructor, used only by class method for creating a new string of required size. Null filled.
String::String(int len)
{
	itsString = new char[len + 1];
	for (int i = 0; i <= len; i++)
		itsString[i] = '\0';
	itsLen = len;
	 cout << "\tString(int len) constructor\n";
	 ConstructorCount++;
}

//#7:
//Converts a character array to a string:
String::String(const char * const cString) // where cString points to an array containing characters and is not properly terminated with NULL. Thus we need to add that NULL character
{
	itsLen = (unsigned short) strlen(cString);
	itsString = new char[itsLen + 1];
	for (int i = 0; i < itsLen;i++)
	{
		itsString[i] = cString[i]; // copying the content of the array into the string array
	}
	itsString[itsLen] = '\0'; // Adding the terminating null character
	 cout << "\tString(const char * const cString) constructor\n";
	 ConstructorCount++;
}

//Copy construct: Initializing a new object and prepopulating it with the data of another object
String::String(const String & rhs)
{
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];
	for (int i = 0; i < itsLen; i++)
	{
		itsString[i] = rhs[i];
	}
	itsString[itsLen] = '\0';
	 cout << "\tString(const String & rhs) constructor\n";
	 ConstructorCount++;
}

String::~String()
{
	delete[] itsString;
	itsLen = 0;
	cout << "\tString destructor\n";
}


// non constant offset operator, returns the reference to a character so that particular character can be changed!
char & String::operator[](int offset)
{
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}


//operator equals, frees existing memory then copies string and size
String& String::operator=(const String &rhs)
{
	if (this == &rhs) return *this; // returning a pointer as a reference!
	delete[] itsString; // clean up the old data: deallocate the memory itsString points
	itsLen = rhs.GetLen(); // determing the size require to hold the new string data
	itsString = new char[itsLen + 1]; // allocate the memory of the require size + 1 for the terminating NULL character
	for (int i = 0; i < itsLen; i++)
	{
		itsString[i] = rhs[i]; // copy the new data into newly allocated memory
	}
	itsString[itsLen] = '\0'; // add the terminating NULL character
	return *this;
	 cout << "\tString operator=\n";
}


//on const object (see copy constructor!): NOTICE THE RETURN TYPE IS NOT A REFERENCE AND THE OPERATOR CANNOT CHANGE WHAT IT OPERATES ON DUE TO CONST TYPE!
char String::operator[](int offset) const
{
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}

String String::operator+(const String & rhs)
{
	int totalLen = itsLen + rhs.GetLen(); // set the length of the resulting string as thge sum of two!
	String temp(totalLen);
	int i, j;
	for (i = 0; i < itsLen; i++) // fill up the first half with the original data
	{
		temp[i] = itsString[i];
	}
	for (j = 0; j < rhs.GetLen(); j++, i++) // proceed with filling up the second half with the new data
	{
		temp[i] = rhs[j];
	}
	temp[totalLen] = '\0'; // finish with adding the terminating character at the end
	return temp;
}

void String::operator+=(const String & rhs)//remember that even if the argument is not of const type, it still can be accepted  by a function and will be treated as such!
{
	unsigned short rhsLen = rhs.GetLen();
	unsigned short totalLen = itsLen + rhsLen;
	String temp(totalLen);
	int i, j;
	for (i = 0; i < itsLen; i++)
	{
		temp[i] = itsString[i];
	}
	for (j = 0; j < rhs.GetLen(); j++, i++)
	{
		temp[i] = rhs[i - itsLen];
	}
	temp[totalLen] = '\0';
	*this = temp;
}

//#7 NOTICE, this operator is used with a C-STYLE (type char) string instead of "String type" string. Is it safe to assume that as long as the String Class is provided with a construct that accepts
//	a C-Style string and creates a String type object out of it, we can use this operator on a C-Style string and the compiler will create a String type object out of the C-style string when
//	this operator is used on it!
String operator+(const String& lhs, const String& rhs)
{
	int totalLen = lhs.GetLen() + rhs.GetLen();
	String temp(totalLen);
	int i, j;
	for (i = 0; i < lhs.GetLen(); i++)
	{
		temp[i] = lhs[i];
	}
	for (j = 0, i = lhs.GetLen(); j < rhs.GetLen(); j++, i++)
	{
		temp[i] = rhs[j];
	}
	temp[totalLen] = '\0';
	return temp;
}

ostream& operator<< (ostream& theStream, String& theString)
{
	theStream << theString.itsString;
	return theStream;
}

int String::ConstructorCount = 0;


class Employee
{
public:
	Employee();
	Employee(char *, char *, char *, long);
	~Employee();
	Employee(const Employee&);
	Employee & operator= (const Employee &);

	const String & GetFirstName()const { return itsFirstName; }
	//Because the operator+ sets itsLen to a new value, we can't use GetFirstName with that operator. Thus, lets overlod GetFirstName such that its non const type:
	String & GetFirstName() { return itsFirstName; }
	const String & GetLastName() const { return itsLastName; }
	const String & GetAddress() const { return itsAddress; }
	long GetSalary() const { return itsSalary; }

	void SetFirstName(const String & fName) { itsFirstName = fName; }
	void SetLastName(const String & lName) { itsLastName = lName; }
	void SetAddress(const String & address) { itsAddress = address; }
	void SetSalary(long salary) { itsSalary = salary; }

private:
	String itsFirstName;
	String itsLastName;
	String itsAddress;
	long itsSalary;
};

Employee::Employee() :
	itsFirstName(" "),
	itsLastName(" "),
	itsAddress(" "),
	itsSalary(0) 
{	}

Employee::Employee(char *firstName, char * lastName, char *address, long salary) :
	itsFirstName(firstName),
	itsLastName(lastName),
	itsAddress(address),
	itsSalary(salary)
{	}

Employee::Employee(const Employee & rhs) :
	itsFirstName(rhs.GetFirstName()),
	itsLastName(rhs.GetLastName()),
	itsAddress(rhs.GetAddress()),
	itsSalary(rhs.GetSalary())
{	}

Employee::~Employee() {}

Employee & Employee::operator= (const Employee & rhs)
{
	if (this == &rhs)
		return *this;

	itsFirstName = rhs.GetFirstName();
	itsLastName = rhs.GetLastName();
	itsAddress = rhs.GetAddress();
	itsSalary = rhs.GetSalary();
	return *this;
}


void PrintFunc(Employee Edie)
{
	cout << "Name: ";
	cout << Edie.GetFirstName().GetString();
	cout << " " << Edie.GetLastName().GetString();
	cout << ".\nAddress: ";
	cout << Edie.GetAddress().GetString();
	cout << ".\nSalary: ";
	cout << Edie.GetSalary();
	cout << endl;
}

void rPrintFunc(const Employee& Edie)
{
	cout << "Name: ";
	cout << Edie.GetFirstName().GetString();
	cout << " " << Edie.GetLastName().GetString();
	cout << ".\nAddress: ";
	cout << Edie.GetAddress().GetString();
	cout << ".\nSalary: ";
	cout << Edie.GetSalary();
	cout << endl;
}



class Part
{
public:
	Part() :itsPartNumber(1) {}
	Part(int PartNumber) :
	itsPartNumber(PartNumber) {}
	virtual ~Part() {}
	int GetPartNumber() const { return itsPartNumber; }
	virtual void Display()const = 0; // pure virtual function

private:
	int itsPartNumber;
};


void Part::Display() const // To allow the derived class to chain up to this base class, we need to provide implementation for the pure virtual function!!!
{
	cout << "\nPart Number: " << itsPartNumber << endl;
}

class CarPart : public Part
{
public:
	CarPart() :itsModelYear(94) {}
	CarPart(int year, int partNumber);
	virtual void Display() const
	{
		Part::Display();
		cout << "ModelYear: ";
		cout << itsModelYear << endl;
	}
private:
	int itsModelYear;
};

CarPart::CarPart(int year, int partNumber) :
	itsModelYear(year),
	Part(partNumber) 
{}

class AirPlanePart : public Part
{
public:
	AirPlanePart() :itsEngineNumber(1) {};
	AirPlanePart(int EngineNumber, int PartNumber);
	virtual void Display()const
	{
		Part::Display();
		cout << "Engine No.: " << itsEngineNumber << "\n";
	}

private:
	int itsEngineNumber;
};

AirPlanePart::AirPlanePart(int EngineNumber, int PartNumber) :
	itsEngineNumber(EngineNumber), 
	Part(PartNumber)
{

}

class PartNode
{
public:
	PartNode(Part*);
	~PartNode();
	void SetNext(PartNode * node)
	{
		itsNext = node;
	}
	PartNode * GetNext() const; // Function that returns a poionter to an object of type PartNode
	Part * GetPart()const; // Function that returns a poionter to an object of type Part

private:
	Part *itsPart;
	PartNode *itsNext;
};

PartNode::PartNode(Part* pPart) :
	itsPart(pPart),
	itsNext(0)
{	

}

PartNode::~PartNode()
{
	delete itsPart;
	itsPart = 0;
	delete itsNext;
	itsNext = 0;
}

PartNode * PartNode::GetNext() const
{
	if(itsPart) return itsNext;
	else return NULL; 
}


Part *PartNode::GetPart() const
{
	if (itsPart) return itsPart;
	else return NULL;
}

class PartsList
{
public:
	PartsList();
	~PartsList();
	void Iterate(void(Part::*f)()const) const; // The Iterate function is a constant type function that accepts a pointer to a constant type function that does not return anything...
	Part * Find(int & position, int PartNumber) const;
	Part * GetFirst() const;
	void Insert(Part *);
	Part * operator[](int) const;
	int GetCount() const { return itsCount; }
	static PartsList& GetGlobalPartsList() { return GlobalPartsList; }

private:
	PartNode *pHead;
	int itsCount;
	static PartsList GlobalPartsList;
};

PartsList PartsList::GlobalPartsList;

PartsList::PartsList() :
	pHead(0),
	itsCount(0)
{}

PartsList::~PartsList() { delete pHead; }

Part * PartsList::GetFirst() const
{
	if (pHead) return pHead->GetPart();
	else return NULL; // check this condition when called
}

Part * PartsList::operator[](int offSet)const
{
	PartNode* pNode = pHead;
	if (!pHead) return NULL;
	if (offSet > itsCount) return NULL;
	for (int i = 0; i < offSet; i++) pNode = pNode->GetNext();
	return pNode->GetPart();
}

Part* PartsList::Find(int & position, int PartNumber) const
{
	PartNode * pNode = 0;
	for (pNode = pHead, position = 0; pNode != NULL; pNode = pNode->GetNext(), position++)
	{
		if (pNode->GetPart()->GetPartNumber() == PartNumber) break;
	}
	if (pNode == NULL) return NULL;
	else return pNode->GetPart();
}

void PartsList::Iterate(void (Part::*func)()const) const
{
	if (!pHead) return;
	PartNode* pNode = pHead;
	do
		(pNode->GetPart()->*func)();	//WTF???? OOOOH: pNode->GetPart() returns a pointer to an Object of type Part first, and then we append *func to the returned object
										//and call the corresponding function They should've done next to make it more explicit: 
										//	Part* Object = pNode->GetPart()
										//	Object->func(); //Let's try this!!!
	while ((pNode = pNode->GetNext()) != 0); // Notice: pNode = pNode->GetNext() causes iteration and pNode != 0 checks for the LAST NODE ON THE LIST.
}

void PartsList::Insert(Part* pPart)
{
	PartNode *pNode = new PartNode(pPart); // Allocate memory for the node to be inserted!
	PartNode *pCurrent = pHead;
	PartNode *pNext = 0;

	int New = pPart->GetPartNumber();
	int Next = 0;
	itsCount++;

	if (!pHead) // if pHead == NULL;
	{
		pHead = pNode;
		return;
	}

	if (pHead->GetPart()->GetPartNumber() > New) // sorted by the part number
	{
		pNode->SetNext(pHead);
		pHead = pNode;
		return;
	}

	for (;;)
	{
		if (!pCurrent->GetNext()) //pCurrent->GetNext() == NULL; current node is the last node 
		{
			pCurrent->SetNext(pNode);
			return;
		}

		pNext = pCurrent->GetNext();
		Next = pNext->GetPart()->GetPartNumber();
		if (Next > New)
		{
			pCurrent->SetNext(pNode);
			pNode->SetNext(pNext);
			return;
		}
		pCurrent = pNext;
	}
}

class PartsCatalog
{
public: // Notice, no construc is used, so only the default one is used.
	void Insert(Part *);
	int Exists(int PartNumber);
	Part * Get(int PartNumber);
	//operator+(const PartsCatalog &);
	void ShowAll() { thePartsList.Iterate(&Part::Display); }
private:
	PartsList thePartsList; // aggregation, PartsList DELEGATES its list management to this PartsCatalog Class!!!!!!
};

void PartsCatalog::Insert(Part * newPart)
{
	int partNumber = newPart->GetPartNumber();
	int offset;

	if (!thePartsList.Find(offset, partNumber))
	{
		thePartsList.Insert(newPart);
	}

	else
	{
		cout << partNumber << "was the ";
		switch (offset)
		{
		case 0: cout << "first "; break;
		case 1: cout << "second "; break;
		case 2: cout << "third "; break;
		default: cout << offset + 1 << "th ";
		}
		cout << "entry.Rejected!" << endl;
	}
}

int PartsCatalog::Exists(int PartNumber)
{
	int offset;
	thePartsList.Find(offset, PartNumber);
	return offset;
}

Part * PartsCatalog::Get(int PartNumber)
{
	int offset;
	Part *thePart = thePartsList.Find(offset, PartNumber);
	return thePart;
}







int main()
{
	Employee *Edie = new Employee("jane", "Doe", "1461 Shore Parkway", 20000);
	Edie->SetSalary(50000);
	String LastName("Levine");
	Edie->SetLastName(LastName);
	Edie->SetFirstName("Edythe");
	cout << "Name: ";
	cout << Edie->GetFirstName().GetString(); // <-NOT SURE HOW EXACTLY THIS WORKS!!!!!!!!!!!!!!
	cout << " " << Edie->GetLastName().GetString();
	cout << ".\nSalary: ";
	cout << Edie->GetSalary();
	cout << "\n";
	delete Edie;

//#3:	COPYING BY VALUE: 
	cout << "#3ss	COPYING BY VALUE: ";
	Employee Ediet("jane", "Doe", "1461 Shore Parkway", 20000);
	cout << "Constructor count: " << String::ConstructorCount << endl;
	rPrintFunc(Ediet);
	cout << "Constructor count: " << String::ConstructorCount << endl;
	PrintFunc(Ediet);
	cout << "Constructor count: " << String::ConstructorCount << endl;
	rPrintFunc(Ediet);

//#4:	AGGREGATION/DELEGATION:
	
	PartsCatalog pc;
	Part * pPart = 0;
	int PartNumber;
	int value;
	int choice = 99;

	while (choice != 0)
	{
		cout << "\n(0) Quit, (1) Car, (2) Plane: "; cin >> choice;
		if (choice != 0)
		{
			cout << "\nNew PartNumber?: "; cin >> PartNumber;
			if (choice == 1)
			{
				cout << "\nModel Year?: "; cin >> value;
				pPart = new CarPart(value, PartNumber);
			}
			else
			{
				cout << "\nEngine Number?: "; cin >> value;
				pPart = new AirPlanePart(value, PartNumber);
			}
			pc.Insert(pPart);
		}
	}
	pc.ShowAll();

//#7:
	String s1("Hello ");
	char *c1 = { " world" }; //array
	String s2;
	String s4;

	cout << "s1: " << s1.GetString() << endl;
	cout << "c1: " << c1 << endl;

	s2 = c1 + s1;
	cout << "s2: " << s2.GetString() << endl;

	s2 = s1 + c1;
	cout << "s2: " << s2.GetString() << endl;

	cout << "s3: \n";
	String s3(c1);

	cout << "s4: \n";
	s4 = s1 + s3;
	cout << "s4: " << s4.GetString() << endl;

//#8:
	cout << s1 << "\n";

	system("pause");

	return 0;
}
