#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "./myClass.h"
#include "./consts.h"


using namespace std;

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

    //C++ Style to allocate memory dynamically:
    char *s = new char[100]; 

    // C Style to allocate memory dynamically:
    char *t = (char *) malloc(100 * sizeof(char)); 
    
    //C++ Style to de-allocate memory:
    delete[] s;

    // C Style to de-allocate memory:
    free(t);    

    cout << "Hellow World!!!\n"; 
    printf("Hellow World!\n");  


    // The commented code will throw an error as per comment below:
    // int var1=0;
    // cout << "Provide a value: ";
    // cin >> var1;
    // cout << "\n";
    //constexpr double var_c = deg2rad(180*var1); // error: constexpr cannot be modified during runtime.

    cout << "deg2rad(180)=" << deg2rad(180) << " rads\n"; 

    // Demonstrating standard predefine macros:
    cout << "Standard Predefuned Macros:" << "\n  Source File: " << __FILE__ << "\n  Time: " << __TIME__ << "\n  Date: " << __DATE__ << "\n";

    return 0;

}


