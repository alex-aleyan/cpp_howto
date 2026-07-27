#ifndef CAT_H
#define CAT_H

// Class Interface starts here and strentches through the next 23 lines:
class Cat
{
    public:
        // CONSTRUCTOR:
        Cat(int    age, 
            int weight);
    
        // DESTRUCTOR:
        // notice, even so the DESTRUCTOR doesn't do anything, we still have to define it by using an empty block { } or a cout statement:
        ~Cat();
    
        // PUBLIC ACCESSORs:
        // Putting the definition of this method into the class interface make this method's implementation of type INLINE. 
        // Notice, since this is a SET kind of method, it is not of a const type.
        void setAge(int age);

        int  getAge() const;

        // Putting the definition of this method into the class interface make this method's implementation of the type INLINE. 
        // Also, using the const keyword right after the method's tag, we restrict this method from being able to change 
        // the content of data members:int getAge() const { return itsAge; }; 
        void setWeight(unsigned int weight);

        int  getWeight() const;
    
        // OUR CAT CAN MEOW NOW:
        void meow() const ;
    
    private:
        // All the data members are private:
        int itsAge;
        int itsWeight;
};

#endif