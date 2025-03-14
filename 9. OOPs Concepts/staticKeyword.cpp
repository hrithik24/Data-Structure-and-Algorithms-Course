#include<iostream>
using namespace std;
class abc{
    public: 
    static int x,y;

    void print(){
        cout << x << " " << y << endl;
    }
};

// static variable initialization
int abc::x = 1;
int abc::y = 2;

int main(){
    abc obj1;
    obj1.print();
    abc obj2;
    obj2.x = 10;
    obj2.y = 20;
    obj1.print();
    obj2.print();

}