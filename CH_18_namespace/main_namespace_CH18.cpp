//	NAMESPACES:	
//	-	items declared within the namespace are owned by the namespace.
//	-	these items can have only PUBLIC visibility!!! They cannot be private or protected as with classes.
//	-	namespaces can be NESTED!!!

//	#1	Declaring NAMESPACE:
//			namespace Window
//			{
//				void move( int x, int y);

//				class List
//				{
//					class methods and data
//				}
//			}
//	#2	Defining NAMESPACE: the functions declared in the namespace using .h file can then be defined outside the namespace body using a .cpp file:
//			void Window::move(int x, int y){ some code here;}
//	#3	Adding a new member: a new member can only be added within the body of the namespace. YOU CANNOT USE DEFINE THEM OUTSIDE THE NAMESPACE"S BODY USING QUALIFIERS:
//			int Window::newIntegerinNamespace; // WRONG, WON'T WORK!!!!
//	#4	Nesting NAMESPACES: a namespace can be nested within another namespace:
//			namespace Window
//			{
//				namespace Pane
//				{
//					void (int x, int y);
//				}
//			}
//			//it can then be called using qualifier:
//			Window::Pane::size(10,20);

//	#5	USING directive and USING declaration:

//	#6:	The namespace ALIAS: Allows the named namespace to be renamed for convinience. Next syntax is used:
//			namespace NewNameSpace = OldNameSpace;

//	#7:	Unnamed NAMESPACE: Simply a NAMESPACE without a name:
//		-	commonly used to shield global data from potential name clashed between object files and other TRANSLATION UNITS (what the heck is a translation unit???).
//		-	the objects within unnamed namespace can be referred to without explicit qualification.


//	NOTE: Remember, variables local to a function/block have higher priority over global variables unless explicitly specified using accessor specifiers!!!

#include <iostream>



namespace Window
{
	const int MAX_X = 30;
	const int MAX_Y = 40;
	class Pane
	{
	public:
		Pane();
		~Pane();
		void size(int x, int y);
		void move(int x, int y);
		void show();
	private:\
		static int count;
			int x;
			int y;
	};
//	#5	USING directive and USING declaration:
	int value1 = 20;
	int value2 = 40;
}

int Window::Pane::count = 0;
Window::Pane::Pane() : x(0), y(0) {}
Window::Pane::~Pane() {}

void Window::Pane::size(int x, int y)
{
	if (x < Window::MAX_X && x > 0)
		Pane::x = x;
	if (y < Window::MAX_Y && y > 0)
		Pane::y = y;
}

void Window::Pane::move(int x, int y)
{
	if (x < Window::MAX_X && x > 0)
		Pane::x = x;
	if (y < Window::MAX_Y && y > 0)
		Pane::y = y;
}

void Window::Pane::show()
{
	std::cout << "\nx " << Pane::x;
	std::cout << "\ny " << Pane::y << std::endl;
}


int integerValue = 0; // versionA 

int main()
{
	//SCOPE and NAMESPACE::
	int integerValue = 0; // versionB
	{
		::integerValue = 10;	// using BLANK SCOPE as :: to access the global variable integerValue versionA
		integerValue = 20;		// accesses versionB of integerValue since versionB has higher priority than versionA when it comes to the scope of main() since it's local to the main function.
	}


	Window::Pane aPane; // or we could've types "using namespace Window" or to be more specific we could've typed "using namespace Window::Pane
	aPane.move(20, 20);
	aPane.show();

//	#5	USING directive and USING declaration:
	Window::value1 = 10;

	{// NOTICE: namespace Window included using the line below is true only within this block!!!
		using namespace Window; // NOTICE, namespace keyword MUST BE used when USING DERACTIVE is used!
		value2 = 30;
		std::cout << "\n USING DIRECTIVE: " << value2 << std::endl;
	}
	{
		using Window::value1; // NOTICE, namespace keyword IS NOT used when USING DECLARATION is used!
		value1 = 40;
		std::cout << "\n USING DECLARATION: " << value1 << std::endl;
	}

//	#6:	The namespace ALIAS: 
	{
		namespace AliasToWindow = Window;
		AliasToWindow::value1 = 50;
		std::cout << "\n USING DECLARATION: " << AliasToWindow::value1 << std::endl;
	}

	system("pause");
	return 0;
}