#include<iostream>
using namespace std;
int numberUsingDigits(int n){
    int num = 0;
    for(int i=0;i<n;i++){
        cout << "Enter the digits: ";
        int digit;
        cin >> digit;
        num = num * 10 + digit;
    }
    return num;

}
int main(){
    int n;
    cout << "Enter how many digits you need: ";
    cin >> n;
    cout << "Number is: " << numberUsingDigits(n);
}