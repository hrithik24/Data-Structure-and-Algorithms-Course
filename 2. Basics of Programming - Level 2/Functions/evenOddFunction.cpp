#include<iostream>
using namespace std;
void evenOdd(int n){
    if(n%2==0){
        cout<< "Even Number" << endl;
    }
    else{
        cout << "Odd Number" << endl;
    }
}
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    evenOdd(n);

}