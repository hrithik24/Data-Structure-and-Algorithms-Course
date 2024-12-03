#include<iostream>
using namespace std;
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        cin >> arr[i];
    }

    // printing the sum of array
    int sum = 0;
    for(int i=0;i<5;i++){
        sum = sum +arr[i];
    }

    cout << "Sum of an array: " << sum;
}