#include<iostream>
#include<cmath>
using namespace std;
// using Division Method
int decimalToBinary(int n){
    int binaryNumber = 0;
    int i = 0;
    while(n > 0){
        int bit = n % 2;
        // cout << bit << endl;
        binaryNumber = bit * pow(10,i++) + binaryNumber;
        n = n/2;
    }
    return binaryNumber;
}

// // Using Bitwise Method
// int decimalToBinary(int n){
//   int binaryNo = 0;
//   int i = 0;
//   while(n > 0){
//     int bit = (n & 1);
//     // cout << bit << endl;
//     binaryNo = bit * pow(10,i++) + binaryNo;
//     n = n >> 1;
//   }
//   return binaryNo;
// }
int main(){
    int n;
    cout << "Enter the number: " ;
    cin >> n;
    int binary =  decimalToBinary(n);
    cout << binary;
}