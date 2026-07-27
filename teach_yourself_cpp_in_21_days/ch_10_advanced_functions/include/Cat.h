#ifndef CAT_H
#define CAT_H

class Cat
{
    public:
        Cat();
        Cat(const Cat &);
        Cat & operator=(const Cat &);
        ~Cat();
        int GetAge() const ;
        int GetWeight() const ;
        void SetAge(int age) ;
        void SetWeight(int weight);
    
    private:
        int *itsAge;
        int *itsWeight;

};
#endif