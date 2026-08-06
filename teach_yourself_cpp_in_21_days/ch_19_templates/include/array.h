#ifndef ARRAY
#define ARRAY

#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include <list>

using namespace std;

const int DefaultSize = 10;

template <class T>
class Array
{
    public:
        Array(int itsSize = DefaultSize);
        Array(const Array &rhs); // copy construct in case if new object to be instantiated is to be a copy of an other object passed in as rhs.
        ~Array() { delete[] pType; }
    
        Array& operator=(const Array&);
        T& operator[] (int offSet) { return pType[offSet]; }
        const T& operator[] (int offSet) const { return pType[offSet]; }
    
        // #8.1: since it's a friend, it can access private data:
        friend void Intrude(Array<int>);
    
        // #8.2:
        // template <class T>
        // friend ostream& operator<< (ostream&, Array<T>&);
    
        //    #10:
               int  GetSize()   const { return itsSize        ; }
        static int  GetNumberArrays() { return itsNumberArrays; }
    
    
        void displayType() { 
            std::cout << "The type is: <" 
                      << typeid(T).name() 
                      << ">"
                      << std::endl; }

        // #8.2:
        // ostream&  operator<<( Array<T>&  theArray)
        // {
        //     ostream&    output;
        //     //ostream&    output;
        //     for (int i = 0; i < theArray.itsSize; i++)
        //         output << "[" << i << "]" << theArray[i] << endl;
        //     return output;
        // }


        friend ostream& operator<< (ostream& output, Array<T>& theArray)
        {
            for (int i = 0; i < theArray.itsSize; i++)
                output << "operator<<(): theArray[" << i << "]=" << theArray[i] << endl;
            return output;
        }


    private:
        T *pType;
        int itsSize;
        //    #10:
        static  int itsNumberArrays ;
};



//    #10:
template <class T>
int Array<T>::itsNumberArrays = 0;



// Implementing/Defining Construct
template <class T>
Array<T>::Array(int size) : 
// Array<T>::Array(int size = DefaultSize) : 
itsSize(size)
{
    pType = new T[size]; // allocate an array of size "size" and type "T".
//    #9 Initilizing the object when creating:
    for (int i = 0; i < size; i++)
    {
        pType[i] = (T) 0;   // here we create a temporarily object when casting (T) 0; and the values of this temporarily object are then assigned to the newly created object the pType pointer points to.
                            // The object created by casting is then released which makes it a very inefficient method of initialization!!!!!!!!!!!!!!!!!!!!!
                            //    #10:
    }
    //    #10:
    itsNumberArrays++;
}


// #9 This specialized contruct makes sure the Animal Array is initialiazed without doing all the extra steps of the implementation above!
// template <class T>
// Array<Animal>::Array(int AnimalArraySize) :
// itsSize(AnimalArraySize)
// {
//     pType = new Animal[AnimalArraySize];
//     //    #10:
//     itsNumberArrays++;
// }


/*
template <class T>
Array<T>::Array(int size) :
itsSize(size)
{
    pType = new T[size];
    for (int i = 0; i < size; i++)
    {
        pType[i] = (T)0;
    }
    //    #10:
    itsNumberArrays++;
}
*/



template <class T>
Array<T>::Array(const Array &rhs)
{
    itsSize = rhs.GetSize();
    pType = new T[itsSize];
    for (int i = 0; i < itsSize; i++)
    {
        pType[i] = rhs[i];
    }
    //    #10:
    itsNumberArrays++;
}

template <class T>
Array<T>& Array<T>::operator=(const Array &rhs) // return type: Array<T>&, operator: Array<t>::operator=, argument: const Array &rhs
{
    if (this == &rhs)
        return *this;
    delete[] pType;
    itsSize = rhs.GetSize();
    pType = new T[itsSize];
    for (int i = 0; i < itsSize; i++)
    {
        pType[i] = rhs[i];
    }
    return *this;
}


// #8.1:
void Intrude(Array<int> theArray) // Friend function
{
    std::cout << std::endl << "*** Intrude ***" << std::endl;
    for (int i = 0; 
             i < theArray.itsSize; 
             i++)
        cout << "Intrude(): theArray.pType[" << i << "]=" << theArray.pType[i] << endl;
    cout << endl;
}



#endif