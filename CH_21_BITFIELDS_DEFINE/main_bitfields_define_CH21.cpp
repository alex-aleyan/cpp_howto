//	Preprocessor and Compiler:
//		- Preprocessor accepts Source Code and turns it into an Object File to be accepted by Compiler.
//		- Compiler accepts Object File and turns it into an Executable File?
//		- Every compiler has a "switch" which can be used to instruct the compiler to save the intermediate file (Object file?)

//	The '#' character instruct the precompiler that the following line is a preprocessor instruction.

//	#1	#DEFINE:
//		
//		1.	The #define can be used:
//			1) For symbolic constants, example: 

//				#define SIZE 

//			2) For testing:

//				somewhere in your code:
//										#define DEBUG

//				somewhere else in your code you then test if the DEBUG has been defined:	
//										#if defined DEBUG
//											cout << "Debug defined";
//										#else 
//											cout << "Debug not defined";		
//										#endif
//					Alternative short cut to the above method is:
//										#ifdef DEBUG
//											cout << "Debug defined";
//										#else 
//											cout << "Debug not defined";
//										#endif
//				you can also test if it was not defined:
//										#if !defined DEBUG
//											cout << "Debug not defined";
//										#else 
//											cout << "Debug defined";		
//										#endif
//
//					Alternative short cut to the above method is:
//										#ifndef DEBUG
//											cout << "Debug not defined";
//										#else 
//											cout << "Debug defined";
//										#endif

//			3) For Inclusion Guarding (to avoid multiple inclusions of the same object in a single branch of hierarchy):
//					#ifndef ANIMAL_HPP
//					#define ANIMAL_HPP
//						some code that might be included more than once come here. Thus the #ifndef prevents it from being included more than once!
//					#endif

//			4) For MACRO Functions. Next syntax is used:
//					#define MACRO_NAME(argument_1, Argument2) ( (x) > (y) ? (x):(y))
//				- It should be kept in mind that it's a good idea to put the arguments into parenthesis throughout the macro's definition to avoid precedence issues in case the argument passes is an expression! 
//				- Also, since macros are expanded inline each time they are used, they consume a lot more memory then regular functions. Yet, they are quicker.
//			5) For ASSERTiong

//		2.	STRINGIZING Operator (#) puts the quotes around any characters following the operator until the WHITE SPACE is incounted:
//				#define WRITESTRING(x) cout << #x ;	// you can then call it as : WHITESTRING(here is a string); and precompiler will turn it into cout << "here is a string";

//		3.	CONCATENATION Operator (##) bonds more than one terms into a word where the new word is actually a TOKEN and not a string which can be used as a class name, a variable name, an offset into an array,
//			or anywhere else a series of letters might appear:
//			
//			#define FPRINT(x) f ## x ## Print .bits // can be used when you have more than functions for example, fOnePrint, fTwoPrint and so on...
//			
//			or you could declare a class as:

//			#define Listof(Type) class Type##List \ 		// where '\' is the CONTINUE OPERATOR for preprocessor.
//			{ \
//			public: \
//			Type##List(){} \
//			private:
//			int itsLength; \
//			};		

//		4.	Predefined macros: __DATE__, __TIME__, __LINE__, __FILE__ When encountered during compilation (not when the program run), the date is replaced with current date, time with current time, 
//			line with source code line number, and file with the name of the file. 	

//		5.	ASSERT():	
//				i.		returns TRUE if its parameter evaluates to TRUE; and takes ACTION if its parameter evaluates to FALSE
//				ii.		usually works in conjunction with "#ifdef DEBUG" and thus is used during debug only:
//							#ifdef DEBUG
//								#define ASSERT(no_fault) \
//										if(no_fault == FALSE) \
//										{ \
//											cout << "FAULT OCCURED" << endl; \
//										} 
//							#endif

//		6.	INVARIANTS, checkout page 764... not that hard to understand so will not be shown here

//		7.	Printing interim values during debug session: In addition to asserting, you can also print the values during debug session only using #define DEBUG:
//				#define DEBUG

//				#ifdef DEBUG
//					#define PRINT(x)
//				#else
//					#define PRINT(x) cout << #x << x << endl;
//				#endif

