#include<iostream>
using namespace std;
void xyz(int n);
void abc(int n){
    if(n > 0){
        cout << n << " ";
        xyz(n-1);
    }
}
void xyz(int n){
    if(n > 0){
        cout << n << " ";
        abc(n-1);
    }
}
int main(){
    int x = 4;
    abc(x);
}