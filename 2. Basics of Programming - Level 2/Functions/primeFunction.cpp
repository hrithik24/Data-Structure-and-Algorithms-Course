#include<iostream>
using namespace std;
void primeNumber(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout << "Not Prime Number";
            return;
        }
    }
    cout << "Prime Number";
}
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    primeNumber(n);

}