#include<iostream>
using namespace std;
class Vehicle{
    public:
        Vehicle(){
            cout << "This is Vehicle" << endl;
        }
};
class Car : public Vehicle{
    public:
        Car(){
            cout << "This is Car Vehicle" << endl;
        }
};
int main(){
    Car c1;
    return 0;

}