#include<iostream>
using namespace std;
// last occurrence of a character from left to right using recursion and iterative method
void lastOccurrenceRecursiveLTR(string& str,char x,int i,int& ans){
    // base case
    if(i >= str.size()){
        return;
    }
    // processing
    if(str[i] == x){
        ans = i;
    }
    // recursive call
    lastOccurrenceRecursiveLTR(str,x,i+1,ans);
}
void lastOccurrence(string str,char x){
    int index = 0;
    for(int i=0;i<str.size();i++){
        if(str[i] == x){
            index = i;
        }
    }
    cout << index << endl;
}

// last occurrence of character from right to left
void lastOccurrenceRTL(string& str,char x,int i, int& ans1){
    // base case
    if(i < 0){
        return ;
    }

    // processing
    if(str[i] == x){
        ans1 = i;
        return;
    }

    // recursive call
    lastOccurrenceRTL(str,x,i-1,ans1);
}
int main(){
    string str = "abcddgdfh";
    char x = 'd';
    int i = 0;
    int ans = -1;
    lastOccurrence(str,x);
    lastOccurrenceRecursiveLTR(str,x,i,ans);
    cout << ans << endl;
    int ans1 = -1;
    lastOccurrenceRTL(str,x,str.size() - 1,ans1);
    cout << ans << endl;
}