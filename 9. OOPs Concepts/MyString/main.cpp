#include<iostream>
#include "MyString.h"
using namespace std;

int main(){
    MyString s("Hrithik is best coder");
    cout << s << endl;
    cout << s[4] << endl;
    cout << s.find("best") << endl;
    return 0;
}