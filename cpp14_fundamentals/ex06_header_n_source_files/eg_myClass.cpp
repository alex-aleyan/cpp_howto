#include "eg_myClass.h"



// Notice the eg::myClass:: needed to specify the <namespace>::<class>
void eg::myClass::setVal(int i){
    a=i;
}

int  eg::myClass::getVal(){
    return a;
}

void eg::myClass::setChar(char i){
    b=i;
}

char eg::myClass::getChar(){
    return b;
}

