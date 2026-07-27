#ifndef SIMPLECAT_H
#define SIMPLECAT_H

class SimpleCat
{
    public:
        SimpleCat();
        ~SimpleCat() {}
        void SetAge(int age);
        int GetAge() const ; // Using keyword const, we made it read only function. IT CANNOT CAUSE CHANGES TO THE OBJECT OF THIS CLASS!
    
        void SetWeight(int weight) ;
        int GetWeight() const ;
    
    private:
        int itsAge;
        int itsWeight;
};



#endif