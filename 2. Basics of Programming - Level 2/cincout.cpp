#include<iostream>
using namespace std;
int main(){
    int a;
    if(cin>>a){
        cout << "Hello1" << endl;
    }
    if(cout<<a<<endl){
        cout << "Hello2" << endl;
    }

    int b = 10;
    int c = ++b * b++;
    cout << c << endl;
}