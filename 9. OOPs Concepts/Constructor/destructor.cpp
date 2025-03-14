#include<iostream>
using namespace std;
class Student{
    public:
        int age,id,nos;
        string name;

         // default constructor
        Student(){
            cout << "Default constructor invoked." << endl;
        }

        // parameterized constructor
        Student(int i,string n,int ag,int s){
            cout << "Student Parameterized constructor called." << endl;
            id = i;
            name = n;
            age = ag;
            nos = s;
        }

        // destructor
        ~Student(){
            cout << "Student destructor called." << endl;
        }
};
int main(){
    Student s1(1,"Hrithik",12,1);
    cout << s1.name << endl;

    {
        Student s2(2,"Sharma",24,2);
        cout << s2.name << endl;
    }

    Student s3;
    return 0;
}