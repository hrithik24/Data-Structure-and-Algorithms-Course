#include<iostream>
using namespace std;
void increment(int& n){
    n = n + 1;
    cout << "n: " << n << endl;
}
int main(){
    int n = 5;
    increment(n);
    cout << "n: " << n << endl;
    return 0;
}