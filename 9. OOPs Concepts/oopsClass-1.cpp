#include<iostream>
using namespace std;
class Student{

    public:

    // default constructor
    Student(){
        cout << "Default constructor invoked." << endl;
    }

    // parameterized constructor
    Student(int i,string n,int ag,int s){
        id = i;
        name = n;
        age = ag;
        nos = s;
    }

    // data members
    int id;
    string name;
    int age;
    int nos;

    // member functions
    void study(){
        cout << "Studying" << endl;
    }
    void bunk(){
        cout << "bunking" << endl;
    }
    void gaming(){
        cout << "Gameing" << endl;
    }
};

// empty class size
class hello{
    // no statements are here
};
int main(){
    Student s1 = Student(1,"Hrithik",24,4);
    cout << s1.name << " " << s1.age;
    // cout << sizeof(hello) << endl;
    return 0;
}