#include<iostream>
using namespace std;
int main(){
    int num;
    cin >> num;
    int n = num/2;

    // Upper part
    for(int i=0;i<n;i++){
        //Inverted triangle 1
        for(int j=0;j<n-i;j++){
            cout << "*";
        }
        //full pyramid
        for(int j=0;j<2*i+1;j++){
            cout << " ";
        }
        //Inverted triangle 2
         for(int j=0;j<n-i;j++){
            cout << "*";
        }  
        cout << endl;
    }

    //lower part
    for(int i=0;i<n;i++){
        //first triangle
        for(int j=0;j<i+1;j++){
            cout << "*";
        }
        //inverted full pyramid
        for(int j=0;j<2*n-2*i-1;j++){
            cout << " ";
        }
        //second triangle
        for(int j=0;j<i+1;j++){
            cout << "*";
        }
        cout << endl;
    }

}