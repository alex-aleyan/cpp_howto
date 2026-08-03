#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <list>

#include <array.h>
#include <animal.h>

using namespace std;


 
 
 
 
 
 
 
 // #8.1:
 void Intrude(Array<int> theArray)
 {
     std::cout << std::endl << "*** Intrude ***" << std::endl;
     for (int i = 0; 
              i < theArray.itsSize; 
              i++)
         cout << "Intrude(): theArray.pType[" << i << "]=" << theArray.pType[i] << endl;
     cout << endl;
 }



//// // #8.2:
//// template <class T>
//// ostream& operator<< (ostream& output, Array<T>& theArray)
//// {
////     for (int i = 0; i < theArray.itsSize; i++)
////         output << "[" << i << "]" << theArray[i] << endl;
////     return output;
//// }
//// 
//// 
//// 
//// 
//// 
//// 
//// 
//// // #11 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//// //11.1.i VECTORs:
//// 
//// class Student
//// {
//// public:
////     Student(); // Default construct
////     Student(const string& name, const int age);
////     Student(const Student& rhs); // Copy Construct
////     ~Student();
//// 
////     void SetName(const string& name);
////     string GetName() const; // can't change private members!
//// 
////     void SetAge(const int age);
////     int GetAge() const;
//// 
////     Student& operator=(const Student& rhs);
//// 
//// private:
////     string itsName;
////     int itsAge;
//// };
//// 
//// //Default Construct
//// Student::Student() : 
////     itsName("New Student"),
////     itsAge(16)
//// {}
//// 
//// 
//// Student::Student(const string& name, const int age) :
////     itsName(name),
////     itsAge(age)
//// {}
//// 
//// Student::Student(const Student& rhs) :
////     itsName(rhs.GetName()), itsAge(rhs.GetAge())
//// {}
//// 
//// Student::~Student()
//// {}
//// 
//// void Student::SetName(const string& name)
//// {
////     itsName = name;
//// }
//// 
//// string Student::GetName() const
//// {
////     return itsName;
//// }
//// 
//// void Student::SetAge(const int age)
//// {
////     itsAge = age;
//// }
//// 
//// int Student::GetAge() const
//// {
////     return itsAge;
//// }
//// 
//// Student& Student::operator=(const Student& rhs)
//// {
////     itsName = rhs.GetName();
////     itsAge = rhs.GetAge();
////     return *this;
//// }
//// 
//// ostream& operator<<(ostream& os, const Student& rhs)    
//// {
////     os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
////     return os;
//// }
//// 
//// template<class T> // the function below is to be a template:
//// void ShowVector(const vector<T>& v);
//// 
//// typedef vector<Student> SchoolClass;
//// 
//// //11.1.ii LIST Container:
//// typedef list <int> IntegerList;
//// 
//// //11.2.i    MAP Container:
//// 
//// //funct prototype:
//// #include<map>
//// 
//// // Template Function (type adoptive function!):
//// template<class T, class A>
//// void ShowMap(const map<T, A>& vec); // <keyType, objectType>
//// 
//// typedef map<string, Student> MapClass;



