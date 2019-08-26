//	WORKING WITH STREAMS:
//	Learn: operating system(terminal) and Vendor Supplied GUI libraries!!!
//	>> Extraction Operator (cin)
//	<< Insertion Operator (cout)

//	#1	Library: a collection of object files that can be linked to your program to provide addtional. This is the most basic form of code reuse.
//		Streams are generally less important for C++  since C++ has evolved to use operatin system or compiler vendorprovided graphical user interface GUI libraries.
//	#2	Streams and Buffers:
//		-	streambuf Class: manages buffer, and its member functions provide capability to fill, empty, flush and manipulate the buffer.
//		-	ios Class: is the base class to input and output stream classes. This class contains an object of streambuf as its data member (aggregation)
//		-	istream and ostream Classes derive from ios class and specialize input/output stream behaviour respectively.
//		-	fstream Class provides input/output from files.
//	#3	When a program includes iostream, next objects are automatically created:
//		-	cin:	handles input from the standard input, keyboard.
//		-	cout:	handles output from the standard input, the console screen.
//		-	cerr:	handles unbuffered output to the standard error device, the console screen. Because things are unbuffered, everything sent tocerr is writtento the standard error device immediately,
//					without waiting for the buffer to fill up.
//		-	clog:	Handles buffer error messages that are output to the standard error device, the console screen, and is common to be redirected to log file.
//	#4	Member Functions of CIN:
//		-	get() with no parameters: returns a value of a character found and returns EOF (Ctrl + Z on DOS, Ctrl + D on Linux) if the end of file is reached!
//				example:	char ch; 
//							while (	(	ch = std::cin.get()	) != EOF) 
//							{		
//								some code comes here
//							}
//		-	get(charTypeBuffer); accepts a buffer of type char and returns an iostream object (std::cin) which allows it to be concantenated as std::cin.get(a).get(b) or std::cin.get(a) >> get(b) which
//								is the same.
//		-	get(pointerToTypeCharArray, sizeOfArray, TerminatingCharacter = '\n'): 
//					where the first argument is the address of the first byte of the array, the second parameter can be sizeof(par1), and the last one is the terminating character which defaults to \n
//		-	getline(pointerToTypeCharArray, sizeOfArray);
//		-	ignore(MaxNumOfCharacterToIgnore, TerminatingCharacter):
//					Throws away up to MaxNumofCharacterToIgnore number of characters until a newline character is found. SEE Listing17.8
//		-	peek(): allows to take a peek at at what's in the buffer by returning what's in there. Example if (cin.peek() == '#') cin.ignore(1,'#');
//		-	read():

//		NOTE: get() leaves the termination characterin the input buffer and stops reading the buffer while getline(), but throws away the terminating character!!!

//	#5	Member Functions of COUT:
//		-	flush(): used to flush the output buffer and can be used as std::cout << flush() or std::cout.flush
//		-	put(): used to write a single character into output buffer and returns an ostream reference so that put() can be concatenated as : std::cout.put('H').put('i);
//		-	write(): works just like insertion operator cout << , but accepts the parameter of the maximum number of characters to write std::cout.write(textArray, arraySize);
//				Ex: cout.write(arrayName, sizeof(arrayName)); cout.write("Hey there", 9); 
//				it should be noted that if the size parameter is less than the array size, the text will be trancated and if it's greater than the array size, gibberish residing in the consequent memory
//				block will be printed.

//	#6	Manipulators, Flags and Formatting Instructions: determine which base (hex/decimal) to use, how wide to make the field, and what character to use to fill in that field.
//		-	cout.width(): changes the width of the very next output field and reverts to default right after. Ex: cout.width(20) will not truncate text greater than 20 characters but will add white
//			space to text shorter than 20 characters/
//		-	cout.fill(): When used with cout,width(), sets a particular character to be used by cout.width() to fill the white space.
//		-	cout.setf(ios::FLAGNAME) controls the iostream Set Flags. next FLAGNAMEs are available: showpoit,showpos, left, right, internal, scientific, fixed,showbase, uppercase, dec, oct, hex.
//				Note: the flags can also be concatenated into insertion operator as: cout << "The number is: " << hex << ourNumber << endl; notice, we use hex and not ios::hex when inserted!

