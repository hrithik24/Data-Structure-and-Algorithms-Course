#include<iostream>
using namespace std;
float circle_area(float radius){
    float area = 3.14 * radius * radius;
    return area;
}
int main(){
    float radius = 5.78;
    cout << "Area of Circle: " << circle_area(radius);
}