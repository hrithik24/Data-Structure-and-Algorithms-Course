#include<iostream>
using namespace std;
int printAllDigitsOfAnInteger(int n){
    while(n > 0){
        int rem = n % 10;
        cout << rem << endl;
        n = n / 10;
    }
}
int main(){
    int n;
    cin >> n;
    printAllDigitsOfAnInteger(n);
}