#include<iostream>
using namespace std;
#define PI 3.1415965
#define MAXX(x,y) (x>y ? x : y)

float circleArea(float r){
    return PI * r * r;
}

float circlePerimeter(float r){
    return 2 * PI * r;
}

void fun(){
    int a = 7;
    int b = 5;
    int c = MAXX(a,b);
    cout << c << endl;
}

int main(){
    cout << circleArea(65.4) << endl;
    cout << circlePerimeter(34.2) << endl;
    fun();
}