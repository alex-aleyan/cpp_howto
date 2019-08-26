//	TEMPLATES also known as PARAMETERIZED TYPES:
//	Allows you to crate a class whose objects can vary in type from definition to definition of the class thus allowing the user to specify the type!

//	1.	STL - Standard Template Library; provides a standardized set of Container Classes.
//	2.	Instantiation - creating a specific type from a template. Thus, individual classes created from a template are called "Instances of The Template"!
//	3.	Building a Template Definition: Two ways to declare a template:

//			1)	template <class TypeParameter>		// Preferred when creating new class types
//				class className
//				{
//					//class definition goes here
//				}
//			2)	template <typename TypeParameter>	// Notice, using keyword "typename" preferred when creating new non-class types
//				class className
//				{
//					//class definition goes here
//				}

//			where:
//				keyword "template" is used to let the compiler know that a template is being declared.
//				keywords "class" and "typename" can be used interchangably and indicate that the parameter passed is a type.
//				TypeParameter is the user defined name for a parameter to be passed to be used by the further declared class.

//			Example:
//				template <class T>
//				class Array
//				{
//					public:
//						Array(int itsSize = 5);
//					private:
//						T *pObject;
//						int itsSize;
//				};

//	4.	Instantiating an object using parameterized class (template), next syntax is used: className<specifiedType> instance;
//			Example:
//				Array<int> anIntArray;
//				Array<Animal> anAnimalArray;

//	5.	BEWARE:	1.	Before using a template, it's a good idea to get the class and its method implemented and tested, and only then use the class to turn it into a template!
//				2.	Template's function definition must be contained in the same file as the template declaration! They cannot be split between an .h and .c files.
//				3.	Remember to implement copy constructor, operator=, operator[], operator+, operator++ and so on for your template class!

//	6.	Functions that accept Instantiated Template Objects, next syntax is used: returnType Func(className<specifiedType> &);
//			Example:
//				void myFunction(Array<int> &); //	remmeber that Array is a type since it's a "templated" class, "int" specifies the template parameter, and "&" says it's a 
//													reference to an object of type Array<int>.
//			BEWARRRRRE:
//				void myFunction(Array<T> &); // <-- is INVALID!!! it cannot accept an object of unspecified type. Only TEMPLATE functions can do it!!!!
//				void myFunction(Array &);	//	is also wrong because Array is a "templated" class, and not just a class

//	7.	Template Function: a function that can accept an argument of type yet to be specified. Next syntax is used:
//			Example:
//				template <class T>
//				void MyTemplateFuntion(Array<T> &);

//			Template functions can also take instances of the template: // well. regular functions can do it too (see #6) so nothing exciting here
//				template <class T>
//				void MyTemplateFuntion(Array<T> &, Array<int>&);

//	8.	TEMPALTES AND FRIENDS:

//		1)	Non-Template Friend Classes and Functions:	friend returnType funcName(className<specifiedType>);
//			Example:
//				friend void Intruder(Array<int> parameterName);	// Remember: Array<int> is a type of a parameter to be passed!

//		2)	General Template Friend Class or Function. Next syntax is used: 
//			template <class T>
//			friend returnType funcName(Array<T>& )

//		3)	Type-specific template friend class of function
//			Example:
//				void myFunction(Array<int> &)

//	9.	Specialized Functions - SUPER IMPORTANT (customizing template behavior by overriding template functions by type) the functions specialized to a specific type of the template! 
//		See Listing 19.6 for more details. In particular, pay attention to listing's lines:
//			-	line 75 - 82 has inefficient implementation that works for all types
//				-	line 84 - 95 has operator= defined used by the inefficient implementation
//			-	line 116 - 120 has SPECIALIZED IMPLEMENTATION for type Animal!!!
//				-	line 39 - 43 has the construct implemented by SPECIALIZED IMPLEMENTATION ABOVE!!!

//	10.	Static members and Templates: A tempolate can have a static data member! Each class created using the template will have its own unique static data member. Thus, you have one static member per
//		type! It should be noted that this static members can be added together to see how members were created totally per template!
//		ATTENTION: When accessing the static data member of a template, you MUST use the SPECIFIC TYPE of the object the static data member you looking for!!!

