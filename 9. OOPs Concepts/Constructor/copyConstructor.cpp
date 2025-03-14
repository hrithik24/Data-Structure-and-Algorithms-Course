#include<iostream>
using namespace std;
class Student{
    private:
        string gf;
    public:
        int id,nos,age;
        bool present;
        string name;

        // default constructor
        Student(){
            cout << "Default constructor" << endl;
        }

        // parameterized constructor
        Student(int id,int age,bool present,string name,int nos){
            this->id = id;
            this->age = age;
            this->present = present;
            this->name = name;
            this->nos = nos;
            cout << "Student parameterized constructor" << endl;
        }

        // copy constructor
        Student(const Student &srcobj){
            cout << "Student Copy Constructor" << endl;
            this->id = srcobj.id;
            this->name = srcobj.name;
            this->present = srcobj.present;
            this->age = srcobj.age;
            this->nos = srcobj.nos;
        } 
};
  
int main(){ 
    Student s1;
    s1.id = 20;
    cout << s1.id << endl;
    Student s2 = s1; // creating another object using s1 and copy constructor calling
    cout << s2.id << endl;
    Student s3(2,23,1,"Hrithik",5);
    cout << s3.name << endl;
    Student s4;
    s4 = s3;
    cout << s4.name << endl;
    Student s5(3,24,0,"Sharma",4);
    Student s6 = s5; // 1 st method
    Student s7(s5); // 2nd method
    cout << s5.name << endl;
    cout << s6.name << endl;
    cout << s7.name << endl;

    return 0;
}