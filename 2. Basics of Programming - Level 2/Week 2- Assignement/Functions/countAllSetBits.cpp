#include<iostream>
#include<math.h>
using namespace std;
int countAllSetBits(int n){
    int setBits = 0;
    // Method 1:- Using normal method
    // while(n > 0){
    //     int bit = n % 2;
    //     if(bit == 1){
    //         setBits++;
    //     }
    //     n = n / 2;
    // }

    // Method 2:- Using Bitwise Method
    while(n > 0){
        int bit = n & 1;
        if(bit == 1){
            setBits++;
        }
        n = n >> 1;
    }
    return setBits;
}
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Total number of Set Bits: " << countAllSetBits(n);
}