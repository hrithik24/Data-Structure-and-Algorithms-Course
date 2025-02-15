#include<iostream>
using namespace std;
void reverseStringRecursively(string& str,int i,int j){
    // base case
    if( i >= j){
        return;
    }

    // processing
    swap(str[i],str[j]);

    // recursive call
    reverseStringRecursively(str,i+1,j-1);
}
void reverseString(string str){
    int size = str.size() - 1;
    for(int i=0,j=size;i<j;i++,j--){
        swap(str[i],str[j]);
    }
    cout <<"String reverse using iterative method: " << str << endl;
}
int main(){
    string str = "Hrithik";
    cout << str << endl;
    reverseString(str);
    reverseStringRecursively(str,0,str.size() - 1);
    cout << "String reverse using recursive method: " << str << endl;

}