//	11.	STL (Standard Template Library): Alteration to re-inventing a wheel!!!
//			-	a library of template-based CONTAINER classes (or just CONTAINERS) like VECTORS, lists, QUEUES AND STACKS.
//			-	also includes a number of common algorithms like SORTING and SEARCHING.
//			-	A CONTAINTER is an object that holds other objects (aggregations?); there are 2 types of STL container classes:
//				1)	SEQUENCE Containers: provide sequential and random access to members, or elements:
//						The STD Library provides five sequence containers:
//							i.		VECTORs: 
//										Behaves like an ARRAY Class.
//										Optimized to provide fast access to its element by an index.
//										Automatically increases its capacity.
//										Make sure to provide the default constructor for the class of the object (where the object is to be stored in the VECTOR array)
//										Next syntax is used to define a vector of a particular class:
//											vector<Type> vectorName;
//											Ex: vector<int> vInts; vector<student> mathClass(50);
//										To access a method of an object contained in the vector, use this syntax:
//											vectorName[indexInteger].funcName();
//											Ex: mathClass[5].GetAge();
//										To use the methods of the VECTOR class, use this syntax:
//											vectorName.methodName(parameter);
//											Ex:	mathClass.push_back(objectName); // here, copy construc of the student class has to be defined
//										Remember to: define default constructor, copy constructor and overloaded assignment operator for such class!
//										Some Member Functions:
//											capacity()
//											front()		- returns a reference to the first element in a list
//											back()		- returns a reference to the last element in a list
//											at()		- works like a subscription operator [] but safer but checks whether the subscript is within the range!
//											insert()	- inserts 1 or more nodes into a given position in a vector (array).
//											pop_back()	- removes the last element from a vector.
//											push_back()
//											max_size()
//							ii.		LIST: 
//										Optimal when elements have to be deleted or inserted frequently and is implemented as a doubly-linked list!
//										Has all the methods the vector class has!
//										To iterate through the list, uses the mechanism called ITERATOR (can be dereferences) which is similar to a pointer but avoids dangers of the pointer!
//										end()	- ATTENTION, it returns the address of the "past the last elemet" element ( &lastElement + 1)
//							iii.	STACK (LIFO)
//										Implemented as a wrapper of a container
//										Can GROW or SHRINK at the END of the stack ONLY!!!
//										Objects must be of the SAME TYPE!!!
//							iv.		DEQUE: Double-Ended Vector
//										Has sequencial reads and writes of the vector class
//										Has optimized front and back end operations
//										Ideal for applications with memory allocations at both ends
//							v.		QUEUE (FIFO)
//										Also implemented as a wrapper
//										front()
//										back()
//										push_back()
//										pop_front()
//				2)	ASSOCIATIVE Containers: optimized to access their elements by key values.
//							i.		MAP:
//										No 2 objects can have the same key
//										Each node has two iterator which are first and second. First points to the key and second points to the Object! See ShowMap for details!
//							ii.		MULTIMAP:
//										A map class that allows duplicate keys.
//							iii.	SET
//										Similar to map container but instead of having key,value pairs its elements are the keys only.
//							iv.		MULTISET
//										A set container that allows duplciates
//							v.		BITSET
//										a template for storing a sequence of bits.



#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
const int DefaultSize = 10;

class Animal
{
public:
	Animal(int weight = 0);
	//Animal();
	~Animal();
	int GetWeight() const { return itsWeight;}
	void Display() const { std::cout << itsWeight; }
private:
	int itsWeight;
};

Animal::Animal(int weight) :
	itsWeight(weight)
{
	cout << "Constructor: Animal(int weight)" << endl;
}

Animal::~Animal()
{
	cout << "Destructor: ~Animal(int weight)" << endl;
}



template <class T>
class Array
{
public:
	Array(int itsSize = DefaultSize);
	Array(const Array &rhs); // copy construct in case if new object to be instantiated is to be a copy of an other object passed in as rhs.
	~Array() { delete[] pType; }

	Array& operator=(const Array&);
	T& operator[] (int offSet) { return pType[offSet]; }
	const T& operator[] (int offSet) const { return pType[offSet]; }
	int GetSize() const { return itsSize; }

	// #8.1: since it's a friend, it can access private data:
	friend void Intrude(Array<int>);

