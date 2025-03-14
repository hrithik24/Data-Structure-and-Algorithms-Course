#include<iostream>
using namespace std;

// function overloading
int add(int a, int b){
    return a + b;
}

int add(int a,int b,int c){
    return a + b + c;
}

double add(double a,double b){
    return a + b;
}

// operator o  verloading
int main(){
    cout << add(10,4) << endl;
    cout << add(2,3,4) << endl;
    cout << add(3.4,7.8) << endl;
    return 0;
}