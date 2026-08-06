#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;


// #11 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//11.1.i VECTORs:

class Student
{
public:
    Student(); // Default construct
    Student(const string& name, 
            const int      age);
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

//11.2.i    MAP Container:

//funct prototype:
#include<map>

// Template Function (type adoptive function!):
template<class KeyType, class ObjectType>
void ShowMap(const map<KeyType, ObjectType>& vec); // <keyType, objectType>

typedef map<string, Student> MapClass;


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

//11.2.i    MAP Container:


// Template Function (type adoptive function!):
template<class KeyType, class ObjectType>

void ShowMap(const map<KeyType, ObjectType>& vec); // <keyType, objectType>

typedef map<string, Student> MapClass;

//11.2.i    MAP Container:
template<class KeyType, class ObjectType>
void ShowMap(const map<KeyType, ObjectType>& vec)
{
    for (typename map<KeyType, ObjectType>::const_iterator ci = vec.begin(); ci != vec.end(); ++ci)
        cout << ci->first << ": " << ci->second << endl;

    cout << endl;
}


#endif