	//	#8.2:
	template <class T>
	friend ostream& operator<< (ostream&, Array<T>&);

	//	#10:
	static int  GetNumberArrays() { return itsNumberArrays; }

private:
	T *pType;
	int itsSize;
	//	#10:
	static int itsNumberArrays;
};

//	#10:
template <class T>
int Array<T>::itsNumberArrays = 0;

// #8.1:
void Intrude(Array<int> theArray)
{
	std::cout << std::endl << "*** Intrude ***" << std::endl;
	for (int i = 0; i < theArray.itsSize; i++)
		cout << "i: " << theArray.pType[i] << endl;
	cout << endl;
}

// #8.2:
template <class T>
ostream& operator<< (ostream& output, Array<T>& theArray)
{
	for (int i = 0; i < theArray.itsSize; i++)
		output << "[" << i << "]" << theArray[i] << endl;
	return output;
}


// Implementing/Defining Construct
template <class T>
Array<T>::Array(int size = DefaultSize) : 
itsSize(size)
{
	pType = new T[size]; // allocate an array of size "size" and type "T".
//	#9 Initilizing the object when creating:
	for (int i = 0; i < size; i++)
	{
		pType[i] = (T) 0;	// here we create a temporarily object when casting (T) 0; and the values of this temporarily object are then assigned to the newly created object the pType pointer points to.
							// The object created by casting is then released which makes it a very inefficient method of initialization!!!!!!!!!!!!!!!!!!!!!
							//	#10:
	}
	//	#10:
	itsNumberArrays++;
}

//	#9	This specialized contruct makes sure the Animal Array is initialiazed without doing all the extra steps of the implementation above!
Array<Animal>::Array(int AnimalArraySize) :
itsSize(AnimalArraySize)
{
	pType = new Animal[AnimalArraySize];
	//	#10:
	itsNumberArrays++;
}


/*
template <class T>
Array<T>::Array(int size) :
itsSize(size)
{
	pType = new T[size];
	for (int i = 0; i < size; i++)
	{
		pType[i] = (T)0;
	}
	//	#10:
	itsNumberArrays++;
}
*/

template <class T>
Array<T>::Array(const Array &rhs)
{
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for (int i = 0; i < itsSize; i++)
	{
		pType[i] = rhs[i];
	}
	//	#10:
	itsNumberArrays++;
}

template <class T>
Array<T>& Array<T>::operator=(const Array &rhs) // return type: Array<T>&, operator: Array<t>::operator=, argument: const Array &rhs
{
	if (this == &rhs)
		return *this;
	delete[] pType;
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for (int i = 0; i < itsSize; i++)
	{
		pType[i] = rhs[i];
	}
	return *this;
}


// #11 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//11.1.i VECTORs:

class Student
{
public:
	Student(); // Default construct
	Student(const string& name, const int age);
	Student(const Student& rhs); // Copy Construct
	~Student();

	void SetName(const string& name);
	string GetName() const; // can't change private members!

	void SetAge(const int age);
	int GetAge() const;

	Student& operator=(const Student& rhs);

private:
	string itsName;
	int itsAge;
};

//Default Construct
Student::Student() : 
	itsName("New Student"),
	itsAge(16)
{}


Student::Student(const string& name, const int age) :
	itsName(name),
	itsAge(age)
{}

Student::Student(const Student& rhs) :
	itsName(rhs.GetName()), itsAge(rhs.GetAge())
{}

Student::~Student()
{}

void Student::SetName(const string& name)
{
	itsName = name;
}

string Student::GetName() const
{
	return itsName;
}

void Student::SetAge(const int age)
{
	itsAge = age;
}

int Student::GetAge() const
{
	return itsAge;
}

Student& Student::operator=(const Student& rhs)
{
	itsName = rhs.GetName();
	itsAge = rhs.GetAge();
	return *this;
}

ostream& operator<<(ostream& os, const Student& rhs)	
{
	os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
	return os;
}

template<class T> // the function below is to be a template:
void ShowVector(const vector<T>& v);

typedef vector<Student> SchoolClass;

//11.1.ii LIST Container:
typedef list <int> IntegerList;

//11.2.i	MAP Container:

//funct prototype:
#include<map>

