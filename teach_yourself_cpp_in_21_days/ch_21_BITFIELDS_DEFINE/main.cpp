#define DEBUG
#define SW_VERSION 5

#define CUBE(A)        ((A)*(A)*(A))
#define BAD_CUBE(A) (A*A*A) 

// #1.3 

#define CycloneV
/*
#define SPEED(FREQ) ((FREQ) ## Hz)
#define FREQ_50 50
*/ 

#ifdef CycloneV
#define CONCAT(FREQ) ((FREQ) ## Hz)
#define STRINGIZE(FREQ) ((#FREQ) )
#endif

//    #1.5

#ifdef DEBUG
    #define ASSERT(no_fault) \
            if(no_fault == 0) \
            { \
                cout << "FAULT OCCURED" << endl; \
            } 
#endif

#define PRINT(ptr) cout << *ptr << endl 
#define PRINT_CONCAT_POINTERS(ptr1, ptr2) cout << *ptr1 << *ptr2 << endl 
#define PRINT_CONCAT_STRINGS( str1, str2) cout <<  str1 <<  str2 << endl 

#include <iostream>

using std::endl;
using std::cout;

//    #3:
enum STATUS { PartTime, FullTime};
enum GRADELEVEL { UnderGrad, Grad };
enum HOUSING { OffCampus, Dorm  };
enum FOODPLAN { NoMeal, AllMeals };

class StudentCT
{
public:
    StudentCT():
        itsStatus(FullTime),
        itsGradLevel(UnderGrad),
        itsHousing(Dorm),
        itsFoodPlan(AllMeals)
    {}
    ~StudentCT() { std::cout << "I'm done" << endl; };
    STATUS getStatus() {if (itsStatus)    return FullTime; 
                        else            return PartTime; };
    void setStatus(STATUS theStatus) { itsStatus = theStatus; };
    unsigned int getPlan() { return itsFoodPlan; }


private:
    unsigned int itsStatus        :    1;
    unsigned int itsGradLevel    :    1;
    unsigned int itsHousing        :    1;
    unsigned int itsFoodPlan    :    1;
};



int main()
{

// L21.1
    cout << "Checking on the definitions of DEBUG, " << endl;
    cout << "SW_version, and WINDOWS_VERSION; listing 21.1" << endl;

    #ifdef DEBUG
        cout << "DEBUG is defined" << endl;
    #else 
        cout << "DEBUG is not defined" << endl;
    #endif

    #ifndef SW_VERSION
        cout << "SW_VERSION is not defined" << endl;
    #else
        cout << "SW_VERSION is defined" << endl;
    #endif

    #ifdef WINDOWS_VERSION
        cout << "WINDOWS_VERSION is not defined" << endl;
    #else
        cout << "WINDOWS_VERSION is not defined" << endl;
    #endif

// L21.2:
    int a = 1;
    int b = 2;
    int x = CUBE(a + b);
    int y = BAD_CUBE(a + b);
    int fault = 0;

    cout << "CUBE: "    << x << endl;
    cout << "BAD_CUBE:" << y << endl;

    cout << STRINGIZE(Hey there) << endl;

    cout << "27 == x, true: " << x << endl;
    ASSERT(27 == x); //        evaluates to true and no action is taken!
    cout << "x == 5, false: " << x << endl;
    ASSERT(x == 5); //        evaluates to false; action is taken!

    std::string hello_w0r1d_str = "hello world!";
    PRINT(&hello_w0r1d_str); // FIXME: uncomment and resolve

    std::string h311o_str = "h311o!";
    std::string w0r1d_str = "w0r1d!";
    PRINT_CONCAT_POINTERS(&h311o_str, &w0r1d_str); // pass sting's address
    PRINT_CONCAT_STRINGS(  h311o_str,  w0r1d_str);    // pass string var

    //    #3:
    StudentCT Jim;

    cout << "Jim.getPlan (1:All Meal, 2:No Meal):  " << Jim.getPlan() << endl;
    cout << "Jim.getStatus (1:FullTime, 2:PartTime): " << Jim.getStatus() << endl;

    cout << "Done." << endl;
    system("sleep 1");
    return 0;
    
}
