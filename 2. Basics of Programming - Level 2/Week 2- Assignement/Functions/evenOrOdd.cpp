#include<iostream>
using namespace std;
bool isEvenOdd(int n){
    if(n % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    bool ans = isEvenOdd(n);
    if(ans == true)
      cout << "Even Number" ;
    else 
      cout << "Odd Number";
}