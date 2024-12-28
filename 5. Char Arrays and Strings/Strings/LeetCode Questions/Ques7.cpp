#include<iostream>
#include<algorithm>
using namespace std;
string str;
bool compare(char ch1,char ch2){
    // this will return true if position of ch1 in str string is less than the position of ch2 in str string.
    // when true is returned, then ch1 will be placed before ch2 in output string.
    return (str.find(ch1) < str.find(ch2));
}
string customSortString(string order,string s){
    str = order;
    sort(s.begin(),s.end(),compare);
    return s;
}
int main(){
    string order = "cba";
    string s = "abcd";
    cout << customSortString(order,s);
}