//	#2	Bit Twiddling, BIT MASKING:
//			1.	&, is an AND gate, or bitwise AND: often used to CLEAR a bit (to low): (0b0101 & 0b1110) will turn 0b0101 into 0b0100 
//			2.	|, is an OR gate, or bitwise OR: often used to SET a bit (to high): (0b0101 | 0b0010) will turn 0b0101 into 0b0111 thus setting the second bit high
//			3.	^, is an XOR gate, or bitwise XOR: often used to toggle a bit: (0b0101 | 0b0011) will turn 0b0101 into 0b0110 thus toggling last 2 bits 
//			4.	~, is an NOT gate, or bitwise NOT

//	#3	Bit Twiddling, BIT FIELDS: Allow a data of any bit size to be declared (remember, nibble = 4 bits):
//			-	a type of each bitfield must be "unsigned int"
//			-	syntax looks next way:	unsigned int bitName: 1;
//			-	commonly used in structures and classes!

#define DEBUG
#define SW_VERSION 5

#define CUBE(A)		((A)*(A)*(A))
#define BAD_CUBE(A) (A*A*A) 

// #1.3 

#define CycloneV
/*
#define SPEED(FREQ) ((FREQ) ## Hz)
#define FREQ_50 50
*/ 

#ifdef CycloneV
#define CONCAT(FREQ) ((FREQ) ## Hz)
#define STRINGIZE(FREQ) ((#FREQ) )
#endif

//	#1.5

#ifdef DEBUG
	#define ASSERT(no_fault) \
			if(no_fault == 0) \
			{ \
				cout << "FAULT OCCURED" << endl; \
			} 
#endif

//	#1.7
#ifndef DEBUG
	#define PRINT(x)
#else
#define PRINT(x) cout << #x ## " : " << x << endl;
#endif

#include <iostream>

using std::endl;
using std::cout;

//	#3:
enum STATUS { PartTime, FullTime};
enum GRADELEVEL { UnderGrad, Grad };
enum HOUSING { OffCampus, Dorm  };
enum FOODPLAN { NoMeal, AllMeals };

class StudentCT
{
public:
	StudentCT():
		itsStatus(FullTime),
		itsGradLevel(UnderGrad),
		itsHousing(Dorm),
		itsFoodPlan(AllMeals)
	{}
	~StudentCT() { std::cout << "I'm done" << endl; };
	STATUS getStatus() {if (itsStatus)	return FullTime; 
						else			return PartTime; };
	void setStatus(STATUS theStatus) { itsStatus = theStatus; };
	unsigned int getPlan() { return itsFoodPlan; }


private:
	unsigned int itsStatus		:	1;
	unsigned int itsGradLevel	:	1;
	unsigned int itsHousing		:	1;
	unsigned int itsFoodPlan	:	1;
};



int main()
{

// L21.1
	cout << "Checking on the definitions of DEBUG, " << endl;
	cout << "SW_version, and WINDOWS_VERSION; listing 21.1" << endl;

	#ifdef DEBUG
		cout << "DEBUG is defined" << endl;
	#else 
		cout << "DEBUG is not defined" << endl;
	#endif

	#ifndef SW_VERSION
		cout << "SW_VERSION is not defined" << endl;
	#else
		cout << "SW_VERSION is defined" << endl;
	#endif

	#ifdef WINDOWS_VERSION
		cout << "WINDOWS_VERSION is not defined" << endl;
	#else
		cout << "WINDOWS_VERSION is not defined" << endl;
	#endif

// L21.2:
	int a = 1;
	int b = 2;
	int x = CUBE(a + b);
	int y = BAD_CUBE(a + b);
	int fault = 0;

	cout << "CUBE: "	<< x << endl;
	cout << "BAD_CUBE:" << y << endl;

	cout << STRINGIZE(Hey there) << endl;

	cout << "27 == x, true: " << x << endl;
	ASSERT(27 == x); //		evaluates to true and no action is taken!
	cout << "x == 5, false: " << x << endl;
	ASSERT(x == 5); //		evaluates to false; action is taken!

	int *ptr = &a;
	PRINT(ptr);
	PRINT(*ptr);

//	#3:
	StudentCT Jim;

	cout << "Jim.getPlan (1:All Meal, 2:No Meal):  " << Jim.getPlan() << endl;
	cout << "Jim.getStatus (1:FullTime, 2:PartTime): " << Jim.getStatus() << endl;

	cout << "Done." << endl;
	system("pause");
	return 0;

}
