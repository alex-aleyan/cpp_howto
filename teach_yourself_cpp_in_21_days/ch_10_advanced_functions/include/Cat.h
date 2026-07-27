#ifndef CAT_H
#define CAT_H

class Cat
{
    public:
        Cat();
        Cat(const Cat &);
        Cat & operator=(const Cat &);
        ~Cat();
        int GetAge() const {return *itsAge;}
        int GetWeight() const { return *itsWeight; }
        void SetAge(int age) { *itsAge = age; }
        void SetWeight(int weight) { *itsWeight = weight; }
    
    private:
        int *itsAge;
        int *itsWeight;

};
#endif