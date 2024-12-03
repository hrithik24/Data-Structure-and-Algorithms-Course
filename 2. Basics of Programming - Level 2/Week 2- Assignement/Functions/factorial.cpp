#include<iostream>
using namespace std;
int fact(int n){
    int factorial = 1;
    for(int i=1;i<=n;i++){
        factorial = factorial * i;
    }
    return factorial;
}
int main(){
    int n = 5;
    cout << "Factorial: " << fact(n);
}