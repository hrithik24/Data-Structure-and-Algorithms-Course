#include<iostream>
using namespace std;
int main(){
    // creation of character array
    char ch[10];
    // taking input of character array
    cout << "Enter the character array: ";
    cin >> ch;
    // printing the character array
    cout << "Printing the character array: ";
    cout << ch << endl;  
    // accessing the character array
    cout << "Element at index 1: " << ch[1] << endl;
    // accessing character array using loop 
    for(int i=0;i<10;i++){
        cout << "At index: " << i << " " << ch[i] << endl;
    }
    // checking the value of null character
    char temp = ch[7];
    int value = (int) temp;
    cout << "Printing integer value of null character: " << value << endl;

    // printing char array with spaces and tabes
    // char a[100];
    // cin.getline(a,100);
    // cout << "Printing the char array with spaces and tabes: " << a;

}