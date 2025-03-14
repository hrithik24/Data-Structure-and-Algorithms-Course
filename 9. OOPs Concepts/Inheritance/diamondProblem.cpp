#include<iostream>
using namespace std;
class Person{
    public:
        Person(){
            cout << "Person::Person() called" << endl;
        }
        Person(int x){
            cout << "Person::Person(int) called" << endl;
        }
        void walk(){
            cout << "Walking..." << endl;
        }
};

class Faculty: virtual public Person{
    public:
        Faculty(int x) : Person(x){
            cout << "Faculty::Faculty(int) called" << endl;
        }
        void walk(){
            cout << "Walking..." << endl;
        }
};

class Student: virtual public Person{
    public:
        Student(int x) : Person(x){
            cout << "Student::Student(int) called" << endl;
        }
        void walk(){
            cout << "Walking..." << endl;
        }
};

class TA: public Student,public Faculty{
    public:
        TA(int x) : Student(x), Faculty(x){
            cout << "TA::TA(int) called" << endl;
        }

};

int main(){
    TA ta1(30);
    // Using scope resolution
    // ta1.Faculty::walk();
    // ta1.Student::walk();
}