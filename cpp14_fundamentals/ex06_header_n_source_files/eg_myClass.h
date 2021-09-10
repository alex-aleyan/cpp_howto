#pragma once
// #define STDAFX_H
// #define STDAFX_H


    #include <iostream>
    #include <stdlib.h>
    #include <stdio.h>


    using namespace std;


    // C++ adds a user defined type "class":
    namespace eg{


        class myClass {
            public:
                // provide default constructor:
                myClass() {
                    a = 1;
                    b = 'a';
                    cout<< "Calling MyClass Constructor.\n";
                } 
                // provide default destructor:
                ~myClass() {
                    cout<< "Calling MyClass Destructor.\n";
                } 

                // See the eg_myClass.cpp file for the definition of the below funcs:
                void setVal(int i);
                int  getVal();

                void setChar(char i);
                char  getChar();
        
            private:
        
                int a;
                char b;
        };


    }



// # endif
