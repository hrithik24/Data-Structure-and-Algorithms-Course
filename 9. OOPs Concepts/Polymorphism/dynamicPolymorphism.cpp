#include<iostream>
using namespace std;
class Animal{
    public:
        virtual void sound(){
            cout << "Animal sound" << endl;
        }
};

class Dog : public Animal{
    public:
        void sound() override{
            cout << "Dog is barking" << endl;
        }
};

class Cat : public Animal{
    public:
        void sound() override{
            cout << "Cat is Meowing" << endl;
        }
};

int main(){
    Animal *obj1 = new Dog();
    obj1->sound();
    Animal *obj2 = new Cat();
    obj2->sound();
}