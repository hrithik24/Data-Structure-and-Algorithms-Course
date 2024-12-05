#include<iostream>
using namespace std;
int main(){
    // Creation of an Array
    int money[12];
    char alphabet[26];
    bool flags[27];

    // Initialization of an array
    int arr[] = {1,2,3,4,5};
    int brr[5] = {10,20,30,50,34};
    int crr[4] = {2,3};
    // int drr[3] = {2,5,6,7,8}; --> this will give error

    // Array Indexing
    cout << arr[3] << endl;
    cout << arr[0] << endl;

    // Address of Operator
    cout << "Address of a variable: " << &arr << endl;
    cout << "Address of a variable: " << &arr[0] << endl;
    cout << "Address of a variable: " << &arr[3] << endl;

    // Size of Operator 
    cout << "Size of an array: " <<sizeof(arr) << endl;

    // Using loop for accessing whole array
    int n = 5;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Taking input an array
    int arr1[5];
    for(int i=0;i<5;i++){
        cin >> arr1[i];
    }

    for(int i=0;i<5;i++){
        cout << arr1[i] <<endl;
    }
    

}