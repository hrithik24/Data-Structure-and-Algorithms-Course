#include<iostream>
using namespace std;
float kmToMiles(float km){
    float miles = km * 0.6217371;
    return miles;
}
int main(){
    float km;
    cout << "Enter the KM: ";
    cin >> km;
    cout << "KM to Miles: " << kmToMiles(km);
}