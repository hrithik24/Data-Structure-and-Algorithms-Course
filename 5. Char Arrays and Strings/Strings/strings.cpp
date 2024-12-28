#include<iostream>
using namespace std;
int main(){
    // creation of string
    string name;
    // input of string
    cin >> name;
    // printing of string
    cout << "Name: " << name << endl; 
    // accessing the string
    cout << name[3] << endl;

    // accessing using loop
    int index = 0;
    while(name[index] != '\0'){
        cout << "Index: " << index << " Character: " << name[index] << endl;
        index++;
    }

    //printing null character ASCII value
    cout << "Printing index 7 value: " << name[7] << endl;
    int value = (int) name[7];
    cout << "Value: " << value << endl;

    // taking input of string with spaces
    // string name;
    // getline(cin,name);
    // cout << "Print the full string: " << name;

}