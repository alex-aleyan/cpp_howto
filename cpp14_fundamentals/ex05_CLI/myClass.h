
#pragma once
// #define STDAFX_H
// #define STDAFX_H

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

// # endif
