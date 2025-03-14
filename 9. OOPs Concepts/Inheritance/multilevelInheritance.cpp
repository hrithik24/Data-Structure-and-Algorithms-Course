#include<iostream>
using namespace std;
class Vehicle{
    public:
        Vehicle(){
            cout << "This is Vehicle" << endl;
        }
};
class FourWheeler : public Vehicle{
    public:
        FourWheeler(){
            cout << "This is FourWheeler Vehicle" << endl;
        }
};
class Car : public FourWheeler{
    public:
        Car(){
            cout << "This is Car Vehicle" << endl;
        }
};
int main(){
    Car c1;
    return 0;

}