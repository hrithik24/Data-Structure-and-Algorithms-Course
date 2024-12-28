#include<iostream>
using namespace std;
string removeOccurrences(string s, string part){
    while(s.find(part) != string::npos){
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main(){
    string s = "daabcbaabcbc";
    string s1 = "axxxxyyyyb";
    string part = "abc";
    string part1 = "xy";
    cout << "After removing occurrences: " << removeOccurrences(s1,part1);
}