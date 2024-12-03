#include<iostream>
#include<cmath>
using namespace std;

int binaryToDecimal(int n){
    int sum = 0;
    int i = 0;
    while(n > 0){
        int rem = n % 2;
        sum = sum + rem * pow(2,i++);
        n = n / 10;
    }
    return sum;
}
int main(){
    int n;
    cout << "Enter the binary number: ";
    cin >> n;
    cout << binaryToDecimal(n);
}