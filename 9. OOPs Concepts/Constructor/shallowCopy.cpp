#include<iostream>
using namespace std;
class abc{
    public:
        int x;
        int *y;

        abc(int _x,int _y) : x(_x), y(new int(_y)) {}

        void print(){
            cout << "x: " << x << endl;
            cout << "Pointer y: " << y << endl;
            cout << "Y: " << *y << endl;
        }
};

int main(){
    abc a(1,2);
    cout << "Printing values of a: " << endl;
    a.print(); 

    abc b = a;
    cout << "Printing values of b: " << endl;
    b.print();

    *b.y = 25;
    cout << "Printing values of b: " << endl;
    b.print();

    cout << "Printing values of a: " << endl;
    a.print(); 
}