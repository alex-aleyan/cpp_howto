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
