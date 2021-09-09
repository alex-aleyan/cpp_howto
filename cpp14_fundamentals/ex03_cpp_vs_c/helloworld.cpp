#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// C++ adds a user defined type "class":
class myClass {
    public:

        myClass() {
            a = 1;
            b = 'a';
            cout<< "Calling MyClass Constructor.\n";
        } 

        ~myClass() {
            cout<< "Calling MyClass Destructor.\n";
        } 
    private:
        int a;
        char b;
};

// In C++ struct is a class whose members are public by default:
struct myStruct {
    int a;
    char b;
};


// In C++:
//     1. enumerations are scoped
//     2. enumerations are strongly typed.
//     3. enumerations can be cast to ints, but are not assignable to INTs implicitly like they are in C. 
enum class Size {XS, S, M ,L ,XL};  // <- Preferred method is using C++ enum class; are not int and checked at compile time.
typedef enum {FLASE, TRUE} Boolean; // C style (bool is a fundamental type in C++)

int main (){

    myClass aClass_o;

    //C++ Style
    char *s = new char[100]; 

    // C Style
    char *t = (char *) malloc(100 * sizeof(char)); 
    
    //C++ Style
    delete[] s;

    // C Style
    free(t);    

    cout << "Hellow World!!!\n"; 
    printf("Hellow World!\n");  

    return 0;

}