//	#7	Manipulating output summary:
//			Special Characters:
//				'\n': New line
//				'\r': Carriage return
//				'\t': Tab
//				'\\': Backlash
//				'\ddd': Octal number-ASCII character
//				'\a': Alarm (ring bell)
//					Ex: cout << "\aAn error occured\t"
//			Manipulators that dont require iomanip:
//				flush: flushes the output
//				endl: inserts newline and flushed the output buffer
//				oct: sets output base to octal
//				dec: sets output base to decimal
//				hex: sets output base to hexadecimal
//			Manipulators that require iomanip:
//				setbase(base): sets output base(0 = dec, 8 = octal, 10 = dec, 16 = hex)
//				setw(width): sets minimum output field width
//				setfill(ch): fills character to be used when width is defined
//				setprecision(p): sets precision for floating point numbers
//				setiosflags(f): sets one or more ios flags
//				resetiosflags(f): resets one or more ios flags.
//					Ex: cout << setw(12) << setfill('#') << hex << x << endl;

//	#8	Using the ofstream: 
//			-	The ofstream type objects are used when data needs to be read from files or written into files. 
//			-	Make sure to include the fstream library #include <fstream>.

//	#9 condition States:
//			eof(): returns true if the iostream object has encountered EOF, end of file character.
//			bad(): returns true if you attempt an invalid operation.
//			fail():	returns true anytime bad() is true or an operation fails.
//			good(); returns true anytime all three of the above are false!
//				Note: fIn.good() is a synonym of fIn. Thus, writing if(fIn.good()) is the same as if(fIn)!!!!!!!!!!!

//	#10	Using a file:
//			-	First a file has to be opened by declaring an object of ofstream/ifstream class: 
//					Declaring an object of class ofstream, and naming it fOut. Opening a file for output (to write into the file):

//						ofstream fOut("myfile.cpp"); ofstream fOut("myfile.cpp", ios::binary); or ofstream fOut(arrayName); ofstream fOut(arrayName, ios::binary);

//					Declaring an object of class ifstream, and naming it fIn. opening a file for input (to read from the file):

//						ifstream fIn("myfile.cpp"); ifstream fIn("myfile.cpp", ios::binary); or ifstream fIn(arrayName); ifstream fIn(arrayName, ios::binary);

//					Note: it should be noted that if the data to be written into a file is the object data, ios::binary should be used!
//			-	You can then use the declared object just as you use the CIN or COUT:

//					fOut << "This text will be written directly into the file\n";
//					fOut << bufferArray << endl;
//					fIn.get(ch); //read a character from a file into char type object.

//			-	Once done with a file stream, remember to close it using close() function as: fIn.close() or fOut.close()
//			-	The default behaviour of a stream can be changed using:
//					ios::app - Appneds to the end of existing files rather than truncating them
//					ios::ate - Places you at the end of the file, but you can write data anywhere in the file. ?????
//					ios::trunc - Causes existing files to be truncated; THIS IS THE DEFAULT
//					ios::nocreate - if the file does not exist, the open will fail!
//					ios::noreplace - if the file does not exist, the open fail!

//	#11 Binary Files VS Text File:
//			-	Text files store everything as text which can be inefficient.
//			-	C++ provides ios::binary flag to distinguish between a text file and a binary file.
//			-	On some systems, all data is stored as binary and binary flag is ignored, or sometimes even illegal!
//			-	Binary Files can store: integers, string, entire data structures!!!
//			-	All of the data can be written at once using write() method which accepts 2 arguments:
//					1.	type char pointer to the object (you must cast you object to be a char type pointer: (char *) Objectname;
//					2.	The number of characters expected to be read/written which can be determined using sizeof() function!
//					Note: when writing and object using binary mode, only the object's data is stored in the file not its methods!
//					Ex:		Cat Barsik(10,3); fout.write((char *) &Barsik, sizeof Barsik); // writing the age and the weight of Barsik into a file
//							fin.read((char *) &Shustrik, sizeof Shustrik); // copying the age and the weight of the Barsik from a file into a new Object Shustrik

