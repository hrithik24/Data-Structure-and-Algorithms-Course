#include<iostream>
using namespace std;
int max(int a,int b,int c){
    if(a>b && a>c)
       return a;
    else if(b>c)
       return b;
    else 
       return c;
}
int main(){
    int maximum = max(20,100,90);
    cout << maximum << endl;
}