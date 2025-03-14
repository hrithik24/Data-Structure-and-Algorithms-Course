#include<iostream>
using namespace std;
class Student{
    private:
        string gf;

    public:
         // data members
        int id;
        string name;
        int age;
        int nos;

        // getter
        string getGFName(){
            return gf;
        }

        // setter
        void setGFName(string gf){
            this->gf = gf;
        }

        // parameterized constructor
        Student(int i,string n,int ag,int s,string g){
            cout << "Parameterized constructor called" << endl;
            id = i;
            name = n;
            age = ag;
            nos = s;
            gf = g;
        }

};
int main(){
    Student s1(1,"Hrithik",24,1,"Sharma");
    cout << s1.getGFName() << endl;
    s1.setGFName("Anu");
    cout << s1.getGFName() << endl;

}