// Template Function (type adoptive function!):
template<class T, class A>
void ShowMap(const map<T, A>& vec); // <keyType, objectType>

typedef map<string, Student> MapClass;

int main()
{
	Array<int> theArray; // an array of integers
	Array<Animal> theZoo; // an array of Animals
	Animal *pAnimal;

	for (int i = 0; i < theArray.GetSize(); i++)
	{
		theArray[i] = i * 2;
		pAnimal = new Animal(i * 3);
		theZoo[i] = *pAnimal;
		delete pAnimal;
	}

	for (int j = 0; j < theArray.GetSize(); j++)
	{
		std::cout << "theArray[" << j << "]: \t";
		std::cout << theArray[j] << "\t\t";
		std::cout << "theZoo[" << j << "]:\t";
		theZoo[j].Display();
		std::cout << std::endl;
	}

	// #8.1, now using the friend function:
	cout << " #8.1 using the friend function to find the members of Array<int>";
	Intrude(theArray);

	cout << endl << "DONE 8.1" << endl << endl;
	 
	cout << theArray << endl;

	cout << endl << "DONE 8.2" << endl;

	cout << "itsNumberArrays: " << Array<Animal>::GetNumberArrays() << endl;

// #11, STL:
cout << " #11 STL vector:";

	Student Harry("Harry", 15);
	Student Marry("Marry", 16);
	Student Peter("Pete", 16);
	Student Nikolas("Nick", 16);

	SchoolClass TenthGrade(3);
	cout << "TenthGrade: " << endl; ShowVector(TenthGrade); 
	cout << endl;

	TenthGrade[0] = Harry;
	TenthGrade[1] = Marry;
	TenthGrade[2] = Peter;

	cout << "TenthGrade after adding Harry, Marry and Pete: " << endl; ShowVector(TenthGrade);

	TenthGrade.push_back(Nikolas);
	cout << "TenthGrade after adding Nick: " << endl; ShowVector(TenthGrade);

	TenthGrade[2].SetName("Peter");
	TenthGrade[3].SetName("Nickolas");
	cout << "TenthGrade after Pete wants to be Peter and Nick wants to be Nickolas: " << endl; ShowVector(TenthGrade);

cout << " #11 STL list:" << endl;

	typedef list<int> IntegerList;

	IntegerList intList;

	for (int i = 1; i <= 10; ++i)
		intList.push_back(i * 2);

	for (IntegerList::const_iterator ci = intList.begin(); ci != intList.end(); ++ci) //.end() returns the address of one iteration past the last node!!!
		cout << *ci << " " << endl;

//11.ii LIST Container:
	IntegerList intListii;

	for (int i = 1; i <= 10; ++i)
		intList.push_back(i * 2);

	for (IntegerList::const_iterator ci = intListii.begin(); ci != intListii.end(); ++ci)
		cout << *ci << " ";

	
//11.2.i	MAP Container:
	Student Mike("Mike", 18);
	Student Lisa("Lisa", 15);
	Student George("George", 17);

	MapClass historyClass;
	historyClass[Mike.GetName()] = Mike;
	historyClass[Lisa.GetName()] = Lisa;
	historyClass[George.GetName()] = George;

	cout << "historyClass : " << endl;
	ShowMap(historyClass);
	cout << "We know that " << historyClass["Mike"].GetName() << " is " << historyClass["Mike"].GetAge() << " years old." << endl;

	system("pause");
	return 0;
}

template<class T>
void ShowVector(const vector<T>& vec)
{
	cout << " max_size() = " << vec.max_size();
	cout << "\tsize() = " << vec.size();
	cout << "\tcapacity() =" << vec.capacity();
	cout << "\t" << vec.empty() ? "empty" : "not empty"; // if vec.empty() returns true, then use "empty" as a string to cout, else use "not empty"
	cout << endl;

	for (unsigned int i = 0; i < vec.size(); ++i)
		cout << vec[i] << endl;

	cout << endl;
}

//11.2.i	MAP Container:

template<class T, class A>
void ShowMap(const map<T, A>& vec)
{
	for (map<T, A>::const_iterator ci = vec.begin(); ci != vec.end(); ++ci)
		cout << ci->first << ": " << ci->second << endl;
	cout << endl;
}