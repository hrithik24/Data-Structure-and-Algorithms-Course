#include<iostream>
#include<string>
using namespace std;
string removeDuplicates(string s){
   int index = 0;
   string str = "";
   while(index < s.length()){
    if(str.length() > 0 && str[str.length() - 1] == s[index]){
        str.pop_back();
    }
    else{
        str.push_back(s[index]);
    }
    index++;
   }
   return str;
}
int main(){
    string s = "abbaca";
    cout << removeDuplicates(s);
}