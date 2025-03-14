#include<iostream>
using namespace std;
int x = 3; // Global variable
void func(){
    int x = 60; // local variable of func()
    cout << x << endl;
    ::x = 13; // changing value of global variable
    cout << ::x << endl;
}
int main(){
    ::x = 5; // changing value of global variable
    int x = 20; // local variable
    cout << x << endl;
    cout << ::x << endl; 
    {
        int x = 500; // local variable
        cout << x << endl;
        cout << ::x << endl;
    }
    func();
}