int main()
{

    // create an array of integers
    Array<int> theArray; 
    for (int i = 0; 
             i < theArray.GetSize(); 
             i++) {
        std::cout << "theArray[" << i << "]= " << theArray[i] << "\t\n";
        theArray[i] = i * 2;
        std::cout << "theArray.GetSize() = " << theArray.GetSize() << "\n";
    }
    theArray.displayType();


    // Create an array of Animals - call it theZoo
    Array<Animal> theZoo; // an array of Animals
    Animal *pAnimal;      // pointer to an Animal element
    for (int i = 0; 
             i < theZoo.GetSize(); 
             i++)
    {
        theZoo[i] = i * 2;
        pAnimal = new Animal(i * 3);
        theZoo[i] = *pAnimal;
        delete pAnimal;
    }

    // Call GetWeight and displayWeight funcs from Animal class
    for (int j = 0; j < theArray.GetSize(); j++)
    {
        std::cout << "theZoo[" << j << "].displayWeight():"
                  << theZoo[j].GetWeight() << "\n\n";

        std::cout <<  "\n\n";
        theZoo[j].displayWeight();
        std::cout <<  "\n\n";
    }



   // #8.1, now using the friend function:
   cout << " #8.1 using the friend function to find the members of Array<int>";
   Intrude(theArray);

//    cout << endl << "DONE 8.1" << endl << endl;
//     
//    cout << theArray << endl;
//
//    cout << endl << "DONE 8.2" << endl;
//
//    cout << "itsNumberArrays: " << Array<Animal>::GetNumberArrays() << endl;
//
//    // #11, STL:
//    cout << " #11 STL vector:";
//
//    Student Harry("Harry", 15);
//    Student Marry("Marry", 16);
//    Student Peter("Pete", 16);
//    Student Nikolas("Nick", 16);
//
//    SchoolClass TenthGrade(3);
//    cout << "TenthGrade: " << endl; ShowVector(TenthGrade); 
//    cout << endl;
//
//    TenthGrade[0] = Harry;
//    TenthGrade[1] = Marry;
//    TenthGrade[2] = Peter;
//
//    cout << "TenthGrade after adding Harry, Marry and Pete: " << endl; ShowVector(TenthGrade);
//
//    TenthGrade.push_back(Nikolas);
//    cout << "TenthGrade after adding Nick: " << endl; ShowVector(TenthGrade);
//
//    TenthGrade[2].SetName("Peter");
//    TenthGrade[3].SetName("Nickolas");
//    cout << "TenthGrade after Pete wants to be Peter and Nick wants to be Nickolas: " << endl; ShowVector(TenthGrade);
//
//    cout << " #11 STL list:" << endl;
//
//    typedef list<int> IntegerList;
//
//    IntegerList intList;
//
//    for (int i = 1; i <= 10; ++i)
//        intList.push_back(i * 2);
//
//    for (IntegerList::const_iterator ci = intList.begin(); ci != intList.end(); ++ci) //.end() returns the address of one iteration past the last node!!!
//        cout << *ci << " " << endl;
//
//    //11.ii LIST Container:
//    IntegerList intListii;
//
//    for (int i = 1; i <= 10; ++i)
//        intList.push_back(i * 2);
//
//    for (IntegerList::const_iterator ci = intListii.begin(); ci != intListii.end(); ++ci)
//        cout << *ci << " ";
//
//    //11.2.i    MAP Container:
//    Student Mike("Mike", 18);
//    Student Lisa("Lisa", 15);
//    Student George("George", 17);
//
//    MapClass historyClass;
//    historyClass[Mike.GetName()] = Mike;
//    historyClass[Lisa.GetName()] = Lisa;
//    historyClass[George.GetName()] = George;
//
//    cout << "historyClass : " << endl;
//    ShowMap(historyClass);
//    cout << "We know that " << historyClass["Mike"].GetName() << " is " << historyClass["Mike"].GetAge() << " years old." << endl;
//
//    system("pause");
//    return 0;
}

// template<class T>
// void ShowVector(const vector<T>& vec)
// {
//     cout << " max_size() = " << vec.max_size();
//     cout << "\tsize() = " << vec.size();
//     cout << "\tcapacity() =" << vec.capacity();
//     cout << "\t" << vec.empty() ? "empty" : "not empty"; // if vec.empty() returns true, then use "empty" as a string to cout, else use "not empty"
//     cout << endl;
// 
//     for (unsigned int i = 0; i < vec.size(); ++i)
//         cout << vec[i] << endl;
// 
//     cout << endl;
// }
// 
// //11.2.i    MAP Container:
// 
// template<class T, class A>
// void ShowMap(const map<T, A>& vec)
// {
//     for (map<T, A>::const_iterator ci = vec.begin(); ci != vec.end(); ++ci)
//         cout << ci->first << ": " << ci->second << endl;
//     cout << endl;
// }
