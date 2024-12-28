#include<iostream>
#include <string.h>
using namespace std;
bool checkPalindrome(char ch[], int size){
    int i = 0;
    int j = size - 1;
    
    while(i <= j){
        if(ch[i] == ch[j]){
            i++;
            j--;
        } 
        else{
            return false;
        }
    }
    return true;
}
int main(){
    char ch[100];
    cin >> ch;
    cout << "Befor: " << ch << endl;
    int length = strlen(ch);
    bool ans = checkPalindrome(ch,length);
    if(ans){
        cout << "Valid Palindrome" << endl;
    }
    else{
        cout << "Not Valid Palindrome" << endl;
    }
}