#include<iostream>
using namespace std;
int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        cin >> arr[i];
    }

    // double-up the array
    for(int i=0;i<10;i++){
        arr[i] = arr[i] * 2;
    }

    // printing the array
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
}