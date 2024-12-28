#include<iostream>
using namespace std;
int main(){
    string name;
    cin >> name;

    // length of string
    cout << "Length of string: " << name.length() << endl;

    // string is empty or not
    cout << "String is empty or not: " << name.empty() << endl;

    // accessing using at
    cout << "Character at Position 1 is: " << name.at(1) << endl;

    // front
    cout << "Front character of string: " << name.front() << endl;

    // back
    cout << "Back character of string: " << name.back() << endl;

    // append 
    string str1 = "hrithik";
    string str2 = "sharma";
    cout << "Before Appending: " << endl;
    cout << str1 << endl;
    cout << str2 << endl;

    str1.append(str2);

    cout << "After Appending: " << endl;
    cout << str1 << endl;
    cout << str2 << endl;

    // erase
    string desc = "This is a car";
    desc.erase(4,3);
    cout << desc << endl;

    // insert
    string n = "Hrithik Sharma";
    string middle = "Kumar ";
    n.insert(8,middle);
    cout << "Printing name: " << n << endl;

    // push_back
    cout <<  n << endl;
    n.push_back('Z');
    cout << "n after push back: " << n << endl;

    // pop_back
    cout << n << endl;
    n.pop_back();
    cout << "n after pop back: " << n << endl;

    // find
    string n1 = "My name is Hrithik Sharma";
    string n2 = "Hrithik";

    if(str1.find(str2) == string::npos){
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found" << endl;
    }
    
    // compare
    string s1 = "Hrithik";
    string s2 = "Hrithik";
    if(s1.compare(s2) == 0){
        cout << "Matching" << endl;
    }
    else{
        cout << "Not Matching" << endl;
    }

    // substring
    string str = "Programming Languages are very easy to learn.";
    cout << str.substr(3,9) << endl;

} 