//	#12	Command-Line Processing!!! HECK YEAH!!!
//			-	Two parameters are often used with main which are argc and argv: int main(int argc, char **argv):
//				1.	The first argument passed is an integer count of the number of arguments on the command line where the program name itself is count as well! It's a good idea to test this argument to
//					see if the expected number of arguments is received. Note: arg[0] is the name of program, arg[1] is the first argument, arg[2] is the second and so on...
//				2.	The second parameter to main() is an array of pointers to character strings which can be declared to be:
//					a. a pointer to a char
//					b. a pointer to an array of char
//					c. an array of arrays of char

#include <fstream>
#include <iostream>
using namespace std;

//#L17.20

class Animal
{
public:
	Animal(int weight = 25, long days = 365) :itsWeight(weight), daysAlive(days) {}
	~Animal() {}
	int GetWeight() const { return itsWeight; }
	long GetDaysAlive()const { return daysAlive; }
	void SetWeight(int weight) { itsWeight = weight; }
	void SetDaysAlive(long days) { daysAlive = days; }

private:
	int itsWeight;
	long daysAlive;
};

int main(int argc, char **argv)
{

	char fileName[80];
	char buffer[255];
	char textFileExtension[] = ".txt";
	char excelFileExtension[] = ".csv";
	
	cout << "File Name: ";
	cin >> fileName;

	printf("The size is %d\n", sizeof(fileName));
	//strcat_s("someString" or &addressOfArray, int sizeOfArray, "textToConcatenate"
	strcat_s(fileName, sizeof(fileName), textFileExtension);

	ofstream fout(fileName, ios::app);
		fout << "This line is written directly to the file and you entered: \n";
		cout << "Enter text for the file: ";
		cin.ignore(1, '\n');
		cin.getline(buffer, 255);
		fout << buffer << "\n";
	fout.close();

	ifstream fin(fileName);
		cout << "Here is the contents of the file:\n";
		char ch;
		while (fin.get(ch))
			cout << ch;
		cout << "\n***End of file contents.***\n";
	fin.close();


//L17.20
	// If the program is executed from the terminal without any additional parameters:
	if (argc != 2)
	{	
		cout << "No argument passed. Terminating the programm... \n" << endl;
		cout << "Usage: " << argv[0] << " <filename>" << endl;
		system("pause");
		return (1);
	}
	
	//	ofstream ObjectName(whereToWrite, binary/text);
	ofstream fout1(argv[1], ios::binary);
	//if the file failed to open:
	if (!fout1)
	{
		cout << "Unable to open " << argv[1] << " for writing.\n";
		system("pause");
		return(1);
	}

	// Let's create an object of type Animal and call it a BEAR:
	Animal Bear(50, 100);
	//Remember, write has next syntax: write( &AddresOfArrayToContainTheText, number of bytes including the NULL character); 
	fout1.write((char *) &Bear, sizeof Bear);
	fout1.close();

	//	ifstream ObjectName(whereToReadFrom, binary/text);
	ifstream fin1(argv[1], ios::binary);
	if (!fin1)
	{
		cout << "Unable to open " << argv[1] << " for reading.\n";
		system("pause");
		return(1);
	}

	Animal BearTwo(1, 1);

	cout << "BearTwo weight: " << BearTwo.GetWeight() << endl;
	cout << "BearTwo days: " << BearTwo.GetDaysAlive() << endl;

	fin1.read((char *)&BearTwo, sizeof BearTwo);
	cout << "BearTwo weight: " << BearTwo.GetWeight() << endl;
	cout << "BearTwo days: " << BearTwo.GetDaysAlive() << endl;
	fin1.close();


	system("pause");
	return 0;

}
